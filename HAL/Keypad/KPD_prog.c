/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 16-Feb-19                                            */
/* Version: 01                                                */
/* Description: Program file for KPD Driver                   */
/**************************************************************/

#include "STD_TYPES.h"
#include "BIT_CALC.h" 
#include "DIO_interface.h"
#include "KPD_interface.h" 
#include "KPD_priv.h" 
#include "KPD_config.h" 

/*
 * Description: Function to return the states of input pins connected to the keypad
 * Inputs: the container variable which will hold the keypad state to represent which button is pressed
 * Output: the error state
 */
u8 KPD_u8GetPressedKeys(u8 (*PAu8KpdState)[KPD_u8_NO_OF_ROWS])
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;
	u8 Local_u8KeySt;

	u8 i,j,k;

	/*checking the error possibilities of the inputs*/
	if (PAu8KpdState == NULL)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		if (KPD_u8_TYPE == KPD_u8_PULL_UP)
		{
			for (i = UNSIGNED_MIN ; i < KPD_u8_NO_OF_COLUMNS ; i++)
			{
				/*firstly Setting all column pins to high to disable any key*/
				for (j = UNSIGNED_MIN ; j < KPD_u8_NO_OF_COLUMNS ; j++)
				{
					Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[j],DIO_u8_PIN_HIGH);
				}

				/*Setting the column you want to check as low as it is a pull up type KPD*/
				Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[i],DIO_u8_PIN_LOW);

				/*Checking the row pins connected to this column*/
				for (k = 0 ; k < KPD_u8_NO_OF_ROWS ; k++)
				{
					Local_u8Error = DIO_u8GetPinValue(KPD_Au8RowsPins[k],&Local_u8KeySt);
					if (Local_u8KeySt == KEY_u8_INPUT_LOW)
					{
						PAu8KpdState[i][k] = KEY_u8_KEY_PRESSED;
					}
					else
					{
						PAu8KpdState[i][k] = KEY_u8_KEY_RELEASED;
					}
				}
			}
		}
		else
		{
			for (i = UNSIGNED_MIN ; i < KPD_u8_NO_OF_COLUMNS ; i++)
			{
				/*firstly Setting all column pins to high to disable any key*/
				for (j = UNSIGNED_MIN ; j < KPD_u8_NO_OF_COLUMNS ; j++)
				{
					Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[j],DIO_u8_PIN_LOW);
				}

				/*Setting the column you want to check as low as it is a pull up type KPD*/
				Local_u8Error = DIO_u8SetPinValue (KPD_Au8ColumnsPins[i],DIO_u8_PIN_HIGH);

				/*Checking the row pins connected to this column*/
				for (k = 0 ; k < KPD_u8_NO_OF_ROWS ; k++)
				{
					Local_u8Error = DIO_u8GetPinValue(KPD_Au8RowsPins[k],&Local_u8KeySt);
					if (Local_u8KeySt == KEY_u8_INPUT_HIGH)
					{
						PAu8KpdState[i][k] = KEY_u8_KEY_PRESSED;
					}
					else
					{
						PAu8KpdState[i][k] = KEY_u8_KEY_RELEASED;
					}
				}
			}
		}
	}

	/*Function return*/
	return Local_u8Error;

}

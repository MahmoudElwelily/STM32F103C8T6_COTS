/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 04-Mar-19                                            */
/* Version: 01                                                */
/* Description: Program file for LCD Driver      	     	  */
/**************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "DELAY_interface.h"
#include "DIO_interface.h"
#include "LCD_interface.h" 
#include "LCD_priv.h" 
#include "LCD_config.h" 

/*
 * Description: Function to run some required commands at first as an initialization
 * Inputs: none
 * Output: void
 */
void LCD_vInit (void)
{
	delay_milliseconds (40);
	LCD_vWriteCommand (LCD_u8_INIT_FUNCTION_SET);
	delay_milliseconds (2);
	LCD_vWriteCommand (LCD_u8_INIT_DISPLAY_CONTROL);
	delay_milliseconds (2);
	LCD_vWriteCommand (LCD_u8_CLEAR);
	delay_milliseconds (2);
}

/*
 * Description: Function needed to send Data to the LCD
 * Inputs: The data needed to be sent Data as a string or a single character
 * Output: Error state
 */

u8 LCD_u8WriteString (u8 *Copy_u8Data,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	u8 Local_u8Address;
	if ((Copy_u8XPos >= 16) || (Copy_u8YPos >= 2) || (Copy_u8Data == NULL))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		Local_u8Address = Copy_u8XPos+(Copy_u8YPos*0x40);
		Local_u8Address |= 0x80;
		LCD_vWriteCommand(Local_u8Address);

			while (*Copy_u8Data != '\0')
			{
				LCD_vWriteData(*Copy_u8Data++);
				Local_u8Address++;

				 /* End of line 1 */
				 if (Local_u8Address == 0x90)
				 {
					 Local_u8Address = 0xC0;
					 LCD_vWriteCommand(Local_u8Address);
				 }

				 /* End of line 2 */
				 if (Local_u8Address == 0xD0)
				 {
					 Local_u8Address = 0x80;
					 LCD_vWriteCommand(Local_u8Address);
				 }
			}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function needed to send Data to the LCD
 * Inputs: The data needed to be sent Data as a string or a single character
 * Output: Error state
 */
static void LCD_vWriteData (u8 Copy_u8Data)
{
	DIO_u8SetPinValue(LCD_u8_RS_PIN,DIO_u8_PIN_HIGH);
	u8Write(Copy_u8Data);
	return;
}


/*
 * Description: Function needed to send Command to the LCD
 * Inputs: The command needed to be sent
 * Output: Error state
 */
static void LCD_vWriteCommand (u8 Copy_u8Command)
{
	DIO_u8SetPinValue (LCD_u8_RS_PIN,DIO_u8_PIN_LOW);
	u8Write (Copy_u8Command);
}

/*
 * Description: Private function needed to send Data/Command to the LCD
 * Inputs: The data or the command needed to be sent
 * Output: Error state
 */
static u8 u8Write (u8 Copy_u8Data)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;

	Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_LOW);
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_RW_PIN,DIO_u8_PIN_LOW);

	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D0_PIN,GET_BIT(Copy_u8Data,0));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D1_PIN,GET_BIT(Copy_u8Data,1));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D2_PIN,GET_BIT(Copy_u8Data,2));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D3_PIN,GET_BIT(Copy_u8Data,3));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D4_PIN,GET_BIT(Copy_u8Data,4));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D5_PIN,GET_BIT(Copy_u8Data,5));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D6_PIN,GET_BIT(Copy_u8Data,6));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D7_PIN,GET_BIT(Copy_u8Data,7));

	Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_HIGH);
	delay_milliseconds (2);
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_LOW);

	/*Function return*/
	return Local_u8Error;
}

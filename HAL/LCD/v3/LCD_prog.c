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
	if (LCD_u8_MODE == LCD_u8_4BIT_MODE)
	{
		LCD_vWriteCommand (0x33);
		LCD_vWriteCommand (0x32);
	}
	LCD_vWriteCommand (LCD_u8_INIT_FUNCTION_SET);
	delay_milliseconds (2);
	LCD_vWriteCommand (LCD_u8_INIT_DISPLAY_CONTROL);
	delay_milliseconds (2);
	LCD_vWriteCommand (LCD_u8_CLEAR);
	delay_milliseconds (2);
}

/*
 * Description: Function needed to send Data to the LCD
 * Inputs: The array of character needed to be displayed and it is required position in x & y axis
 * Output: Error state
 */
u8 LCD_u8WriteString (u8 *Copy_u8Data,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	u8 Local_u8Address;
	if ((Copy_u8XPos >= LCD_u8_COLOMN_NO) || (Copy_u8YPos >= LCD_u8_ROW_NO) || (Copy_u8Data == NULL))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		Local_u8Address = Copy_u8XPos+(Copy_u8YPos*LCD_u8_2ND_ROW);
		Local_u8Address |= LCD_u8_SET_DDRAM_ADDRESS;
		LCD_vWriteCommand(Local_u8Address);

		while (*Copy_u8Data != '\0')
		{
			LCD_vWriteData(*Copy_u8Data++);
			Local_u8Address++;

			/* End of line 1 */
			if (Local_u8Address == LCD_u8_LINE1_END)
			{
				/* Move the cursor to line 2 */
				Local_u8Address = LCD_u8_LINE2_START;
				LCD_vWriteCommand(Local_u8Address);
			}

			/* End of line 2 */
			if (Local_u8Address == LCD_u8_LINE2_END)
			{
				/* Move the cursor to line 1 */
				Local_u8Address = LCD_u8_SET_DDRAM_ADDRESS;
				LCD_vWriteCommand(Local_u8Address);
			}
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function save any word of special letters outside the asci scope
 * Inputs: pointer to the array of 8 patterns needed for each letter of this word and the word size
 * Output: Error state
 */
u8 LCD_u8SaveSpecialWord (u8 Au8_SymbolPattern[][8],u8 Copy_u8WordSize)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	u8 Local_u8Index1,Local_u8Index2;
	if (Copy_u8WordSize > LCD_u8_MAX_SYMBOL)
	{
		Local_u8Error = ERROR_NOK;
	}
	LCD_vWriteCommand(LCD_u8_SET_CGRAM_ADDRESS);

	for (Local_u8Index1 = ZERO ; Local_u8Index1 < Copy_u8WordSize ; Local_u8Index1++)
	{
		for (Local_u8Index2 = ZERO ; Local_u8Index2 < LCD_u8_CHARACTER_SIZE ; Local_u8Index2++)
		{
			LCD_vWriteData(Au8_SymbolPattern[Local_u8Index1][Local_u8Index2]);
		}
	}

	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to write a special word on the LCD
 * Inputs: the symbol index in the CGRAM and its required position on the LCD according to x & y axis
 * Output: Error state
 */
u8 LCD_u8SwriteSpecialSymbol (u8 Copy_u8SymbolIndex,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	u8 Local_u8Address;
	if ((Copy_u8XPos >= LCD_u8_COLOMN_NO) || (Copy_u8YPos >= LCD_u8_ROW_NO))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		Local_u8Address = Copy_u8XPos+(Copy_u8YPos*LCD_u8_2ND_ROW);
		Local_u8Address |= LCD_u8_SET_DDRAM_ADDRESS;
		LCD_vWriteCommand(Local_u8Address);
		LCD_vWriteData(Copy_u8SymbolIndex);
	}
	/*Function return*/
	return Local_u8Error;
}

/*=====================================Common Commands===================*/
/*
 * Description: Function to clear the LCD from any previous displayed data on it.
 * Inputs: none
 * Output: void
 */
void LCD_vCLEAR(void)
{
	LCD_vWriteCommand (LCD_u8_CLEAR);
}

/*
 * Description: Function to shift the display to right
 * Inputs: none
 * Output: void
 */
void LCD_vShiftRight(void)
{
	LCD_vWriteCommand (LCD_u8_SHIFT_RIGHT);
}

/*
 * Description: Function to shift the display to lift
 * Inputs: none
 * Output: void
 */
void LCD_vShiftLift(void)
{
	LCD_vWriteCommand (LCD_u8_SHIFT_LEFT);
}

/*====================Static Functions===============================*/
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

	if (LCD_u8_MODE == LCD_u8_8BIT_MODE)
	{
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D0_PIN,GET_BIT(Copy_u8Data,0));
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D1_PIN,GET_BIT(Copy_u8Data,1));
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D2_PIN,GET_BIT(Copy_u8Data,2));
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D3_PIN,GET_BIT(Copy_u8Data,3));
	}
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D4_PIN,GET_BIT(Copy_u8Data,4));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D5_PIN,GET_BIT(Copy_u8Data,5));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D6_PIN,GET_BIT(Copy_u8Data,6));
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_D7_PIN,GET_BIT(Copy_u8Data,7));

	Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_HIGH);
	delay_milliseconds (2);
	Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_LOW);

	delay_milliseconds (5);
	if (LCD_u8_MODE == LCD_u8_4BIT_MODE)
	{
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_LOW);

		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D4_PIN,GET_BIT(Copy_u8Data,0));
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D5_PIN,GET_BIT(Copy_u8Data,1));
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D6_PIN,GET_BIT(Copy_u8Data,2));
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_D7_PIN,GET_BIT(Copy_u8Data,3));

		Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_HIGH);
		delay_milliseconds (2);
		Local_u8Error = DIO_u8SetPinValue (LCD_u8_E_PIN,DIO_u8_PIN_LOW);
	}
	/*Function return*/
	return Local_u8Error;
}

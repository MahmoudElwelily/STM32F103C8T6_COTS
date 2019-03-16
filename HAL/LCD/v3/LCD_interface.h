/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 04-Mar-19                                        */
/* Version: 01                                            */
/* Description: Interface file for LCD Driver  			  */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef LCD_INTERFACE_H 
#define LCD_INTERFACE_H 

/*
 * Description: Function to run some required commands at first as an initialization
 * Inputs: none
 * Output: void
 */
void LCD_vInit(void);

/*
 * Description: Function to shift the display to right.
 * Inputs: none
 * Output: void
 */
void LCD_vCLEAR(void);

/*
 * Description:  Function to shift the display to lift.
 * Inputs: none
 * Output: void
 */
void LCD_vShiftLeft(void);

/*
 * Description: Function to clear the LCD from any previous displayed data on it.
 * Inputs: none
 * Output: void
 */
void LCD_vShiftRight(void);

/*
 * Description: Function needed to send Data to the LCD
 * Inputs: The array of character needed to be displayed and it is required position on the LCD according to x & y axis
 * Output: Error state
 */
u8 LCD_u8WriteString (u8 *Copy_u8Data,u8 Copy_u8XPos,u8 Copy_u8YPos);

/*
 * Description: Function save any word of special letters outside the asci scope
 * Inputs: pointer to the array of 8 patterns needed for each letter of this word and the word size
 * Output: Error state
 */
u8 LCD_u8SaveSpecialWord (u8 Au8_SymbolPattern[][8],u8 Copy_u8WordSize);

/*
 * Description: Function to write a special word on the LCD
 * Inputs: the symbol index in the CGRAM and its required position on the LCD according to x & y axis
 * Output: Error state
 */
u8 LCD_u8SwriteSpecialSymbol (u8 Copy_u8SymbolIndex,u8 Copy_u8XPos,u8 Copy_u8YPos);

#endif /* LCD_INTERFACE_H */ 

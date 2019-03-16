/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 04-Mar-19                                        */
/* Version: 01                                            */
/* Description: Private file for LCD Driver    			  */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef LCD_PRIV_H 
#define LCD_PRIV_H 

/*
 * Description: Private function needed to send Data/Command to the LCD
 * Inputs: The data or the command needed to be sent
 * Output: Error state
 */
static u8 u8Write (u8 Copy_u8Data);

/*
 * Description: Function needed to send Command to the LCD
 * Inputs: The command needed to be sent
 * Output: Error state
 */
static void LCD_vWriteCommand (u8 Copy_u8Command);
/*
 * Description: Function needed to send Data to the LCD
 * Inputs: The data needed to be sent Data as a string or a single character
 * Output: Error state
 */
static void LCD_vWriteData (u8 Copy_u8Data);

#endif /* LCD_PRIV_H */ 

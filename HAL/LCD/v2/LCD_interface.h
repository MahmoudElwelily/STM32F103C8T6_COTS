/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 04-Mar-19                                        */
/* Version: 01                                            */
/* Description: Interface file for LCD Driver  			  */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef LCD_INTERFACE_H 
#define LCD_INTERFACE_H 

/*Macros for whole needed commands for the LCD */
#define LCD_u8_FUN_SET_8BIT_1LINE        (u8)0x30
#define LCD_u8_FUN_SET_8BIT_2LINES       (u8)0x38
#define LCD_u8_FUN_SET_4BIT_1LINE	 	 (u8)0x20
#define LCD_u8_FUN_SET_4BIT_2LINES	  	 (u8)0x28
#define LCD_u8_CLEAR			         (u8)0x01
#define LCD_u8_ENTRY_MODE				 (u8)0x06
#define LCD_u8_DISPLAY_OFF_CURSOR_OFF	 (u8)0x08
#define LCD_u8_DISPLAY_ON_CURSOR_ON 	 (u8)0x0E
#define LCD_u8_DISPLAY_ON_CURSOR_OFF	 (u8)0x0C
#define LCD_u8_SHIFT_RIGHT				 (u8)0x1C
#define LCD_u8_SHIFT_LEFT				 (u8)0x18

/*
 * Description: Function to run some required commands at first as an initialization
 * Inputs: none
 * Output: void
 */
void LCD_vInit(void);

u8 LCD_u8WriteString (u8 *Copy_u8Data,u8 Copy_u8XPos,u8 Copy_u8YPos);


#endif /* LCD_INTERFACE_H */ 

/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 16-Feb-19                                        */
/* Version: 01                                            */
/* Description: Interface file for KPD Driver   		  */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef KPD_INTERFACE_H 
#define KPD_INTERFACE_H 

/*Macros for determining the number of rows and columns of the used keypad*/
#define KPD_u8_NO_OF_ROWS        (u8)3
#define KPD_u8_NO_OF_COLUMNS     (u8)3

/*Macros for the key states (pressed-released)*/
#define KEY_u8_KEY_PRESSED           					(u8)1
#define KEY_u8_KEY_RELEASED     	     	   	 		(u8)0
/*
 * Description: Function to return the states of input pins connected to the keypad
 * Inputs: the container variable which will hold the keypad state to represent which button is pressed
 * Output: the error state
 */
u8 KPD_u8GetPressedKeys(u8 (*PAu8KpdState)[KPD_u8_NO_OF_ROWS]);

#endif /* KPD_INTERFACE_H */ 

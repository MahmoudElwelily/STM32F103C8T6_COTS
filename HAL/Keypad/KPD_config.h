/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 16-Feb-19                                            */
/* Version: 01                                                */
/* Description: Configuration file for KPD Driver  			  */
/**************************************************************/

/*Preprocessor Guard*/
#ifndef KPD_CONFIG_H 
#define KPD_CONFIG_H 

/*
Macro to determine the type of the keypad
Range:  KPD_u8_PULL_UP
		KPD_u8_PULL_DOWN
*/
#define KPD_u8_TYPE			KPD_u8_PULL_UP

/*Arrays holding the channel pins connected to each rows and column of the keypad*/
u8 KPD_Au8RowsPins[KPD_u8_NO_OF_ROWS] = {DIO_u8_PIN9,DIO_u8_PIN10,DIO_u8_PIN11};
u8 KPD_Au8ColumnsPins[KPD_u8_NO_OF_COLUMNS] = {DIO_u8_PIN12,DIO_u8_PIN13,DIO_u8_PIN14};

#endif /* KPD_CONFIG_H */ 


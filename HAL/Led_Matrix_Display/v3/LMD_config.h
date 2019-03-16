/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: Configuration file for LMD interface                */
/********************************************************************/
/*PreProccessor Guard*/
#ifndef LMD_CONFIG_H_
#define LMD_CONFIG_H_

/*Macro to determine the activation type of the active part of the Led Matrix Display
  whether it is active column or row
  Range:   LMD_u8_ACTIVE_LOW
	   	     LMD_u8_ACTIVE_HIGH
*/
#define LMD_u8_ACTIVE_TYPE   LMD_u8_ACTIVE_LOW

/*Array holding the pins connected to the active port*/
u8 LMD_Au8LmdActPrt[LMD_u8_SIZE] = {DIO_u8_PIN16,DIO_u8_PIN17,DIO_u8_PIN26,DIO_u8_PIN27,
									DIO_u8_PIN25,DIO_u8_PIN24,DIO_u8_PIN23,DIO_u8_PIN22};

/*Array holding the pins connected to the Light port whether it is for the red color or the green color*/                  
u8 LMD_Au8RedPrt[LMD_u8_SIZE] = {DIO_u8_PIN21,DIO_u8_PIN12,DIO_u8_PIN11,DIO_u8_PIN10,
									DIO_u8_PIN31,DIO_u8_PIN30,DIO_u8_PIN29,DIO_u8_PIN28};

/* LMD_Au8GreenPrt[LMD_u8_SIZE] -> if you are connecting the green port */

#endif /* LMD_CONFIG_H_ */

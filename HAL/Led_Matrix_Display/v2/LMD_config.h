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
u8 LMD_Au8LmdActPrt[LMD_u8_SIZE] = {DIO_u8_PIN29,DIO_u8_PIN30,DIO_u8_PIN21,DIO_u8_PIN22,
									DIO_u8_PIN23,DIO_u8_PIN24,DIO_u8_PIN25,DIO_u8_PIN28};

/*Macro to determine the port responsible for displaying the RED color (A-D)
  Range:   DIO_u8_PORT_A
           DIO_u8_PORT_B
           DIO_u8_PORT_C
           DIO_u8_PORT_D
 */
#define LMD_u8_RED_PORT       DIO_u8_PORT_A

/*Macro to determine the port responsible for displaying the GREEN color (A-D)
  Range:   DIO_u8_PORT_A
           DIO_u8_PORT_B
           DIO_u8_PORT_C
           DIO_u8_PORT_D
 */
#define LMD_u8_GREEN_PORT      DIO_u8_PORT_B



#endif /* LMD_CONFIG_H_ */

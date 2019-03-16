/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: Configuration file for LMD interface                */
/********************************************************************/
/*PreProccessor Guard*/
#ifndef LMD_CONFIG_H_
#define LMD_CONFIG_H_

/*Macro for identifying the active part of the Led Matrix Display
  Range:   LMD_u8_ACTIVE_COLUMN
           LMD_u8_ACTIVE_ROW
*/
#define LMD_u8_TYPE  LMD_u8_ACTIVE_COLUMN

/*Macro to determine the activation type of the active part of the Led Matrix Display
  whether it is active column or row
  Range:   LMD_u8_ACTIVE_LOW
	   	   LMD_u8_ACTIVE_HIGH
*/
#define LMD_u8_ACTIVE_TYPE   LMD_u8_ACTIVE_LOW

/*Macro to determine the active port (A-D)
  Range:   DIO_u8_PORT_A
           DIO_u8_PORT_B
           DIO_u8_PORT_C
           DIO_u8_PORT_D
 */
#define LMD_u8_ACTIVE_PORT    DIO_u8_PORT_A


/*Macro to determine the port responsible for displaying the RED color (A-D)
  Range:   DIO_u8_PORT_A
           DIO_u8_PORT_B
           DIO_u8_PORT_C
           DIO_u8_PORT_D
 */
#define LMD_u8_RED_PORT       DIO_u8_PORT_D

/*Macro to determine the port responsible for displaying the GREEN color (A-D)
  Range:   DIO_u8_PORT_A
           DIO_u8_PORT_B
           DIO_u8_PORT_C
           DIO_u8_PORT_D
 */
#define LMD_u8_GREEN_PORT      DIO_u8_PORT_A

#endif /* LMD_CONFIG_H_ */

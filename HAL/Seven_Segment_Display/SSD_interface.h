/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                   								    */
/* Description: Interface file for Seven Segment display            */
/********************************************************************/

/*PreProccessor Guard*/
#ifndef SSD_INTERFACE_
#define SSD_INTERFACE_

/* Macros for numbering SSDs */
#define SSD_u8_1  (u8)0
#define SSD_u8_2  (u8)1
#define SSD_u8_3  (u8)2
#define SSD_u8_4  (u8)3

/*
Macros for the port assignments needed to represent each digit
on the 7 segments display from 0 to 9
*/
#define SSD_u8_ZERO    (u8)0
#define SSD_u8_ONE 	   (u8)1
#define SSD_u8_TWO 	   (u8)2
#define SSD_u8_THREE   (u8)3
#define SSD_u8_FOUR    (u8)4
#define SSD_u8_FIVE    (u8)5
#define SSD_u8_SIX     (u8)6
#define SSD_u8_SEVEN   (u8)7
#define SSD_u8_EIGHT   (u8)8
#define SSD_u8_NINE    (u8)9

/*
 * Description: Function to turn a SSD on
 * Inputs: the SSD number according to the number of SSD specified in the configuration file
 * output: the Error state of the function
*/
u8 SSD_u8_SetOn (u8 Copy_u8SsdNb);

/*
 * Description: Function to turn a SSD off
 * Inputs: the SSD number according to the number of SSD specified in the configuration file
 * output: the Error state of the function
*/
u8 SSD_u8_SetOff (u8 Copy_u8SsdNb);

/*
 * Description: Function to set pins of a SSD to display a certain digit on it
 * Inputs: the SSD number according to the number of SSD specified in the configuration file
 * 		   and the digit needed to be displayed
 * output: the Error state of the function
*/
u8 SSD_u8_SetValue (u8 Copy_u8SsdNb,u8 Copy_u8Digit);

#endif /* SSD_INTERFACE_ */

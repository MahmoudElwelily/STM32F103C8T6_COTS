/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: header file for LED interface                       */
/********************************************************************/
/*PreProccessor Guard*/
#ifndef LED_H_INTERFACE_
#define LED_H_INTERFACE_

/* Initial pins connected all leds							 	 */
/* knowing that the max number of leds can be connected to       */
/* the AVR pins  is 31   										 */
#define LED_u8_NO_0      (u8)0
#define LED_u8_NO_1      (u8)1
#define LED_u8_NO_2      (u8)2
#define LED_u8_NO_3      (u8)3
#define LED_u8_NO_4      (u8)4
#define LED_u8_NO_5      (u8)5
#define LED_u8_NO_6      (u8)6
#define LED_u8_NO_7      (u8)7

#define LED_u8_NO_8      (u8)8
#define LED_u8_NO_9      (u8)9
#define LED_u8_NO_10     (u8)10
#define LED_u8_NO_11     (u8)11
#define LED_u8_NO_12     (u8)12
#define LED_u8_NO_13     (u8)13
#define LED_u8_NO_14     (u8)14
#define LED_u8_NO_15     (u8)15

#define LED_u8_NO_16     (u8)16
#define LED_u8_NO_17     (u8)17
#define LED_u8_NO_18     (u8)18
#define LED_u8_NO_19     (u8)19
#define LED_u8_NO_20     (u8)20
#define LED_u8_NO_21     (u8)21
#define LED_u8_NO_22     (u8)22
#define LED_u8_NO_23     (u8)23

#define LED_u8_NO_24     (u8)24
#define LED_u8_NO_25     (u8)25
#define LED_u8_NO_26     (u8)26
#define LED_u8_NO_27     (u8)27
#define LED_u8_NO_28     (u8)28
#define LED_u8_NO_29     (u8)29
#define LED_u8_NO_30     (u8)30
#define LED_u8_NO_31     (u8)31

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number connected to the led
 * output: the Error state of the function
*/
u8 LED_u8LedOn (u8 Copy_u8LedNb);

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number connected to the led
 * output: the Error state of the function
*/
u8 LED_u8LedOff (u8 Copy_u8LedNb);

#endif /* LED_H_INTERFACE_ */

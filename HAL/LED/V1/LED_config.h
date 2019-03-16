/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: Configuration file for LED interface                */
/********************************************************************/
/*PreProccessor Guard*/
#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

/* Initial pins connected all leds							 	 */
/* knowing that the max number of leds can be connected to       */
/* the AVR pins  is 31   										 */
#define LED0_u8_DIO_CH       DIO_u8_PIN0
#define LED1_u8_DIO_CH       DIO_u8_PIN1
#define LED2_u8_DIO_CH       DIO_u8_PIN2
#define LED3_u8_DIO_CH       DIO_u8_PIN3
#define LED4_u8_DIO_CH       DIO_u8_PIN4
#define LED5_u8_DIO_CH       DIO_u8_PIN5
#define LED6_u8_DIO_CH       DIO_u8_PIN6
#define LED7_u8_DIO_CH       DIO_u8_PIN7

/* Initial direction for pins connected all leds		  */
/* Range: LED_u8_FORWARD 	   	   				          */
/*        LED_u8_REVERSE	 	                          */
#define LED0_u8_TYPE         LED_u8_FORWARD
#define LED1_u8_TYPE         LED_u8_FORWARD
#define LED2_u8_TYPE         LED_u8_FORWARD
#define LED3_u8_TYPE         LED_u8_FORWARD
#define LED4_u8_TYPE         LED_u8_REVERSE
#define LED5_u8_TYPE         LED_u8_REVERSE
#define LED6_u8_TYPE         LED_u8_REVERSE
#define LED7_u8_TYPE         LED_u8_REVERSE

/* the number of leds connected to the controller */
#define LED_u8_NUM_OF_LEDS 8

/*Array collecting the pins connected to each configurated led*/
u8 LED_Au8LedCh[LED_u8_NUM_OF_LEDS] = {LED0_u8_DIO_CH,LED1_u8_DIO_CH,LED2_u8_DIO_CH,LED3_u8_DIO_CH,
		                                       LED4_u8_DIO_CH,LED5_u8_DIO_CH,LED6_u8_DIO_CH,LED7_u8_DIO_CH};

/*Array collecting the connectivity of each led whether it is connected forward (active high) or reverse (active low)*/
u8 LED_Au8LedType[LED_u8_NUM_OF_LEDS] = {LED0_u8_TYPE,LED1_u8_TYPE,LED2_u8_TYPE,LED3_u8_TYPE,
	                                     LED4_u8_TYPE,LED5_u8_TYPE,LED6_u8_TYPE,LED7_u8_TYPE};

#endif /* LED_CONFIG_H_ */

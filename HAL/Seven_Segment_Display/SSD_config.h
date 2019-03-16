/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: Configuration file of Seven segment display         */
/********************************************************************/

/*
SSD Configuration Manual:
--------------------------
1) Determine the number of connected SSD.
2) Determine the connectivity of each SSD with each DIO pin.
3) Determine the type of each pin.
4) Determine the connectivity of the EN pin of each connected SSD with which DIO pin.
5) Determine the initial digit should be displayed on each SSD.
6) Modify the configuration arrays according to the configuration you've made in the upper steps.

Features:
----------
This SSD driver provides the following feature:
A) if you call (set on) in the first time --> SSD will display the initial value
B) if you call (set on) then (set value) then (set off) then (set on) -> SSD will display the last digit
C) if you call (set on) then (set off) then (set value) -> nothing happens it will display the intial value
*/

/* PreProcessor Guard */
#ifndef SSD_CONFIG_H_
#define SSD_CONFIG_H_

/*Macro for determining the number of connected SSDs*/
#define SSD_u8_NO_OF_SSDS  2

/*Macro for segments mapping with DIO pins (for each SSD connected with the controller)*/
#define SSD_u8_SSD0_SEG_A       DIO_u8_PIN0    /*PINA0*/
#define SSD_u8_SSD0_SEG_B		DIO_u8_PIN1    /*PINA1*/
#define SSD_u8_SSD0_SEG_C		DIO_u8_PIN2    /*PINA2*/
#define SSD_u8_SSD0_SEG_D		DIO_u8_PIN3    /*PINA3*/
#define SSD_u8_SSD0_SEG_E		DIO_u8_PIN4    /*PIND4*/
#define SSD_u8_SSD0_SEG_F		DIO_u8_PIN5    /*PIND5*/
#define SSD_u8_SSD0_SEG_G		DIO_u8_PIN6    /*PIND6*/

#define SSD_u8_SSD1_SEG_A       DIO_u8_PIN0
#define SSD_u8_SSD1_SEG_B		DIO_u8_PIN1
#define SSD_u8_SSD1_SEG_C		DIO_u8_PIN2
#define SSD_u8_SSD1_SEG_D		DIO_u8_PIN3
#define SSD_u8_SSD1_SEG_E		DIO_u8_PIN4
#define SSD_u8_SSD1_SEG_F		DIO_u8_PIN5
#define SSD_u8_SSD1_SEG_G		DIO_u8_PIN6

/*Macro for the Enable pin of each configurated SSD*/
#define SSD_u8_SSD0_SEG_EN      DIO_u8_PIN7    /*PINA7*/
#define SSD_u8_SSD1_SEG_EN      DIO_u8_PIN24   /*PIND0*/
/*
 * Macro for determining the type of each connected SSDs
 * Range: SSD_u8_COMMON_CATHODE
 *        SSD_u8_COMMON_ANODE
 */
#define SSD_u8_SSD0_TYPE      SSD_u8_COMMON_CATHODE
#define SSD_u8_SSD1_TYPE      SSD_u8_COMMON_CATHODE

/*
Macro for the initial digit should be displayed on the initial condition on calling SSD_SetOn.
It is determined for each SSD connected with the controller
Range: SSD_u8_ZERO
       SSD_u8_ONE
       SSD_u8_TWO
       SSD_u8_THREE
       SSD_u8_FOUR
       SSD_u8_FIVE
       SSD_u8_SIX
       SSD_u8_SEVEN
       SSD_u8_EIGHT
       SSD_u8_NINE
*/
#define SSD_u8_SSD0_INIT_DIGIT    SSD_u8_ZERO
#define SSD_u8_SSD1_INIT_DIGIT    SSD_u8_NINE

/* Configuration Arrays */
/************************/
/*Array collecting the pins connected to each configurated SSD*/
u8 SSD_Au8SsdsPinConnected[SSD_u8_NO_OF_SSDS][SSD_u8_NO_OF_SEG] = {
																	/*Pins connected to SSD0*/
																	{ DIO_u8_PIN0,DIO_u8_PIN1,DIO_u8_PIN2,DIO_u8_PIN3,
																			DIO_u8_PIN4,DIO_u8_PIN5,DIO_u8_PIN6
																	},
																	{ DIO_u8_PIN0,DIO_u8_PIN1,DIO_u8_PIN2,DIO_u8_PIN3,
																			DIO_u8_PIN4,DIO_u8_PIN5,DIO_u8_PIN6
																	}
																   };

/*Array holding the enable pin for each configurated SSD*/
u8 SSD_Au8SsdsEnPin[SSD_u8_NO_OF_SSDS] = {SSD_u8_SSD0_SEG_EN,SSD_u8_SSD1_SEG_EN};

/*Array holding the type of each configurated SSD*/
u8 SSD_Au8SsdsTypes[SSD_u8_NO_OF_SSDS] = {SSD_u8_SSD0_TYPE,SSD_u8_SSD1_TYPE};

/*Array holding the initial digit to be displayed on each configurated SSD*/
u8 SSD_Au8SsdsInitDigit[SSD_u8_NO_OF_SSDS] = {SSD_u8_SSD0_INIT_DIGIT,SSD_u8_SSD1_INIT_DIGIT};

#endif /* SSD_CONFIG_H_ */

/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 28-Mar-19                                            */
/* Version: 01                                                */
/* Description: Configuration file for DAC Driver             */
/**************************************************************/

/*Preprocessor Guard*/
#ifndef DAC_CONFIG_H 
#define DAC_CONFIG_H 

/*Macro to define the number of bits needed to represent the analog signal
Note: if resolution increases -> accuracy increases*/
#define DAC_u8_RESOLUTION     (u8)8

/*Macro to define the max possible voltage can be generated from the digital pin*/
#define DAC_u8_MAX_VOLTAGE    (u8)5

/*Array holding the pins connected to DAC circuit*/
u8 DAC_Au8ConnectedPins[DAC_u8_RESOLUTION] = {DIO_u8_PIN24,DIO_u8_PIN25,DIO_u8_PIN26,DIO_u8_PIN27,
											  DIO_u8_PIN28,DIO_u8_PIN29,DIO_u8_PIN30,DIO_u8_PIN31};

#endif /* DAC_CONFIG_H */ 


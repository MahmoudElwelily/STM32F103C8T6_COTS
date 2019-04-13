/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 16-Mar-19                                            */
/* Version: 01                                                */
/* Description: Configuration file for Stepper Motor Driver   */
/**************************************************************/

/*Preprocessor Guard*/
#ifndef STPM_CONFIG_H 
#define STPM_CONFIG_H 

#define STMP_NO_OF_STPM    1

typedef struct
{
	u8 YellowPin;
	u8 OrangePin;
	u8 BluePin;
	u8 PinkPin;
	u8 ActivationType;
	/* According to the connection of the common wire whether it is connected to the VCC or the ground */
	u8 CoilNumber;
}STPM_Struct;


STPM_Struct STPM_AStpmArray[STMP_NO_OF_STPM]={{DIO_u8_PIN0,DIO_u8_PIN1,DIO_u8_PIN2,DIO_u8_PIN3,STPM_u8_ACTIVE_LOW,64}};

#endif /* STPM_CONFIG_H */ 


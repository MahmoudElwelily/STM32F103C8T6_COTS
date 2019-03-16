/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 12-Mar-19                                            */
/* Version: 01                                                */
/* Description: Configuration file for DC motor Driver        */
/**************************************************************/

/*Preprocessor Guard*/
#ifndef DCM_CONFIG_H 
#define DCM_CONFIG_H 

/*Macro to determine the number of connected DC motors*/
#define DCM_NO_OF_MOTORS    1

/*Macro to determine the pins connected to the 2 terminal of each DC motor */
#define DCM_u8_DCM0_POS_TER   DIO_u8_PIN0
#define DCM_u8_DCM0_NEG_TER   DIO_u8_PIN1

/* Configuration Arrays */
/************************/
/*Array collecting the pins connected to each DC motor*/
u8 DCM_Au8PinConnected[DCM_NO_OF_MOTORS][DCM_u8_NO_OF_TERMINALS] = {{DIO_u8_PIN0,DIO_u8_PIN1}};

/*
Array holding the activation type of each motor (Active high/Active low)
according to the motor connection with the controller
Ranges: DCM_u8_ACTIVE_HIGH
		DCM_u8_ACTIVE_LOW
*/
u8 DCM_Au8MotorsType[DCM_NO_OF_MOTORS] = {DCM_u8_ACTIVE_HIGH};

/*
Array holding the initial state of each motor (Enable/Disable)
Ranges: DCM_u8_ENABLE
	    DCM_u8_DISABLE
*/
u8 DCM_Au8InitState[DCM_NO_OF_MOTORS] = {DCM_u8_DISABLE};


/*
Array holding the initial direction of each motor (Right/Left)
Ranges: DCM_u8_PRIV_CW
	    DCM_u8_PRIV_CCW
*/
u8 DCM_Au8InitDir[DCM_NO_OF_MOTORS] = {DCM_u8_PRIV_CW};

#endif /* DCM_CONFIG_H */ 


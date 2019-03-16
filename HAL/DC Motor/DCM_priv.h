/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 12-Mar-19                                        */
/* Version: 01                                            */
/* Description: Private file for DCM Driver               */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef DCM_PRIV_H 
#define DCM_PRIV_H 

/*Macro to determine the activation type of the DC motor*/
#define DCM_u8_ACTIVE_LOW    (u8)0
#define DCM_u8_ACTIVE_HIGH   (u8)1

/*Macro to define the initial state of the DC motor*/
#define DCM_u8_DISABLE    (u8)0
#define DCM_u8_ENABLE     (u8)1

/*Macro to define the initial direction of the DC motor*/
#define DCM_u8_PRIV_CCW   (u8)0
#define DCM_u8_PRIV_CW    (u8)1

/*Macro to define the number of the terminal of the DC motor*/
#define DCM_u8_NO_OF_TERMINALS (u8)2

/*Macro for identifying the SetOff flag*/
#define DCM_u8_SET_OFF_FLAG_OFF (u8)0
#define DCM_u8_SET_OFF_FLAG_ON (u8)1


#endif /* DCM_PRIV_H */ 

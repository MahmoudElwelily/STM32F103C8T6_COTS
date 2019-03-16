/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 12-Mar-19                                        */
/* Version: 01                                            */
/* Description: Interface file for DC Motor Driver        */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef DCM_INTERFACE_H 
#define DCM_INTERFACE_H 

/*Macros to define the possible direction of the DC motor*/
#define DCM_u8_CW          (u8)1
#define DCM_u8_CCW         (u8)0

/*
 * Description: Function to set the initial state and direction of each connected DC motor
 * Inputs: none
 * Output: void
 */
void DCM_vInit (void);

/*
 * Description: Function to enable the assigned DC motor
 * Inputs: The motor ID
 * Output: Error state
 */
u8 DCM_u8MotorOn (u8 Copy_u8MotorId);

/*
 * Description: Function to disable the assigned DC motor
 * Inputs: The motor ID
 * Output: Error state
 */
u8 DCM_u8MotorOff (u8 Copy_u8MotorId);

/*
 * Description: Function to rotate the assigned DC motor according to the required direction (CW/CCW)
 * Inputs: The motor ID and the possible direction of the motor (CW/CCW)
 * Output: Error state
 */
u8 DCM_u8Rotate (u8 Copy_u8MotorId,u8 Copy_u8Direction);

#endif /* DCM_INTERFACE_H */ 

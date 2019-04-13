/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 16-Mar-19                                        */
/* Version: 01                                            */
/* Description: Interface file for Stepper Motor Driver   */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef STPM_INTERFACE_H 
#define STPM_INTERFACE_H 

#define STPM_u8_CW     (u8)1
#define STPM_u8_CCW    (u8)0

/*
 * Description: Function to set the initial angle of each connected stepper motor
 * Inputs: none
 * Output: void
 */
void STPM_vInit (void);

u8 STPM_u8Rotate (u8 Copy_u8StepperId,u8 Copy_u8Angle,u8 Copy_u8Direction,u8 Copy_u8StepDelay);

u8 STPM_u8Step (u8 Copy_u8StepperId,u8 Copy_u8StepNo,u8 Copy_u8Direction,u8 Copy_u8StepDelay);
#endif /* STPM_INTERFACE_H */ 

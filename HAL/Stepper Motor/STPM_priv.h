/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 16-Mar-19                                        */
/* Version: 01                                            */
/* Description: Private file for Stepper Motor Driver     */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef STPM_PRIV_H 
#define STPM_PRIV_H 

#define STPM_u8_ACTIVE_LOW    (u8)0
#define STPM_u8_ACTIVE_HIGH   (u8)1

#define STPM_360_ANGLE  360

static void STPM_vSetActiveLowSequence (u8 Copy_u8StepperNo,u8 Copy_u8Direction,u8 Copy_u8StepTime);
static void STPM_vSetActiveHighSequence (u8 Copy_u8StepperNo,u8 Copy_u8Direction,u8 Copy_u8StepTime);
#endif /* STPM_PRIV_H */ 

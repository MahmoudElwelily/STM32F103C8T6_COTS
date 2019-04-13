/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 16-Mar-19                                            */
/* Version: 01                                                */
/* Description: Program file for Stepper Motor Driver         */
/**************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "DELAY_interface.h"
#include "DIO_interface.h"
#include "STPM_interface.h" 
#include "STPM_priv.h" 
#include "STPM_config.h" 


/*
 * Description: Function to set the initial angle of each connected stepper motor
 * Inputs: none
 * Output: void
 */
void STPM_vInit (void)
{

}

u8 STPM_u8Rotate (u8 Copy_u8StepperId,u8 Copy_u8Angle,u8 Copy_u8Direction,u8 Copy_u8StepDelay)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;

	/*Local variable holding the number of steps of the assigned Stepper motor according to its number of coil*/
	u8 Local_u8NoOfSteps = ((Copy_u8Angle*STPM_AStpmArray[Copy_u8StepperId].CoilNumber)/STPM_360_ANGLE);
	u8 Local_u8Index;

	if (Copy_u8StepperId >= STMP_NO_OF_STPM)
		 Local_u8Error = ERROR_NOK;
	else
	{
		if (STPM_AStpmArray[Copy_u8StepperId].ActivationType == STPM_u8_ACTIVE_LOW)
		{
			for (Local_u8Index = 0 ; Local_u8Index < Local_u8NoOfSteps ; Local_u8Index++)
			{
				STPM_vSetActiveLowSequence (Copy_u8StepperId,Copy_u8Direction,Copy_u8StepDelay);
			}
		}
		else
		{
			for (Local_u8Index = 0 ; Local_u8Index < Local_u8NoOfSteps ; Local_u8Index++)
			{
				STPM_vSetActiveHighSequence (Copy_u8StepperId,Copy_u8Direction,Copy_u8StepDelay);
			}
		}
	}
	/*Function return*/
	return Local_u8Error;
}

u8 STPM_u8Step (u8 Copy_u8StepperId,u8 Copy_u8StepNo,u8 Copy_u8Direction,u8 Copy_u8StepDelay)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;

	u8 Local_u8Index;

	if (Copy_u8StepperId >= STMP_NO_OF_STPM)
		 Local_u8Error = ERROR_NOK;
	else
	{
		if (STPM_AStpmArray[Copy_u8StepperId].ActivationType == STPM_u8_ACTIVE_LOW)
		{
			for (Local_u8Index = 0 ; Local_u8Index < Copy_u8StepNo ; Local_u8Index++)
			{
				STPM_vSetActiveLowSequence (Copy_u8StepperId,Copy_u8Direction,Copy_u8StepDelay);
			}
		}
		else
		{
			for (Local_u8Index = 0 ; Local_u8Index < Copy_u8StepNo ; Local_u8Index++)
			{
				STPM_vSetActiveHighSequence (Copy_u8StepperId,Copy_u8Direction,Copy_u8StepDelay);
			}
		}
	}
	/*Function return*/
	return Local_u8Error;
}

static void STPM_vSetActiveLowSequence (u8 Copy_u8StepperNo,u8 Copy_u8Direction,u8 Copy_u8StepTime)
{
	/*if the required direction is CW */
	if (Copy_u8Direction == STPM_u8_CW)
	{
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
	}
	/*if the required direction is CCW */
	else
	{
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
	}
}


static void STPM_vSetActiveHighSequence (u8 Copy_u8StepperNo,u8 Copy_u8Direction,u8 Copy_u8StepTime)
{
	/*if the required direction is CW */
	if (Copy_u8Direction == STPM_u8_CW)
	{
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
	}
	/*if the required direction is CCW */
	else
	{
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_LOW);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].YellowPin,DIO_u8_PIN_LOW);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].OrangePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].BluePin,DIO_u8_PIN_HIGH);
		DIO_u8SetPinValue (STPM_AStpmArray[Copy_u8StepperNo].PinkPin,DIO_u8_PIN_HIGH);
		delay_milliseconds(Copy_u8StepTime);
	}
}


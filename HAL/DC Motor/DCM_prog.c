/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 12-Mar-19                                            */
/* Version: 01                                                */
/* Description: Program file for DCM Driver                   */
/**************************************************************/

#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "DIO_interface.h"
#include "DCM_interface.h" 
#include "DCM_priv.h" 
#include "DCM_config.h" 

/*Static array holding the last direction of the motor*/
static u8 DCM_u8LastDir[DCM_NO_OF_MOTORS] = {ZERO};

/*Static array holding the off flag according to the special case of each motor*/
static u8 DCM_u8OffFlag[DCM_NO_OF_MOTORS] = {DCM_u8_SET_OFF_FLAG_OFF};

/*
 * Description: Function to set the initial state and direction of each connected DC motor
 * Inputs: none
 * Output: void
 */
void DCM_vInit (void)
{
	u8 Local_u8Index;

	for (Local_u8Index = 0; Local_u8Index < DCM_NO_OF_MOTORS; Local_u8Index++)
	{
		if (DCM_Au8InitState[Local_u8Index] == DCM_u8_DISABLE)
		{
			switch (DCM_Au8MotorsType[Local_u8Index])
			{
				case DCM_u8_ACTIVE_HIGH:
				{
					DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][0],DIO_u8_PIN_LOW);
					DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][1],DIO_u8_PIN_LOW);
					break;
				}
				case DCM_u8_ACTIVE_LOW:
				{
					DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][0],DIO_u8_PIN_HIGH);
					DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][1],DIO_u8_PIN_HIGH);
					break;
				}
			}
		}
		else
		{
			/* if the initial direction is clockwise*/
			if (DCM_Au8InitDir[Local_u8Index] == DCM_u8_PRIV_CW)
			{
				switch (DCM_Au8MotorsType[Local_u8Index])
				{
					case DCM_u8_ACTIVE_HIGH:
					{
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][0],DIO_u8_PIN_LOW);
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][1],DIO_u8_PIN_HIGH);
						break;
					}
					case DCM_u8_ACTIVE_LOW:
					{
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][0],DIO_u8_PIN_HIGH);
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][1],DIO_u8_PIN_LOW);
						break;
					}
				}
				DCM_u8LastDir[Local_u8Index] = DCM_u8_PRIV_CW;
			}
			/* if the initial direction is counter-clockwise*/
			else
			{
				switch (DCM_Au8MotorsType[Local_u8Index])
				{
					case DCM_u8_ACTIVE_HIGH:
					{
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][0],DIO_u8_PIN_HIGH);
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][1],DIO_u8_PIN_LOW);
						break;
					}
					case DCM_u8_ACTIVE_LOW:
					{
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][0],DIO_u8_PIN_LOW);
						DIO_u8SetPinValue (DCM_Au8PinConnected[Local_u8Index][1],DIO_u8_PIN_HIGH);
						break;
					}
				}
				DCM_u8LastDir[Local_u8Index] = DCM_u8_PRIV_CCW;
			}
		}
	}
}

/*
 * Description: Function to enable the assigned DC motor
 * Inputs: The motor ID
 * Output: Error state
 */
u8 DCM_u8MotorOn (u8 Copy_u8MotorId)
{
	/*Local Variable holding the error state*/
    u8 Local_u8Error = ERROR_OK;

    if (Copy_u8MotorId >= DCM_NO_OF_MOTORS)
    {
    	Local_u8Error = ERROR_NOK;
    }
    else
    {
    	DCM_u8OffFlag[Copy_u8MotorId] = DCM_u8_SET_OFF_FLAG_ON;
		/* if the initial direction is clockwise*/
		if (DCM_u8LastDir[Copy_u8MotorId] == DCM_u8_PRIV_CW)
		{
			switch (DCM_Au8MotorsType[Copy_u8MotorId])
			{
				case DCM_u8_ACTIVE_HIGH:
				{
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_LOW);
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_HIGH);
					break;
				}
				case DCM_u8_ACTIVE_LOW:
				{
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_HIGH);
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_LOW);
					break;
				}
			}
		}
		/* if the initial direction is counter-clockwise*/
		else
		{
			switch (DCM_Au8MotorsType[Copy_u8MotorId])
			{
				case DCM_u8_ACTIVE_HIGH:
				{
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_HIGH);
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_LOW);
					break;
				}
				case DCM_u8_ACTIVE_LOW:
				{
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_LOW);
					DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_HIGH);
					break;
				}
			}
		}
    }
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to disable the assigned DC motor
 * Inputs: The motor ID
 * Output: Error state
 */
u8 DCM_u8MotorOff (u8 Copy_u8MotorId)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
    if (Copy_u8MotorId >= DCM_NO_OF_MOTORS)
    {
    	Local_u8Error = ERROR_NOK;
    }
    else
    {
    	DCM_u8OffFlag[Copy_u8MotorId] = DCM_u8_SET_OFF_FLAG_ON;
		switch (DCM_Au8MotorsType[Copy_u8MotorId])
		{
			case DCM_u8_ACTIVE_HIGH:
			{
				Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_LOW);
				Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_LOW);
				break;
			}
			case DCM_u8_ACTIVE_LOW:
			{
				Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_HIGH);
				Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_HIGH);
				break;
			}
		}
    }
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to rotate the assigned DC motor according to the required direction (CW/CCW)
 * Inputs: The motor ID and the possible direction of the motor (CW/CCW)
 * Output: Error state
 */
u8 DCM_u8Rotate (u8 Copy_u8MotorId,u8 Copy_u8Direction)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
    if (Copy_u8MotorId >= DCM_NO_OF_MOTORS)
    {
    	Local_u8Error = ERROR_NOK;
    }
    else
    {
    	if (DCM_u8OffFlag[Copy_u8MotorId] == DCM_u8_SET_OFF_FLAG_OFF)
    	{
			DCM_u8LastDir[Copy_u8MotorId] = Copy_u8Direction;
			/* if the required direction is clockwise*/
			if (Copy_u8Direction == DCM_u8_CW)
			{
				switch (DCM_Au8MotorsType[Copy_u8MotorId])
				{
					case DCM_u8_ACTIVE_HIGH:
					{
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_LOW);
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_HIGH);
						break;
					}
					case DCM_u8_ACTIVE_LOW:
					{
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_HIGH);
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_LOW);
						break;
					}
				}
			}
			/* if the required direction is counter-clockwise*/
			else
			{
				switch (DCM_Au8MotorsType[Copy_u8MotorId])
				{
					case DCM_u8_ACTIVE_HIGH:
					{
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_HIGH);
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_LOW);
						break;
					}
					case DCM_u8_ACTIVE_LOW:
					{
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][0],DIO_u8_PIN_LOW);
						Local_u8Error = DIO_u8SetPinValue (DCM_Au8PinConnected[Copy_u8MotorId][1],DIO_u8_PIN_HIGH);
						break;
					}
				}
			}
    	}
    }
	/*Function return*/
	return Local_u8Error;
}

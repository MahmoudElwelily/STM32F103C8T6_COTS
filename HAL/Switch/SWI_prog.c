/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Program file for Switch driver							        */
/*                                                                  */
/*                                                                  */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "SWI_interface.h"
#include "SWI_priv.h"
#include "SWI_config.h"

/*
 * Description: Function to get the state of switch whether it is released or pressed
 * Inputs: the switch ID according to the config file and the container variable which will hold the state of this switch
 * Output: the Error state of the function
 */
u8 SWI_u8GetSwitchState (u8 Copy_u8SwitchNb, u8 *Copy_u8SwitchState)
{
	/*Local Variables*/
	u8 Local_u8Error;
	u8 Local_u8SwiSt;

	if ((Copy_u8SwitchNb >= SWI_u8_NO_OF_SWI) || (Copy_u8SwitchState == NULL))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		Local_u8Error = DIO_u8GetPinValue(SWI_Au8SwCh[Copy_u8SwitchNb],&Local_u8SwiSt);
		switch (SWI_Au8SwSt[Copy_u8SwitchNb])
		{
		/* in case the SWI is connected with pull-up resistor */
		case (SWI_u8_PULL_UP):
				{
			if (Local_u8SwiSt == SWI_u8_INPUT_HIGH)
				*Copy_u8SwitchState = SWI_u8_RELEASED;  /* Released */
			else
				*Copy_u8SwitchState = SWI_u8_PRESSED;   /* Pressed */
			break;
				}
		/* in case the SWI is connected with pull-down resistor */
		case (SWI_u8_PULL_DOWN):
				{
			if (Local_u8SwiSt == SWI_u8_INPUT_LOW)
				*Copy_u8SwitchState = SWI_u8_RELEASED;   /* Released */
			else
				*Copy_u8SwitchState = SWI_u8_PRESSED;    /* Pressed */
			break;
				}
		}
	}
	/*Function return*/
	return Local_u8Error;
}

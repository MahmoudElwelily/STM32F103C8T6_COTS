/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_priv.h"
#include "LED_config.h"

/*
 * Description: Function to turn led on on a certain pin connected to it
 * Inputs: the led number
 * output: the Error state of the function
*/
u8 LED_u8LedOn (u8 Copy_u8LedNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

    /* Checking if the passed number of led is within the leds number determined in the config file */
	if (Copy_u8LedNb < LED_u8_NUM_OF_LEDS)
    {
		/* Checking if the led corresponding to the passed number is forward or reverse */
	    if (LED_Au8LedType[Copy_u8LedNb] == LED_u8_FORWARD)
	    {
	    	Local_u8Error = DIO_u8SetPinValue (LED_Au8LedCh[Copy_u8LedNb],DIO_u8_PIN_HIGH);
	    }
	    else
	    {
	    	Local_u8Error = DIO_u8SetPinValue (LED_Au8LedCh[Copy_u8LedNb],DIO_u8_PIN_LOW);
	    }
    }
	else
	{
		Local_u8Error = ERROR_NOK;
	}

	/* Function return */
	return Local_u8Error;
}

/*
 * Description: Function to turn led off on a certain pin connected to it
 * Inputs: the led number
 * output: the Error state of the function
*/
u8 LED_u8LedOff (u8 Copy_u8LedNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

    /* Checking if the passed number of led is within the leds number determined in the config file */
	if (Copy_u8LedNb < LED_u8_NUM_OF_LEDS)
    {
		/* Checking if the led corresponding to the passed number is forward or reverse */
	    if (LED_Au8LedType[Copy_u8LedNb] == LED_u8_FORWARD)
	    {
	    	Local_u8Error = DIO_u8SetPinValue (LED_Au8LedCh[Copy_u8LedNb],DIO_u8_PIN_LOW);
	    }
	    else
	    {
	    	Local_u8Error = DIO_u8SetPinValue (LED_Au8LedCh[Copy_u8LedNb],DIO_u8_PIN_HIGH);
	    }
    }
	else
	{
		Local_u8Error = ERROR_NOK;
	}

	/* Function return */
	return Local_u8Error;
}

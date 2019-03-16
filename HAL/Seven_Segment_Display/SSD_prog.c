/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                   								    */
/* Description: Program file for Seven Segment display              */
/********************************************************************/
#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "SSD_interface.h"
#include "SSD_priv.h"
#include "SSD_config.h"

static u8 SSD_Au8INIT_FLAG[SSD_u8_NO_OF_SSDS] =  {SSD_u8_SSD_INIT_FLAG_ZERO};
static u8 SSD_u8LastDigit[SSD_u8_NO_OF_SSDS]  =  {SSD_u8_SSD_LAST_DIG_INIT_VAL};
static u8 SSD_u8OffFlag[SSD_u8_NO_OF_SSDS]    =  {SSD_u8_SSD_SET_OFF_FLAG_OFF};
/*
 * Description: Function to turn a SSD on
 * Inputs: the SSD number according to the number of SSD specified in the configuration file
 * output: the Error state of the function
*/
u8 SSD_u8_SetOn (u8 Copy_u8SsdNb)
{

	/*Local Variable holding the error state*/
	u8 Local_u8Error;
	SSD_u8OffFlag[Copy_u8SsdNb] = SSD_u8_SSD_SET_OFF_FLAG_OFF;

	if (Copy_u8SsdNb >= SSD_u8_NO_OF_SSDS)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/*Checking whether the passed SSD number is related to Common Cathode SSD*/
		if (SSD_Au8SsdsTypes[Copy_u8SsdNb] == SSD_u8_COMMON_CATHODE)
		{
			if (SSD_Au8INIT_FLAG[Copy_u8SsdNb] == SSD_u8_SSD_INIT_FLAG_ZERO)
			{
			  /*handling the enable pin according to the cathode SSD */
			  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_LOW);
			  for (u8 i = SSD_u8_INIT_ITER ; i < SSD_u8_NO_OF_SEG; i++)
			  {
				  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsPinConnected[Copy_u8SsdNb][i],SSD_Au8SEG_PATTERN_CATHODE[SSD_Au8SsdsInitDigit[Copy_u8SsdNb]][i]);
			  }
			}
			else
			{
			  /*handling the enable pin according to the cathode SSD */
				Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_LOW);
			  for (u8 i = SSD_u8_INIT_ITER ; i < SSD_u8_NO_OF_SEG; i++)
			  {
				  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsPinConnected[Copy_u8SsdNb][i],SSD_Au8SEG_PATTERN_CATHODE[SSD_u8LastDigit[Copy_u8SsdNb]][i]);
			  }
			}
		}
		else
		{	/*If the SSD is Common anode*/
			if (SSD_Au8INIT_FLAG[Copy_u8SsdNb] == SSD_u8_SSD_INIT_FLAG_ZERO)
			{
			  /*handling the enable pin according to the anode SSD */
			  DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_HIGH);
			  for (u8 i = SSD_u8_INIT_ITER ; i < SSD_u8_NO_OF_SEG; i++)
			  {
				  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsPinConnected[Copy_u8SsdNb][i],SSD_Au8SEG_PATTERN_ANODE[SSD_Au8SsdsInitDigit[Copy_u8SsdNb]][i]);
			  }
			}
			else
			{
			  /*handling the enable pin according to the anode SSD */
			  DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_HIGH);
			  for (u8 i = SSD_u8_INIT_ITER ; i < SSD_u8_NO_OF_SEG; i++)
			  {
				  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsPinConnected[Copy_u8SsdNb][i],SSD_Au8SEG_PATTERN_ANODE[SSD_u8LastDigit[Copy_u8SsdNb]][i]);
			  }
			}
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to turn a SSD off
 * Inputs: the SSD number according to the number of SSD specified in the configuration file
 * output: the Error state of the function
*/
u8 SSD_u8_SetOff (u8 Copy_u8SsdNb)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;
	SSD_u8OffFlag[Copy_u8SsdNb] = SSD_u8_SSD_SET_OFF_FLAG_ON;

	if (Copy_u8SsdNb >= SSD_u8_NO_OF_SSDS)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/*Checking whether the passed SSD number is related to Common Cathode SSD*/
		if (SSD_Au8SsdsTypes[Copy_u8SsdNb] == SSD_u8_COMMON_CATHODE)
		{
			  /*handling the enable pin according to the cathode SSD */
			  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_HIGH);
		}
		else
		{
			  /*handling the enable pin according to the anode SSD */
			  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_LOW);
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set pins of a SSD to display a certain digit on it
 * Inputs: the SSD number according to the number of SSD specified in the configuration file
 * 		   and the digit needed to be displayed
 * output: the Error state of the function
*/
u8 SSD_u8_SetValue (u8 Copy_u8SsdNb,u8 Copy_u8Digit)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	if ((Copy_u8SsdNb >= SSD_u8_NO_OF_SSDS) || (Copy_u8Digit > SSD_u8_MAX_DIGIT_FOR_SSD))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		if (SSD_u8OffFlag[Copy_u8SsdNb] == SSD_u8_SSD_SET_OFF_FLAG_OFF)
		{
			SSD_Au8INIT_FLAG[Copy_u8SsdNb] = SSD_u8_SSD_INIT_FLAG_ONE;
			SSD_u8LastDigit[Copy_u8SsdNb] = Copy_u8Digit;

			/*Checking whether the passed SSD number is related to Common Cathode SSD*/
			if (SSD_Au8SsdsTypes[Copy_u8SsdNb] == SSD_u8_COMMON_CATHODE)
			{
				  /*handling the enable pin according to the cathode SSD */
				  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_LOW);
				  for (u8 i = SSD_u8_INIT_ITER ; i < SSD_u8_NO_OF_SEG; i++)
				  {
					  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsPinConnected[Copy_u8SsdNb][i],SSD_Au8SEG_PATTERN_CATHODE[Copy_u8Digit][i]);
				  }
			}
			else
			{
				  /*handling the enable pin according to the anode SSD */
				  DIO_u8SetPinValue(SSD_Au8SsdsEnPin[Copy_u8SsdNb],DIO_u8_PIN_HIGH);
				  for (u8 i = SSD_u8_INIT_ITER ; i < SSD_u8_NO_OF_SEG; i++)
				  {
					  Local_u8Error = DIO_u8SetPinValue(SSD_Au8SsdsPinConnected[Copy_u8SsdNb][i],SSD_Au8SEG_PATTERN_ANODE[Copy_u8Digit][i]);
				  }
			}
		}
		else
			Local_u8Error = ERROR_OK;
	}
	/*Function return*/
	return Local_u8Error;
}

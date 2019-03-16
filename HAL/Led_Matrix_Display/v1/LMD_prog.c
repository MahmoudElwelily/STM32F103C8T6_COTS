/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01  												    */
/* Description: program file for LMD interface                      */
/********************************************************************/
#include "STD_TYPES.h"
#include "DELAY_interface.h"
#include "DIO_interface.h"
#include "LMD_interface.h"
#include "LMD_priv.h"
#include "LMD_config.h"

u8 LMD_u8Display (u8 *Copy_Pu8Image,u8 Copy_u8Color)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	u8 i;

	if ((Copy_Pu8Image == NULL) || (Copy_u8Color != LMD_u8_RED &&  Copy_u8Color != LMD_u8_GREEN))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/* if the activity type row/column is active right */
		if (LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_HIGH)
		{
			switch (Copy_u8Color)
			{
				/* if the required color is RED */
				case (LMD_u8_RED):
				{
					for (i = ZERO; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_ACTIVE_PORT,LMD_Au8ActivePort[i]);
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_RED_PORT,~Copy_Pu8Image[i]);
						delay_milliseconds(2);
					}
					break;
				}

				/* if the required color is GREEN */
				case (LMD_u8_GREEN):
				{
					for (i = ZERO; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_ACTIVE_PORT,LMD_Au8ActivePort[i]);
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_GREEN_PORT,~Copy_Pu8Image[i]);
						delay_milliseconds(2);
					}
					break;
				}
			}
		 }
		/* if the activity row/column is active low */
		else
		{
			switch (Copy_u8Color)
			{
				/* if the required color is RED */
				case (LMD_u8_RED):
				{
					for (i = ZERO; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_ACTIVE_PORT,~LMD_Au8ActivePort[i]);
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_RED_PORT,Copy_Pu8Image[i]);
						delay_milliseconds(2);
					}
					break;
				}

				/* if the required color is GREEN */
				case (LMD_u8_GREEN):
				{
					for (i = ZERO; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_ACTIVE_PORT,~LMD_Au8ActivePort[i]);
						Local_u8Error = DIO_u8SetPortValue (LMD_u8_GREEN_PORT,Copy_Pu8Image[i]);
						delay_milliseconds(2);
					}
					break;
				}
			}
		}
	}

	/*Function return*/
	return Local_u8Error;
}

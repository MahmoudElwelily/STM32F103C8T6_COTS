/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01  												    */
/* Description: program file for LMD interface                      */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "SYSTICK_interface.h"
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
		/* if the activity type row/column is active high */
		if (LMD_u8_ACTIVE_TYPE == LMD_u8_ACTIVE_HIGH)
		{
			switch (Copy_u8Color)
			{
				/* if the required color is RED */
				case (LMD_u8_RED):
				{
					for (i = UNSIGNED_MIN; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_HIGH);
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[0],~GET_BIT(Copy_Pu8Image[i],0));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[1],~GET_BIT(Copy_Pu8Image[i],1));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[2],~GET_BIT(Copy_Pu8Image[i],2));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[3],~GET_BIT(Copy_Pu8Image[i],3));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[4],~GET_BIT(Copy_Pu8Image[i],4));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[5],~GET_BIT(Copy_Pu8Image[i],5));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[6],~GET_BIT(Copy_Pu8Image[i],6));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[7],~GET_BIT(Copy_Pu8Image[i],7));
						SysTick_Wait10us(1000);
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_LOW);
					}
					break;
				}

				/* if the required color is GREEN */
				case (LMD_u8_GREEN):
				{
					for (i = UNSIGNED_MIN; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_HIGH);
            Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[0],~GET_BIT(Copy_Pu8Image[i],0));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[1],~GET_BIT(Copy_Pu8Image[i],1));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[2],~GET_BIT(Copy_Pu8Image[i],2));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[3],~GET_BIT(Copy_Pu8Image[i],3));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[4],~GET_BIT(Copy_Pu8Image[i],4));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[5],~GET_BIT(Copy_Pu8Image[i],5));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[6],~GET_BIT(Copy_Pu8Image[i],6));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[7],~GET_BIT(Copy_Pu8Image[i],7));
						delay_milliseconds(2);
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_LOW);
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
					for (i = UNSIGNED_MIN; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_LOW);
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[0],GET_BIT(Copy_Pu8Image[i],0));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[1],GET_BIT(Copy_Pu8Image[i],1));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[2],GET_BIT(Copy_Pu8Image[i],2));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[3],GET_BIT(Copy_Pu8Image[i],3));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[4],GET_BIT(Copy_Pu8Image[i],4));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[5],GET_BIT(Copy_Pu8Image[i],5));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[6],GET_BIT(Copy_Pu8Image[i],6));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8RedPrt[7],GET_BIT(Copy_Pu8Image[i],7));
						delay_milliseconds(2);
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_HIGH);
					}
					break;
				}

				/* if the required color is GREEN */
				case (LMD_u8_GREEN):
				{
					for (i = UNSIGNED_MIN; i < LMD_u8_SIZE ; i++)
					{
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_LOW);
            Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[0],GET_BIT(Copy_Pu8Image[i],0));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[1],GET_BIT(Copy_Pu8Image[i],1));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[2],GET_BIT(Copy_Pu8Image[i],2));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[3],GET_BIT(Copy_Pu8Image[i],3));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[4],GET_BIT(Copy_Pu8Image[i],4));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[5],GET_BIT(Copy_Pu8Image[i],5));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[6],GET_BIT(Copy_Pu8Image[i],6));
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8GreenPrt[7],GET_BIT(Copy_Pu8Image[i],7));
						delay_milliseconds(2);
						Local_u8Error = DIO_u8SetPinValue (LMD_Au8LmdActPrt[i],DIO_u8_PIN_HIGH);
					}
					break;
				}
			}
		}
	}

	/*Function return*/
	return Local_u8Error;
}

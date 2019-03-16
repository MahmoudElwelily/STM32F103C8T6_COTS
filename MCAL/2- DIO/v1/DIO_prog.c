/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Program file for using DIO peripheral in STM32F103               */
/********************************************************************/
#include "STD_TYPES.h"
#include "BIT_CALC.h"
#include "DIO_interface.h"
#include "DIO_priv.h"
#include "DIO_config.h"

/*
 * Description: Function to set the initialized direction and value of each pin in all ports
 * Inputs: none
 * Output: the Error state of the function
 */
void DIO_vInit (void)
{
	GPIOA_CRL = ((DIO_u8_PIN0_INIT_MODE << 0) | (DIO_u8_PIN1_INIT_MODE << 4) | (DIO_u8_PIN2_INIT_MODE << 8)
				| (DIO_u8_PIN3_INIT_MODE << 12) | (DIO_u8_PIN4_INIT_MODE << 16) | (DIO_u8_PIN5_INIT_MODE << 20)
				| (DIO_u8_PIN6_INIT_MODE << 24) | (DIO_u8_PIN7_INIT_MODE << 28));

	GPIOA_CRH = ((DIO_u8_PIN8_INIT_MODE << 0) | (DIO_u8_PIN9_INIT_MODE << 4) | (DIO_u8_PIN10_INIT_MODE << 8)
				| (DIO_u8_PIN11_INIT_MODE << 12) | (DIO_u8_PIN12_INIT_MODE << 16) | (DIO_u8_PIN13_INIT_MODE << 20)
				| (DIO_u8_PIN14_INIT_MODE << 24) | (DIO_u8_PIN15_INIT_MODE << 28));

	GPIOB_CRL = (DIO_u8_PIN16_INIT_MODE << 0) | (DIO_u8_PIN17_INIT_MODE << 4) | (DIO_u8_PIN18_INIT_MODE << 8)
				| (DIO_u8_PIN19_INIT_MODE << 12) | (DIO_u8_PIN20_INIT_MODE << 16) | (DIO_u8_PIN21_INIT_MODE << 20)
				| (DIO_u8_PIN22_INIT_MODE << 24) | (DIO_u8_PIN23_INIT_MODE << 28);


	GPIOB_CRH = ((DIO_u8_PIN24_INIT_MODE << 0) | (DIO_u8_PIN25_INIT_MODE << 4) | (DIO_u8_PIN26_INIT_MODE << 8)
				| (DIO_u8_PIN27_INIT_MODE << 12) | (DIO_u8_PIN28_INIT_MODE << 16) | (DIO_u8_PIN29_INIT_MODE << 20)
				| (DIO_u8_PIN30_INIT_MODE << 24) | (DIO_u8_PIN31_INIT_MODE << 28));

	GPIOC_CRH = ((DIO_u8_PIN32_INIT_MODE << 20) | (DIO_u8_PIN33_INIT_MODE << 24) | (DIO_u8_PIN34_INIT_MODE << 28));


	GPIOD_CRL = ((DIO_u8_PIN35_INIT_MODE << 0) | (DIO_u8_PIN36_INIT_MODE << 4));

	GPIOA_ODR = ((DIO_u8_PIN0_INIT_STATE << 0) | (DIO_u8_PIN1_INIT_STATE << 1) | (DIO_u8_PIN2_INIT_STATE << 2)
				| (DIO_u8_PIN3_INIT_STATE << 3) | (DIO_u8_PIN4_INIT_STATE << 4) | (DIO_u8_PIN5_INIT_STATE << 5)
				| (DIO_u8_PIN6_INIT_STATE << 6) | (DIO_u8_PIN7_INIT_STATE << 7) | (DIO_u8_PIN8_INIT_STATE << 8)
				| (DIO_u8_PIN9_INIT_STATE << 9) | (DIO_u8_PIN10_INIT_STATE << 10) | (DIO_u8_PIN11_INIT_STATE << 11)
				| (DIO_u8_PIN12_INIT_STATE << 12) | (DIO_u8_PIN13_INIT_STATE << 13) | (DIO_u8_PIN14_INIT_STATE << 14)
				| (DIO_u8_PIN15_INIT_STATE << 15));

	GPIOB_ODR = ((DIO_u8_PIN16_INIT_STATE << 0) | (DIO_u8_PIN17_INIT_STATE << 1) | (DIO_u8_PIN18_INIT_STATE << 2)
				| (DIO_u8_PIN19_INIT_STATE << 3) | (DIO_u8_PIN20_INIT_STATE << 4) | (DIO_u8_PIN21_INIT_STATE << 5)
				| (DIO_u8_PIN22_INIT_STATE << 6) | (DIO_u8_PIN23_INIT_STATE << 7) | (DIO_u8_PIN24_INIT_STATE << 8)
				| (DIO_u8_PIN25_INIT_STATE << 9) | (DIO_u8_PIN26_INIT_STATE << 10) | (DIO_u8_PIN27_INIT_STATE << 11)
				| (DIO_u8_PIN28_INIT_STATE << 12) | (DIO_u8_PIN29_INIT_STATE << 13) | (DIO_u8_PIN30_INIT_STATE << 14)
				| (DIO_u8_PIN31_INIT_STATE << 15));

	GPIOC_ODR = ((DIO_u8_PIN32_INIT_STATE << 13) | (DIO_u8_PIN33_INIT_STATE << 14) | (DIO_u8_PIN34_INIT_STATE << 15));

	GPIOD_ODR = (DIO_u8_PIN35_INIT_STATE << 0) | (DIO_u8_PIN36_INIT_STATE << 1);

	return;
}

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinMode (u8 Copy_u8PinNb,u8 Copy_u8Mode)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if((Copy_u8PinNb >= DIO_u8MAXPINNB) ||
			((Copy_u8Mode != DIO_u8_INPUT_ANALOG) && (Copy_u8Mode != DIO_u8_INPUT_FLOATING)
		      && (Copy_u8Mode != DIO_u8_INPUT_PULL_UP_DOWN) && (Copy_u8Mode != DIO_u8_OUPUT_10MHZ_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_10MHZ_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_10MHZ_ALTFUN_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_10MHZ_ALTFUN_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_2MHZ_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_2MHZ_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_2MHZ_ALTFUN_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_2MHZ_ALTFUN_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_50MHZ_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_50MHZ_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_50MHZ_ALTFUN_PUSHPULL)
			  && (Copy_u8Mode != DIO_u8_OUPUT_50MHZ_ALTFUN_OPENDRAIN)))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/*if the selected pin is in PORTA within A0-A7*/
		if (Copy_u8PinNb < DIO_u8_PIN8)
		{
			ASSIGN_NIBBLE(GPIOA_CRL,Copy_u8PinNb,Copy_u8Mode);
		}
		/*if the selected pin is in PORTA within A8-A15*/
		else if (Copy_u8PinNb >= DIO_u8_PIN8 && Copy_u8PinNb < DIO_u8_PIN16)
		{
			ASSIGN_NIBBLE(GPIOA_CRH,(Copy_u8PinNb-8),Copy_u8Mode);
		}
		/*if the selected pin is in PORTB within B0-B7*/
		else if (Copy_u8PinNb >= DIO_u8_PIN16 && Copy_u8PinNb < DIO_u8_PIN24)
		{
			ASSIGN_NIBBLE(GPIOB_CRL,(Copy_u8PinNb-16),Copy_u8Mode);
		}
		/*if the selected pin is in PORTB within B8-B15*/
		else if (Copy_u8PinNb >= DIO_u8_PIN24 && Copy_u8PinNb < DIO_u8_PIN32)
		{
			ASSIGN_NIBBLE(GPIOB_CRH,(Copy_u8PinNb-24),Copy_u8Mode);
		}
		/*if the selected pin is in PORTC within C13-C15*/
		else if (Copy_u8PinNb >= DIO_u8_PIN32 && Copy_u8PinNb < DIO_u8_PIN35)
		{
			switch (Copy_u8PinNb)
			{
				/*if pin C13 is selected*/
			    case DIO_u8_PIN32:
			    {
			    	ASSIGN_NIBBLE(GPIOC_CRH,DIO_u8_PIN5,Copy_u8Mode);
			    	break;
			    }
			    /*if pin C14 is selected*/
			    case DIO_u8_PIN33:
			    {
			    	ASSIGN_NIBBLE(GPIOC_CRH,DIO_u8_PIN6,Copy_u8Mode);
			    	break;
			    }
			    /*if pin C15 is selected*/
			    case DIO_u8_PIN34:
			    {
			    	ASSIGN_NIBBLE(GPIOC_CRH,DIO_u8_PIN7,Copy_u8Mode);
			    	break;
			    }
			}

		}
		/*if the selected pin is in PORTD (D0,D1)*/
		else if (Copy_u8PinNb >= DIO_u8_PIN35 && Copy_u8PinNb < DIO_u8MAXPINNB)
		{
			ASSIGN_NIBBLE(GPIOD_CRL,(Copy_u8PinNb-DIO_u8_PIN35),Copy_u8Mode);
		}
		Local_u8Error = ERROR_OK;
	}

	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set a specific pin in a specified port with a specified value (INPUT = 0,OUTPUT = 1)
 * Inputs: the pin number , the pin value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinValue (u8 Copy_u8PinNb, u8 Copy_u8Value)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNb >= DIO_u8MAXPINNB) || ((Copy_u8Value != DIO_u8_PIN_HIGH) && (Copy_u8Value != DIO_u8_PIN_LOW)))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8Value)
		{
			case (DIO_u8_PIN_HIGH):   /* if the pin value is high */
			{
				/*if the selected pin is in PORTA within A0-A15*/
				if (Copy_u8PinNb < DIO_u8_PIN16)
				{
					SET_BIT(GPIOA_BSRR,Copy_u8PinNb);
				}
				/*if the selected pin is in PORTB within B0-B15*/
				else if (Copy_u8PinNb >= DIO_u8_PIN16 && Copy_u8PinNb < DIO_u8_PIN32)
				{
					SET_BIT(GPIOB_BSRR,(Copy_u8PinNb-16));
				}
				/*if the selected pin is in PORTC within C13-C15*/
				else if (Copy_u8PinNb >= DIO_u8_PIN32 && Copy_u8PinNb < DIO_u8_PIN35)
				{
					switch (Copy_u8PinNb)
					{
						/*if pin C13 is selected*/
						case DIO_u8_PIN32:
						{
							SET_BIT(GPIOC_BSRR,DIO_u8_PIN13);
							break;
						}
						/*if pin C14 is selected*/
						case DIO_u8_PIN33:
						{
							SET_BIT(GPIOC_BSRR,DIO_u8_PIN14);
							break;
						}
						/*if pin C15 is selected*/
						case DIO_u8_PIN34:
						{
							SET_BIT(GPIOC_BSRR,DIO_u8_PIN15);
							break;
						}
					}
				}
				/*if the selected pin is in PORTD (D0,D1)*/
				else if (Copy_u8PinNb >= DIO_u8_PIN35 && Copy_u8PinNb < DIO_u8MAXPINNB)
				{
					SET_BIT(GPIOD_BSRR,(Copy_u8PinNb-DIO_u8_PIN35));
				}
				break;
			}
			case(DIO_u8_PIN_LOW):   /* if the pin value is low */
			{
				/*if the selected pin is in PORTA within A0-A15*/
				if (Copy_u8PinNb < DIO_u8_PIN16)
				{
					SET_BIT(GPIOA_BRR,Copy_u8PinNb);
				}
				/*if the selected pin is in PORTB within B0-B15*/
				else if (Copy_u8PinNb >= DIO_u8_PIN16 && Copy_u8PinNb < DIO_u8_PIN32)
				{
					SET_BIT(GPIOB_BRR,(Copy_u8PinNb-16));
				}
				/*if the selected pin is in PORTC within C13-C15*/
				else if (Copy_u8PinNb >= DIO_u8_PIN32 && Copy_u8PinNb < DIO_u8_PIN35)
				{
					switch (Copy_u8PinNb)
					{
						/*if pin C13 is selected*/
						case DIO_u8_PIN32:
						{
							SET_BIT(GPIOC_BRR,DIO_u8_PIN13);
							break;
						}
						/*if pin C14 is selected*/
						case DIO_u8_PIN33:
						{
							SET_BIT(GPIOC_BRR,DIO_u8_PIN14);
							break;
						}
						/*if pin C15 is selected*/
						case DIO_u8_PIN34:
						{
							SET_BIT(GPIOC_BRR,DIO_u8_PIN15);
							break;
						}
					}
				}
				/*if the selected pin is in PORTD (D0,D1)*/
				else if (Copy_u8PinNb >= DIO_u8_PIN35 && Copy_u8PinNb < DIO_u8MAXPINNB)
				{
					SET_BIT(GPIOD_BRR,(Copy_u8PinNb-DIO_u8_PIN35));
				}
				break;
			}
		}
	}

	Local_u8Error = ERROR_OK;
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number , the container variable which will hold the value on this pin
 * output: the Error state of the function
 */
u8 DIO_u8GetPinValue (u8 Copy_u8PinNb,u8 *Copy_u8PinValue)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if ((Copy_u8PinNb >= DIO_u8MAXPINNB) || (Copy_u8PinValue == NULL))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/*if the selected pin is in PORTA within A0-A15*/
		if (Copy_u8PinNb < DIO_u8_PIN16)
		{
			*Copy_u8PinValue = GET_BIT(GPIOA_IDR,Copy_u8PinNb);
		}
		/*if the selected pin is in PORTB within B0-B15*/
		else if (Copy_u8PinNb >= DIO_u8_PIN16 && Copy_u8PinNb < DIO_u8_PIN32)
		{
			*Copy_u8PinValue = GET_BIT(GPIOB_IDR,(Copy_u8PinNb-16));
		}
		/*if the selected pin is in PORTC within C13-C15*/
		else if (Copy_u8PinNb >= DIO_u8_PIN32 && Copy_u8PinNb < DIO_u8_PIN35)
		{
			switch (Copy_u8PinNb)
			{
				/*if pin C13 is selected*/
				case DIO_u8_PIN32:
				{
					*Copy_u8PinValue = GET_BIT(GPIOC_IDR,DIO_u8_PIN13);
					break;
				}
				/*if pin C14 is selected*/
				case DIO_u8_PIN33:
				{
					*Copy_u8PinValue = GET_BIT(GPIOC_IDR,DIO_u8_PIN14);
					break;
				}
				/*if pin C15 is selected*/
				case DIO_u8_PIN34:
				{
					*Copy_u8PinValue = GET_BIT(GPIOC_IDR,DIO_u8_PIN15);
					break;
				}
			}
		}
		/*if the selected pin is in PORTD (D0,D1)*/
		else if (Copy_u8PinNb >= DIO_u8_PIN35 && Copy_u8PinNb < DIO_u8MAXPINNB)
		{
			*Copy_u8PinValue = GET_BIT(GPIOD_IDR,(Copy_u8PinNb-DIO_u8_PIN35));
		}
		Local_u8Error = ERROR_OK;
	}

	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set the direction of the whole pins in a specified port
 * Inputs: the port number and direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortMode (u8 Copy_u8PortNb,u8 Copy_u8Mode)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;
	u8 iter;

	/*checking the error possibilities of the inputs*/
	if((Copy_u8PortNb >= DIO_u8MAXPortNB))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		/* if the assigned port is PORT A */
		if(Copy_u8PortNb == DIO_u8_PORT_A)
		{
			for (iter = ZERO; iter < (DIO_u8NUMBER_OF_PINS_IN_PORT/2);iter++)
			{
				ASSIGN_NIBBLE(GPIOA_CRL,iter,Copy_u8Mode);
				ASSIGN_NIBBLE(GPIOA_CRH,iter,Copy_u8Mode);
			}
		}
		/* if the assigned port is PORT B */
		else if(Copy_u8PortNb == DIO_u8_PORT_B)
		{
			for (iter = ZERO; iter < (DIO_u8NUMBER_OF_PINS_IN_PORT/2);iter++)
			{
				ASSIGN_NIBBLE(GPIOB_CRL,iter,Copy_u8Mode);
				ASSIGN_NIBBLE(GPIOB_CRH,iter,Copy_u8Mode);
			}
		}
		Local_u8Error = ERROR_OK;
	}

	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNb, u32 Copy_u8Value)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB)
		Local_u8Error = ERROR_NOK;
	else
	{
		/* if the assigned port is PORT A */
		if(Copy_u8PortNb == DIO_u8_PORT_A)
		{
			ASSIGN_BITS (GPIOA_ODR,Copy_u8Value);
		}
		/* if the assigned port is PORT B */
		else if(Copy_u8PortNb == DIO_u8_PORT_B)
		{
			ASSIGN_BITS (GPIOB_ODR,Copy_u8Value);
		}
		Local_u8Error = ERROR_OK;
	}

	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNb, u32 *Copy_u8PortValue)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB || Copy_u8PortValue == NULL)
		Local_u8Error = ERROR_NOK;
	else
	{
		/* if the assigned port is in PORT A */
		if(Copy_u8PortNb == DIO_u8_PORT_A)
		{
			*Copy_u8PortValue = GPIOA_IDR;
		}
		/* if the assigned port is in PORT B */
		else if(Copy_u8PortNb == DIO_u8_PORT_B)
		{
			*Copy_u8PortValue = GPIOB_IDR;
		}
		Local_u8Error = ERROR_OK;
	}

	/*Function return*/
	return Local_u8Error;
}

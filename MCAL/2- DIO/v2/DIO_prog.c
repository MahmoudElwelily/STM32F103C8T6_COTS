/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V02                                                    */
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
	/* Setting the initialized mode of each pin in Port A */
	DIO_GPIOA->CRL.ByteAccess = ((DIO_u8_PIN0_INIT_MODE << 0) | (DIO_u8_PIN1_INIT_MODE << 4) | (DIO_u8_PIN2_INIT_MODE << 8)
				| (DIO_u8_PIN3_INIT_MODE << 12) | (DIO_u8_PIN4_INIT_MODE << 16) | (DIO_u8_PIN5_INIT_MODE << 20)
				| (DIO_u8_PIN6_INIT_MODE << 24) | (DIO_u8_PIN7_INIT_MODE << 28));

	DIO_GPIOA->CRH.ByteAccess = ((DIO_u8_PIN8_INIT_MODE << 0) | (DIO_u8_PIN9_INIT_MODE << 4) | (DIO_u8_PIN10_INIT_MODE << 8)
				| (DIO_u8_PIN11_INIT_MODE << 12) | (DIO_u8_PIN12_INIT_MODE << 16) | (DIO_u8_PIN13_INIT_MODE << 20)
				| (DIO_u8_PIN14_INIT_MODE << 24) | (DIO_u8_PIN15_INIT_MODE << 28));

	/* Setting the initialized mode of each pin in Port B */
	DIO_GPIOB->CRL.ByteAccess  = (DIO_u8_PIN16_INIT_MODE << 0) | (DIO_u8_PIN17_INIT_MODE << 4) | (DIO_u8_PIN18_INIT_MODE << 8)
				| (DIO_u8_PIN19_INIT_MODE << 12) | (DIO_u8_PIN20_INIT_MODE << 16) | (DIO_u8_PIN21_INIT_MODE << 20)
				| (DIO_u8_PIN22_INIT_MODE << 24) | (DIO_u8_PIN23_INIT_MODE << 28);


	DIO_GPIOB->CRH.ByteAccess = ((DIO_u8_PIN24_INIT_MODE << 0) | (DIO_u8_PIN25_INIT_MODE << 4) | (DIO_u8_PIN26_INIT_MODE << 8)
				| (DIO_u8_PIN27_INIT_MODE << 12) | (DIO_u8_PIN28_INIT_MODE << 16) | (DIO_u8_PIN29_INIT_MODE << 20)
				| (DIO_u8_PIN30_INIT_MODE << 24) | (DIO_u8_PIN31_INIT_MODE << 28));

	/* Setting the initialized mode of pins 13,14,15 in Port C */
	DIO_GPIOC->CRH.ByteAccess = ((DIO_u8_PIN32_INIT_MODE << 20) | (DIO_u8_PIN33_INIT_MODE << 24) | (DIO_u8_PIN34_INIT_MODE << 28));

	/* Setting the initialized mode of pins 0,1 in Port D */
	DIO_GPIOD->CRL.ByteAccess = ((DIO_u8_PIN35_INIT_MODE << 0) | (DIO_u8_PIN36_INIT_MODE << 4));


	/* Setting the initialized state of each pin in Port A */
	DIO_GPIOA->ODR.ByteAccess = ((DIO_u8_PIN0_INIT_STATE << 0) | (DIO_u8_PIN1_INIT_STATE << 1) | (DIO_u8_PIN2_INIT_STATE << 2)
				| (DIO_u8_PIN3_INIT_STATE << 3) | (DIO_u8_PIN4_INIT_STATE << 4) | (DIO_u8_PIN5_INIT_STATE << 5)
				| (DIO_u8_PIN6_INIT_STATE << 6) | (DIO_u8_PIN7_INIT_STATE << 7) | (DIO_u8_PIN8_INIT_STATE << 8)
				| (DIO_u8_PIN9_INIT_STATE << 9) | (DIO_u8_PIN10_INIT_STATE << 10) | (DIO_u8_PIN11_INIT_STATE << 11)
				| (DIO_u8_PIN12_INIT_STATE << 12) | (DIO_u8_PIN13_INIT_STATE << 13) | (DIO_u8_PIN14_INIT_STATE << 14)
				| (DIO_u8_PIN15_INIT_STATE << 15));

	/* Setting the initialized state of each pin in Port B */
	DIO_GPIOB->ODR.ByteAccess = ((DIO_u8_PIN16_INIT_STATE << 0) | (DIO_u8_PIN17_INIT_STATE << 1) | (DIO_u8_PIN18_INIT_STATE << 2)
				| (DIO_u8_PIN19_INIT_STATE << 3) | (DIO_u8_PIN20_INIT_STATE << 4) | (DIO_u8_PIN21_INIT_STATE << 5)
				| (DIO_u8_PIN22_INIT_STATE << 6) | (DIO_u8_PIN23_INIT_STATE << 7) | (DIO_u8_PIN24_INIT_STATE << 8)
				| (DIO_u8_PIN25_INIT_STATE << 9) | (DIO_u8_PIN26_INIT_STATE << 10) | (DIO_u8_PIN27_INIT_STATE << 11)
				| (DIO_u8_PIN28_INIT_STATE << 12) | (DIO_u8_PIN29_INIT_STATE << 13) | (DIO_u8_PIN30_INIT_STATE << 14)
				| (DIO_u8_PIN31_INIT_STATE << 15));

	/* Setting the initialized state of pins 13,14,15 in Port C */
	DIO_GPIOC->ODR.ByteAccess = ((DIO_u8_PIN32_INIT_STATE << 13) | (DIO_u8_PIN33_INIT_STATE << 14) | (DIO_u8_PIN34_INIT_STATE << 15));

	/* Setting the initialized state of pins 0,1 in Port D */
	DIO_GPIOD->ODR.ByteAccess = (DIO_u8_PIN35_INIT_STATE << 0) | (DIO_u8_PIN36_INIT_STATE << 1);

	return;
}

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNb,u8 Copy_u8Mode)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;

	/*Local variables holding the actual port number and the pin number */
	u8 Local_u8PortId = Copy_u8PinNb / DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNb % DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the error possibilities of the inputs*/
	if(
			((Copy_u8Mode != DIO_u8_INPUT_ANALOG) && (Copy_u8Mode != DIO_u8_INPUT_FLOATING)
		      && (Copy_u8Mode != DIO_u8_INPUT_PULL_UP) && (Copy_u8Mode != DIO_u8_INPUT_PULL_DOWN)
			  && (Copy_u8Mode != DIO_u8_OUPUT_10M_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_10M_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_10M_OPENDRAIN)
		      && (Copy_u8Mode != DIO_u8_OUPUT_10M_ALTFUN_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_2M_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_2M_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_2M_ALTFUN_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_2M_ALTFUN_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_50M_PUSHPULL)
		      && (Copy_u8Mode != DIO_u8_OUPUT_50M_OPENDRAIN) && (Copy_u8Mode != DIO_u8_OUPUT_50M_ALTFUN_PUSHPULL)
			  && (Copy_u8Mode != DIO_u8_OUPUT_50M_ALTFUN_OPENDRAIN))
      )
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		if (Copy_u8Mode == DIO_u8_INPUT_PULL_UP)
		{
			switch (Local_u8PortId)
			{
				case DIO_u8_PORT_A:
				{
					SET_BIT(DIO_GPIOA->ODR.ByteAccess,Local_u8PinId);
					break;
				}
				case DIO_u8_PORT_B:
				{
					SET_BIT(DIO_GPIOB->ODR.ByteAccess,Local_u8PinId);
					break;
				}
				case DIO_u8_PORT_C:
				{
					SET_BIT(DIO_GPIOC->ODR.ByteAccess,Local_u8PinId);
					break;
				}
				case DIO_u8_PORT_D:
				{
					SET_BIT(DIO_GPIOD->ODR.ByteAccess,Local_u8PinId);
					break;
				}
			}
		}
		else if (Copy_u8Mode == DIO_u8_INPUT_PULL_DOWN)
		{
			switch (Local_u8PortId)
			{
				case DIO_u8_PORT_A:
				{
					CLEAR_BIT(DIO_GPIOA->ODR.ByteAccess,Local_u8PinId);
					break;
				}
				case DIO_u8_PORT_B:
				{
					CLEAR_BIT(DIO_GPIOB->ODR.ByteAccess,Local_u8PinId);
					break;
				}
				case DIO_u8_PORT_C:
				{
					CLEAR_BIT(DIO_GPIOC->ODR.ByteAccess,Local_u8PinId);
					break;
				}
				case DIO_u8_PORT_D:
				{
					CLEAR_BIT(DIO_GPIOD->ODR.ByteAccess,Local_u8PinId);
					break;
				}
			}
			Copy_u8Mode = DIO_u8_INPUT_PULL_UP;
		}
		if (Local_u8PinId <= 7)
		{
			switch (Local_u8PortId)
			{
				case DIO_u8_PORT_A:
				{
					ASSIGN_NIBBLE(DIO_GPIOA->CRL.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				case DIO_u8_PORT_B:
				{
					ASSIGN_NIBBLE(DIO_GPIOB->CRL.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				case DIO_u8_PORT_C:
				{
					ASSIGN_NIBBLE(DIO_GPIOC->CRL.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				case DIO_u8_PORT_D:
				{
					ASSIGN_NIBBLE(DIO_GPIOD->CRL.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				default:  Local_u8Error = ERROR_NOK;
			}
		}
    else
		{
			Local_u8PinId -= 8;
			switch (Local_u8PortId)
			{
				case DIO_u8_PORT_A:
				{
					ASSIGN_NIBBLE(DIO_GPIOA->CRH.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				case DIO_u8_PORT_B:
				{
					ASSIGN_NIBBLE(DIO_GPIOB->CRH.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				case DIO_u8_PORT_C:
				{
					ASSIGN_NIBBLE(DIO_GPIOC->CRH.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				case DIO_u8_PORT_D:
				{
					ASSIGN_NIBBLE(DIO_GPIOD->CRH.ByteAccess,Local_u8PinId,Copy_u8Mode);
					break;
				}
				default:  Local_u8Error = ERROR_NOK;
			}
		}
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
	u8 Local_u8Error = ERROR_OK;
	u8 Local_u8PortId = Copy_u8PinNb / DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNb % DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the error possibilities of the inputs*/
	if (((Copy_u8Value != DIO_u8_PIN_HIGH) && (Copy_u8Value != DIO_u8_PIN_LOW)))
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Copy_u8Value)
		{
			case DIO_u8_PIN_HIGH:
				Local_u8Error = u8SetPin(Local_u8PortId,Local_u8PinId); break;

			case DIO_u8_PIN_LOW:
				Local_u8Error = u8ResetPin(Local_u8PortId,Local_u8PinId); break;

			default: Local_u8Error = ERROR_NOK;
		}
	}
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
	u8 Local_u8Error = ERROR_OK;
	u8 Local_u8PortId = Copy_u8PinNb / DIO_u8NUMBER_OF_PINS_IN_PORT;
	u8 Local_u8PinId = Copy_u8PinNb % DIO_u8NUMBER_OF_PINS_IN_PORT;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PinValue == NULL)
	{
		Local_u8Error = ERROR_NOK;
	}
	else
	{
		switch (Local_u8PortId)
		{
			case DIO_u8_PORT_A: *Copy_u8PinValue = GET_BIT(DIO_GPIOA -> IDR.ByteAccess,Local_u8PinId); break;

			case DIO_u8_PORT_B: *Copy_u8PinValue = GET_BIT(DIO_GPIOB -> IDR.ByteAccess,Local_u8PinId); break;

			case DIO_u8_PORT_C: *Copy_u8PinValue = GET_BIT(DIO_GPIOC -> IDR.ByteAccess,Local_u8PinId); break;

			case DIO_u8_PORT_D: *Copy_u8PinValue = GET_BIT(DIO_GPIOD -> IDR.ByteAccess,Local_u8PinId); break;
			default:  Local_u8Error = ERROR_NOK;
		}
	}
	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNb, u8 Copy_u8Value)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB)
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Copy_u8PortNb)
		{
			case DIO_u8_PORT_A: DIO_GPIOA -> ODR.ByteAccess = Copy_u8Value; break;

			case DIO_u8_PORT_B: DIO_GPIOB -> ODR.ByteAccess = Copy_u8Value; break;

			case DIO_u8_PORT_C: DIO_GPIOC -> ODR.ByteAccess = Copy_u8Value; break;

			case DIO_u8_PORT_D: DIO_GPIOD -> ODR.ByteAccess = Copy_u8Value; break;
			default:  Local_u8Error = ERROR_NOK;
		}
	}

	/*Function return*/
	return Local_u8Error;
}

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNb, u8 *Copy_u8PortValue)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error;

	/*checking the error possibilities of the inputs*/
	if (Copy_u8PortNb >= DIO_u8MAXPortNB || Copy_u8PortValue == NULL)
		Local_u8Error = ERROR_NOK;
	else
	{
		switch (Copy_u8PortNb)
		{
			case DIO_u8_PORT_A: *Copy_u8PortValue = DIO_GPIOA -> IDR.ByteAccess; break;

			case DIO_u8_PORT_B: *Copy_u8PortValue = DIO_GPIOB -> IDR.ByteAccess; break;

			case DIO_u8_PORT_C: *Copy_u8PortValue = DIO_GPIOC -> IDR.ByteAccess; break;

			case DIO_u8_PORT_D: *Copy_u8PortValue = DIO_GPIOD -> IDR.ByteAccess; break;
			default:  Local_u8Error = ERROR_NOK;
		}
	}

	/*Function return*/
	return Local_u8Error;
}

//================Private Function=============================
static u8 u8SetPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	switch (Copy_u8Port)
	{
		case DIO_u8_PORT_A: DIO_GPIOA -> BSRR.ByteAccess = (1<<Copy_u8Pin); break;

		case DIO_u8_PORT_B: DIO_GPIOB -> BSRR.ByteAccess = (1<<Copy_u8Pin); break;

		case DIO_u8_PORT_C: DIO_GPIOC -> BSRR.ByteAccess = (1<<Copy_u8Pin); break;

		case DIO_u8_PORT_D: DIO_GPIOD -> BSRR.ByteAccess = (1<<Copy_u8Pin); break;
		default:  Local_u8Error = ERROR_NOK;
	}
	/*Function return*/
	return Local_u8Error;
}

static u8 u8ResetPin(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	/*Local Variable holding the error state*/
	u8 Local_u8Error = ERROR_OK;
	switch (Copy_u8Port)
	{
		case DIO_u8_PORT_A: DIO_GPIOA -> BRR.ByteAccess = (1<<Copy_u8Pin); break;

		case DIO_u8_PORT_B: DIO_GPIOB -> BRR.ByteAccess = (1<<Copy_u8Pin); break;

		case DIO_u8_PORT_C: DIO_GPIOC -> BRR.ByteAccess = (1<<Copy_u8Pin); break;

		case DIO_u8_PORT_D: DIO_GPIOD -> BRR.ByteAccess = (1<<Copy_u8Pin); break;
		default:  Local_u8Error = ERROR_NOK;
	}
	/*Function return*/
	return Local_u8Error;
}

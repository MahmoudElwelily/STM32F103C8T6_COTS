/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 24-Feb-19                                            */
/* Version: 02                                                */
/* Description: Program file for RCC Driver in STM32F103      */
/**************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "RCC_interface.h" 
#include "RCC_priv.h" 
#include "RCC_config.h" 

/*
 * Description: Function to set the initialized direction and value of each pin in all ports
 * Inputs: none
 * Output: void
 */
void RCC_vInit (void)
{
	/*	Checking if HSI is enabled in the configuration file*/
	if (RCC_u8_HSI_STATE == RCC_u8_ENABLE)
	{
		/*Enable Internal high-speed clock in RCC_CR register */
		SET_BIT(RCC->CR.WordAccess,0);

		/*waiting HSI clock to be ready and stable*/
		while (GET_BIT(RCC->CR.WordAccess,1) == 0);
	}
	else
	{
		/*Disable Internal high-speed clock in RCC_CR register */
		CLEAR_BIT(RCC->CR.WordAccess,0);
	}
	/*============================================================*/
	/*	Checking if HSE is enabled in the configuration file*/
	if (RCC_u8_HSE_STATE == RCC_u8_ENABLE)
	{
		/*Enable External high-speed clock in RCC_CR register */
		SET_BIT(RCC->CR.WordAccess,16);

		/*waiting HSE clock to be ready and stable*/
		while (GET_BIT(RCC->CR.WordAccess,17) == 0);
	}
	else
	{
		/*Disable External high-speed clock in RCC_CR register */
		CLEAR_BIT(RCC->CR.WordAccess,16);
	}
	/*============================================================*/
	/*	Checking if PLL is enabled in the configuration file*/
	if (RCC_u8_PLL_STATE == RCC_u8_ENABLE)
	{
		/*Step(1): Enable HSI and select it*/
		/*Enable Internal high-speed clock in RCC_CR register */
		SET_BIT(RCC->CR.WordAccess,0);

		/*waiting HSI clock to be ready and stable*/
		while (GET_BIT(RCC->CR.WordAccess,1) == 0);

		/*Select HSI as the system clock in RCC_CFGR register */
		CLEAR_BIT(RCC->CFGR.WordAccess,1);CLEAR_BIT(RCC->CFGR.WordAccess,0);
		/*********************/
		/*Step(2): Disable PLL in RCC_CR_register*/
		CLEAR_BIT(RCC->CR.WordAccess,24);
		/*********************/
		/*Step(3): Set the PLL configurations*/
		if (RCC_u8_PLLSRC == RCC_u8_HSI_DIVIDED_BY_2)
			CLEAR_BIT(RCC->CFGR.WordAccess,16);
		else
		{
			if (RCC_u8_PLLXTPRE == RCC_u8_HSE_NOT_DIVIDED)
				CLEAR_BIT(RCC->CFGR.WordAccess,17);
			else
				SET_BIT(RCC->CFGR.WordAccess,17);
			SET_BIT(RCC->CFGR.WordAccess,16);
		}
		RCC->CFGR.WordAccess |= (RCC_u8_PLLMUL<<18);
		/*********************/
		/*Step(4): Enable the PLL and select it*/
		/*Enable PLL clock in RCC_CR register */
		SET_BIT(RCC->CR.WordAccess,24);
		/*waiting PLL clock to be ready and stable*/
		while (GET_BIT(RCC->CR.WordAccess,25) == 0);
	}
	else
	{
		/*Disable PLL clock in RCC_CR register */
		CLEAR_BIT(RCC->CR.WordAccess,24);
	}
	/*============================================================*/
	/*Checking the initial configuration of the System Clock*/
	switch (RCC_u8_SYS_CLOCK)
	{
		case (RCC_u8_HSI):
		{
			/*Select HSI as the system clock in RCC_CFGR register */
			CLEAR_BIT(RCC->CFGR.WordAccess,1);CLEAR_BIT(RCC->CFGR.WordAccess,0);
			break;
		}
		case (RCC_u8_HSE):
		{
			/*Select HSE as the system clock in RCC_CFGR register */
			CLEAR_BIT(RCC->CFGR.WordAccess,1);SET_BIT(RCC->CFGR.WordAccess,0);
			break;
		}
		case (RCC_u8_PLL):
		{
			/*Select PLL as the system clock in RCC_CFGR register */
			SET_BIT(RCC->CFGR.WordAccess,1);CLEAR_BIT(RCC->CFGR.WordAccess,0);
			break;
		}
	}
	/*============================================================*/
	/*Checking the initial configuration of AHB prescaler*/
	switch (RCC_u8_AHB_PRESCALER)
	{
		case (RCC_u8_NOT_DIVIDED):
		{
			CLEAR_BIT(RCC->CFGR.WordAccess,7);
			break;
		}
		case (RCC_u8_DIVIDED_BY_2):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			CLEAR_BIT(RCC->CFGR.WordAccess,6);
			CLEAR_BIT(RCC->CFGR.WordAccess,5);
			CLEAR_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_4):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			CLEAR_BIT(RCC->CFGR.WordAccess,6);
			CLEAR_BIT(RCC->CFGR.WordAccess,5);
			SET_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_8):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			CLEAR_BIT(RCC->CFGR.WordAccess,6);
			SET_BIT(RCC->CFGR.WordAccess,5);
			CLEAR_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_16):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			CLEAR_BIT(RCC->CFGR.WordAccess,6);
			SET_BIT(RCC->CFGR.WordAccess,5);
			SET_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_64):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			SET_BIT(RCC->CFGR.WordAccess,6);
			CLEAR_BIT(RCC->CFGR.WordAccess,5);
			CLEAR_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_128):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			SET_BIT(RCC->CFGR.WordAccess,6);
			CLEAR_BIT(RCC->CFGR.WordAccess,5);
			SET_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_256):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			SET_BIT(RCC->CFGR.WordAccess,6);
			SET_BIT(RCC->CFGR.WordAccess,5);
			CLEAR_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
		case (RCC_u8_DIVIDED_BY_512):
		{
			SET_BIT(RCC->CFGR.WordAccess,7);
			SET_BIT(RCC->CFGR.WordAccess,6);
			SET_BIT(RCC->CFGR.WordAccess,5);
			SET_BIT(RCC->CFGR.WordAccess,4);
			break;
		}
	}
	/*============================================================*/
	/*Checking the initial configuration of APB1 prescaler*/
	switch (RCC_u8_APB1_PRESCALER)
	{
		case (RCC_u8_NOT_DIVIDED):
		{
			CLEAR_BIT(RCC->CFGR.WordAccess,10);
			break;
		}
		case (RCC_u8_DIVIDED_BY_2):
		{
			SET_BIT(RCC->CFGR.WordAccess,10);
			CLEAR_BIT(RCC->CFGR.WordAccess,9);
			CLEAR_BIT(RCC->CFGR.WordAccess,8);
			break;
		}
		case (RCC_u8_DIVIDED_BY_4):
		{
			SET_BIT(RCC->CFGR.WordAccess,10);
			CLEAR_BIT(RCC->CFGR.WordAccess,9);
			SET_BIT(RCC->CFGR.WordAccess,8);
			break;
		}
		case (RCC_u8_DIVIDED_BY_8):
		{
			SET_BIT(RCC->CFGR.WordAccess,10);
			SET_BIT(RCC->CFGR.WordAccess,9);
			CLEAR_BIT(RCC->CFGR.WordAccess,8);
			break;
		}
		case (RCC_u8_DIVIDED_BY_16):
		{
			SET_BIT(RCC->CFGR.WordAccess,10);
			SET_BIT(RCC->CFGR.WordAccess,9);
			SET_BIT(RCC->CFGR.WordAccess,8);
			break;
		}
	}
	/*============================================================*/
	/*Checking the initial configuration of APB2 prescaler*/
	switch (RCC_u8_APB2_PRESCALER)
	{
		case (RCC_u8_NOT_DIVIDED):
		{
			CLEAR_BIT(RCC->CFGR.WordAccess,13);
			break;
		}
		case (RCC_u8_DIVIDED_BY_2):
		{
			SET_BIT(RCC->CFGR.WordAccess,13);
			CLEAR_BIT(RCC->CFGR.WordAccess,12);
			CLEAR_BIT(RCC->CFGR.WordAccess,11);
			break;
		}
		case (RCC_u8_DIVIDED_BY_4):
		{
			SET_BIT(RCC->CFGR.WordAccess,13);
			CLEAR_BIT(RCC->CFGR.WordAccess,12);
			SET_BIT(RCC->CFGR.WordAccess,11);
			break;
		}
		case (RCC_u8_DIVIDED_BY_8):
		{
			SET_BIT(RCC->CFGR.WordAccess,13);
			SET_BIT(RCC->CFGR.WordAccess,12);
			CLEAR_BIT(RCC->CFGR.WordAccess,11);
			break;
		}
		case (RCC_u8_DIVIDED_BY_16):
		{
			SET_BIT(RCC->CFGR.WordAccess,13);
			SET_BIT(RCC->CFGR.WordAccess,12);
			SET_BIT(RCC->CFGR.WordAccess,11);
			break;
		}
	}
	return;
}

/*
 * Description: Function to set the state of any peripheral (Enable/disable)
 * Inputs: the peripheral name
 * Output: Error state
 */
u8 RCC_vEnablePeripheralClock (u8 Copy_u8PeriName)
{
	/*Local Variable holding the error state*/
	u32 Local_u8Error = ERROR_OK;

	switch (Copy_u8PeriName)
	{
		/*For APB2 peripherals*/
		case RCC_u8_USART1:
					RCC->APB2ENR.WordAccess |= (1<<14); break;
		case RCC_u8_SPI1:
					RCC->APB2ENR.WordAccess |= (1<<12); break;
		case RCC_u8_TIM1:
					RCC->APB2ENR.WordAccess |= (1<<11); break;
		case RCC_u8_ADC2:
					RCC->APB2ENR.WordAccess |= (1<<10); break;
		case RCC_u8_ADC1:
					RCC->APB2ENR.WordAccess |= (1<<9); break;
		case RCC_u8_IOPD:
					RCC->APB2ENR.WordAccess |= (1<<5); break;
		case RCC_u8_IOPC:
					RCC->APB2ENR.WordAccess |= (1<<4); break;
		case RCC_u8_IOPB:
					RCC->APB2ENR.WordAccess |= (1<<3); break;
		case RCC_u8_IOPA:
					RCC->APB2ENR.WordAccess |= (1<<2); break;
		case RCC_u8_AFIO:
					RCC->APB2ENR.WordAccess |= (1<<0); break;

		/*For APB1 peripherals*/
		case RCC_u8_DAC:
					RCC->APB1ENR.WordAccess |= (1<<29); break;
		case RCC_u8_PWR:
					RCC->APB1ENR.WordAccess |= (1<<28); break;
		case RCC_u8_BKP:
					RCC->APB1ENR.WordAccess |= (1<<27); break;
		case RCC_u8_CAN2:
					RCC->APB1ENR.WordAccess |= (1<<26); break;
		case RCC_u8_CAN1:
					RCC->APB1ENR.WordAccess |= (1<<25); break;
		case RCC_u8_I2C2:
					RCC->APB1ENR.WordAccess |= (1<<22); break;
		case RCC_u8_I2C1:
					RCC->APB1ENR.WordAccess |= (1<<21); break;
		case RCC_u8_USART5:
					RCC->APB1ENR.WordAccess |= (1<<20); break;
		case RCC_u8_USART4:
					RCC->APB1ENR.WordAccess |= (1<<19); break;
		case RCC_u8_USART3:
					RCC->APB1ENR.WordAccess |= (1<<18); break;
		case RCC_u8_USART2:
					RCC->APB1ENR.WordAccess |= (1<<17); break;
		case RCC_u8_SPI3:
					RCC->APB1ENR.WordAccess |= (1<<15); break;
		case RCC_u8_SPI2:
					RCC->APB1ENR.WordAccess |= (1<<14); break;
		case RCC_u8_WWDG:
					RCC->APB1ENR.WordAccess |= (1<<11); break;
		case RCC_u8_TIM7:
					RCC->APB1ENR.WordAccess |= (1<<5); break;
		case RCC_u8_TIM6:
					RCC->APB1ENR.WordAccess |= (1<<4); break;
		case RCC_u8_TIM5:
					RCC->APB1ENR.WordAccess |= (1<<3); break;
		case RCC_u8_TIM4:
					RCC->APB1ENR.WordAccess |= (1<<2); break;
		case RCC_u8_TIM3:
					RCC->APB1ENR.WordAccess |= (1<<1); break;
		case RCC_u8_TIM2:
					RCC->APB1ENR.WordAccess |= (1<<0); break;

		/*For AHB peripherals*/
		case RCC_u8_OTGFS:
					RCC->AHBENR.WordAccess |= (1<<12); break;
		case RCC_u8_CRC:
					RCC->AHBENR.WordAccess |= (1<<6); break;
		case RCC_u8_SRAM:
					RCC->AHBENR.WordAccess |= (1<<2); break;
		case RCC_u8_DMA2:
					RCC->AHBENR.WordAccess |= (1<<1); break;
		case RCC_u8_DMA1:
					RCC->AHBENR.WordAccess |= (1<<0); break;
		default:
			Local_u8Error = ERROR_NOK;
	}
	/* Function return */
	return Local_u8Error;
}

u8 RCC_vDisablePeripheralClock (u8 Copy_u8PeriName)
{
	/*Local Variable holding the error state*/
	u32 Local_u8Error = ERROR_OK;

	switch (Copy_u8PeriName)
	{
		/*For APB2 peripherals*/
		case RCC_u8_USART1:
					RCC->APB2RSTR.WordAccess |= (1<<14); break;
		case RCC_u8_SPI1:
					RCC->APB2RSTR.WordAccess |= (1<<12); break;
		case RCC_u8_TIM1:
					RCC->APB2RSTR.WordAccess |= (1<<11); break;
		case RCC_u8_ADC2:
					RCC->APB2RSTR.WordAccess |= (1<<10); break;
		case RCC_u8_ADC1:
					RCC->APB2RSTR.WordAccess |= (1<<9); break;
		case RCC_u8_IOPD:
					RCC->APB2RSTR.WordAccess |= (1<<5); break;
		case RCC_u8_IOPC:
					RCC->APB2RSTR.WordAccess |= (1<<4); break;
		case RCC_u8_IOPB:
					RCC->APB2RSTR.WordAccess |= (1<<3); break;
		case RCC_u8_IOPA:
					RCC->APB2RSTR.WordAccess |= (1<<2); break;
		case RCC_u8_AFIO:
					RCC->APB2RSTR.WordAccess |= (1<<0); break;

		/*For APB1 peripherals*/
		case RCC_u8_DAC:
					RCC->APB1RSTR.WordAccess |= (1<<29); break;
		case RCC_u8_PWR:
					RCC->APB1RSTR.WordAccess |= (1<<28); break;
		case RCC_u8_BKP:
					RCC->APB1RSTR.WordAccess |= (1<<27); break;
		case RCC_u8_CAN2:
					RCC->APB1RSTR.WordAccess |= (1<<26); break;
		case RCC_u8_CAN1:
					RCC->APB1RSTR.WordAccess |= (1<<25); break;
		case RCC_u8_I2C2:
					RCC->APB1RSTR.WordAccess |= (1<<22); break;
		case RCC_u8_I2C1:
					RCC->APB1RSTR.WordAccess |= (1<<21); break;
		case RCC_u8_USART5:
					RCC->APB1RSTR.WordAccess |= (1<<20); break;
		case RCC_u8_USART4:
					RCC->APB1RSTR.WordAccess |= (1<<19); break;
		case RCC_u8_USART3:
					RCC->APB1RSTR.WordAccess |= (1<<18); break;
		case RCC_u8_USART2:
					RCC->APB1RSTR.WordAccess |= (1<<17); break;
		case RCC_u8_SPI3:
					RCC->APB1RSTR.WordAccess |= (1<<15); break;
		case RCC_u8_SPI2:
					RCC->APB1RSTR.WordAccess |= (1<<14); break;
		case RCC_u8_WWDG:
					RCC->APB1RSTR.WordAccess |= (1<<11); break;
		case RCC_u8_TIM7:
					RCC->APB1RSTR.WordAccess |= (1<<5); break;
		case RCC_u8_TIM6:
					RCC->APB1RSTR.WordAccess |= (1<<4); break;
		case RCC_u8_TIM5:
					RCC->APB1RSTR.WordAccess |= (1<<3); break;
		case RCC_u8_TIM4:
					RCC->APB1RSTR.WordAccess |= (1<<2); break;
		case RCC_u8_TIM3:
					RCC->APB1RSTR.WordAccess |= (1<<1); break;
		case RCC_u8_TIM2:
					RCC->APB1RSTR.WordAccess |= (1<<0); break;

		/*For AHB peripherals*/
		case RCC_u8_OTGFS:
					RCC->AHBRSTR.WordAccess |= (1<<12); break;
		case RCC_u8_CRC:
					RCC->AHBRSTR.WordAccess |= (1<<6); break;
		case RCC_u8_SRAM:
					RCC->AHBRSTR.WordAccess |= (1<<2); break;
		case RCC_u8_DMA2:
					RCC->AHBRSTR.WordAccess |= (1<<1); break;
		case RCC_u8_DMA1:
					RCC->AHBRSTR.WordAccess |= (1<<0); break;
		default:
			Local_u8Error = ERROR_NOK;
	}
	/* Function return */
	return Local_u8Error;
}

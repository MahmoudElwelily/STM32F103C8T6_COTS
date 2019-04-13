/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                                            */
/* Date: 06-Mar-19                                                */
/* Version: 01                                                */
/* Description: Program file for SYSTICK Driver         */
/**************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "SYSTICK_interface.h" 
#include "SYSTICK_priv.h" 
#include "SYSTICK_config.h" 


/*
 * Description: Function to set the initialized configuration in the SysTick control and status register (STK_CTRL)
 * Inputs: none
 * Output: the Error state of the function
 */
void SysTick_Init(void)
{
	if (SYSTICK_u8_CLKSOURCE == SYSTICK_u8_AHB)
	{
		SET_BIT(SYSTICK_TIMER->STK_CTRL.WordAccess,2);
	}
	else if (SYSTICK_u8_CLKSOURCE == SYSTICK_u8_AHB_OVER_8)
	{
		CLEAR_BIT(SYSTICK_TIMER->STK_CTRL.WordAccess,2);
	}

	if (SYSTICK_u8_TICKINT == SYSTICK_u8_DISABLE_EXEP_REQ)
	{
		CLEAR_BIT(SYSTICK_TIMER->STK_CTRL.WordAccess,1);
	}
	else if (SYSTICK_u8_CLKSOURCE == SYSTICK_u8_ENABLE_EXEP_REQ)
	{
		SET_BIT(SYSTICK_TIMER->STK_CTRL.WordAccess,2);
	}
	SET_BIT(SYSTICK_TIMER->STK_CTRL.WordAccess,0);
}

/*
 * Description: Function to make delay in millisecond using the SYSTICK timer
 * Inputs: the required delay as a multiple of 10ms (n*10ms)
 * Output: void
 */
void SysTick_Wait10ms(u32 Copy_u32Delay)
{
	u32 i;
	for (i = 0 ; i < Copy_u32Delay ; i++)
	{
		SYSTICK_vSysTickWait(SYSTICK_u8_10MS_COUNT);
	}
}

/*
 * Description: Function to make delay in nanosecond using the SYSTICK timer
 * Inputs: the required delay as a multiple of 10ns (n*10ns)
 * Output: void
 */
void SysTick_Wait10us(u32 Copy_u32Delay)
{
	u32 i;
	for (i = 0 ; i < Copy_u32Delay ; i++)
	{
		SYSTICK_vSysTickWait(SYSTICK_u8_10US_COUNT);
	}
}

/*
 * Description: The function required for making the delay
 * Inputs: the required number of count should be loaded in theSysTick reload value register (STK_LOAD)
 * Output: void
 */
static void SYSTICK_vSysTickWait(u32 Copy_u32Delay)
{
	SYSTICK_TIMER->STK_LOAD.WordAccess = Copy_u32Delay-1;  //wait for 10ms
	/*Enable the Systick counter*/

	SYSTICK_TIMER->STK_VAL.WordAccess = 0;
	while(GET_BIT(SYSTICK_TIMER->STK_CTRL.WordAccess,16) == 0);

}

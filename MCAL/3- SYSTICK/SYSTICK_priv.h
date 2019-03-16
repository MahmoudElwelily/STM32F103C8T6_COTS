/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                                        */
/* Date: 06-Mar-19                                            */
/* Version: 01                                            */
/* Description: Private file for SYSTICK Driver     */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef SYSTICK_PRIV_H 
#define SYSTICK_PRIV_H 

typedef struct
{
	Register_32Bit STK_CTRL;
	Register_32Bit STK_LOAD;
	Register_32Bit STK_VAL;
	Register_32Bit STK_CALIB;
}SYSTICK;

#define SYSTICK_TIMER          ((SYSTICK*)0xE000E010)

/*Macros for the possible clock frequencies that can feed the Systick Peripheral*/
#define SYSTICK_u8_AHB_OVER_8   (u8)0
#define SYSTICK_u8_AHB 		    (u8)1

/*Macros for the possible states for the SysTick exception request*/
#define SYSTICK_u8_DISABLE_EXEP_REQ (u8)0
#define SYSTICK_u8_ENABLE_EXEP_REQ (u8)1

/*Macros for the required number of count should be made to make a delay
of 10ms or 10us*/
#define SYSTICK_u8_10MS_COUNT     (u32)80000
#define SYSTICK_u8_10US_COUNT     (u32)80

/*
 * Description: The function required for making the delay
 * Inputs: the required number of count should be loaded in theSysTick reload value register (STK_LOAD)
 * Output: void
 */
static void SYSTICK_vSysTickWait(u32 Copy_u32Delay);

#endif /* SYSTICK_PRIV_H */ 

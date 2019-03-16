/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Program file for using Delay functions (in milliseconds) 		*/
/* in AVR ATmega32 using NOP assembly instruction 					*/
/* which takes only one cycle             							*/
/********************************************************************/
#include "STD_TYPES.h"
#include "DELAY_interface.h"
#include "DELAY_priv.h"

/*
 * Description: Function to make delay in millisecond using NOP assembly instruction
 * Inputs: the required delay in millisecond
 * Output: void
 */
void delay_milliSecond(u32 value){
	value = (u32)value*Milli2Micro;
	value = (u32)(value - DELAY_u32_T1 - DELAY_u32_T2 - DELAY_u32_T3) ;
	value = (u32)(value / DELAY_u32_LOOPTIME) ;
	for (u32 ii = 0 ; ii < (u32)value ; ii++)
	{
		for (u16 i = 0 ; i < (u16)MAX_TO_1m ; i++)
		{
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
		}

	}
}



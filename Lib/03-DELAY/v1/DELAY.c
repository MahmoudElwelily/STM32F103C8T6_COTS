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
#include "DELAY.h"

/*
 * Description: Function to make delay in millisecond using NOP assembly instruction
 * Inputs: the required delay in millisecond
 * Output: void
 */
void DELAY_vMilliSecond (u32 Copy_u32MilliTime) {
	u32 Local_u8Iter = 0;
	u32 Local_u8Count;

	Copy_u32MilliTime = (Copy_u32MilliTime*DELAY_u32_IN_MILLI)-DELAY_u32_T1-DELAY_u32_T2-DELAY_u32_T3;
	Local_u8Count = Copy_u32MilliTime/DELAY_u32_LOOPTIME;

	for (; Local_u8Iter < Local_u8Count ; Local_u8Iter++)
	{
		asm("NOP");
	}
}

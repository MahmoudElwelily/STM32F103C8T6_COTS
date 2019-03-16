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
void delay_milliseconds (u32 Copy_u32OuterLoopIterations)
{

	u32 u32OuterLoopIndex = 0, u32InnerLoopIndex = 0;

	for(u32OuterLoopIndex = 0; u32OuterLoopIndex < Copy_u32OuterLoopIterations; u32OuterLoopIndex++)
	{

		// This loop yields 1 millisecond

		for(u32InnerLoopIndex = 0; u32InnerLoopIndex < INNER_LOOP_ITERATIONS; u32InnerLoopIndex++)
		{
			asm("NOP");
			asm("NOP");
			asm("NOP");
			asm("NOP");
		}
	}

}



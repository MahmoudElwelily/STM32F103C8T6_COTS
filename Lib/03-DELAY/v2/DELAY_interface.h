/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Interface file for using Delay functions (in milliseconds) 		*/
/* in AVR ATmega32 using NOP assembly instruction 					*/
/* which takes only one cycle             							*/
/********************************************************************/
/* PreProcessor Guard */
#ifndef DELAY_INTERFACE_H_
#define DELAY_INTERFACE_H_

/*
 * Description: Function to make delay in millisecond using NOP assembly instruction
 * Inputs: the required delay in millisecond
 * Output: void
 */
void delay_milliSecond (u32 Copy_u32MilliTime);

#endif /* DELAY_INTERFACE_H_ */

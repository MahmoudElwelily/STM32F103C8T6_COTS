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
#ifndef DELAY_H_INTERFACE_
#define DELAY_H_INTERFACE_

/*
 * Description: Function to make delay in millisecond using NOP assembly instruction
 * Inputs: the required delay in millisecond
 * Output: void
 */
void DELAY_vMilliSecond (u32 Copy_u32MilliTime);

#endif /* DELAY_H_ */

/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                                        */
/* Date: 06-Mar-19                                            */
/* Version: 01                                            */
/* Description: Interface file for SYSTICK Driver    */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef SYSTICK_INTERFACE_H 
#define SYSTICK_INTERFACE_H 

/*
 * Description: Function to set the initialized configuration in the SysTick control and status register (STK_CTRL)
 * Inputs: none
 * Output: the Error state of the function
 */
void SysTick_Init(void);

/*
 * Description: Function to make delay in millisecond using the SYSTICK timer
 * Inputs: the required delay as a multiple of 10ms (n*10ms)
 * Output: void
 */
void SysTick_Wait10ms(u32 Copy_u32Delay);

/*
 * Description: Function to make delay in nanosecond using the SYSTICK timer
 * Inputs: the required delay as a multiple of 10ns (n*10ns)
 * Output: void
 */
void SysTick_Wait10us(u32 Copy_u32Delay);

#endif /* SYSTICK_INTERFACE_H */ 

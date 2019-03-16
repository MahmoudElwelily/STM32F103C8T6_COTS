/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* private file for using Delay functions (in milliseconds) 		*/
/* in AVR ATmega32 using NOP assembly instruction 					*/
/* which takes only one cycle             							*/
/********************************************************************/


/* PreProcessor Guard */
#ifndef DELAY_PRIV_H_
#define DELAY_PRIV_H_

/* Macro for the time of context switching (to the function) */
#define DELAY_u32_T1        3
/* Macro for the time of context switching (return from the function) */
#define DELAY_u32_T2        2
/* Macro for the time of the required arithmetic operations needed to make the delay */
#define DELAY_u32_T3        88

/* Variable to be adjusted to control the 1 milli loop 											 */
#define MAX_TO_1m            590

/* This Value is for converting the milli to micro value  										 */
#define Milli2Micro         1000
/*Macro for the time of the time of a single for loop with a single NOP instruction within it*/
#define DELAY_u32_LOOPTIME  1000

#endif /* DELAY_PRIV_H_ */

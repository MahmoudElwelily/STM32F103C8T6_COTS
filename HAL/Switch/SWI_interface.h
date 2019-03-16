/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Interface file for Switch driver							        */
/*                                                                  */
/*                                                                  */
/********************************************************************/

/* Preprocessor Guard */
#ifndef SWI_INTERFACE_H_
#define SWI_INTERFACE_H_

/*Macros for numbering the switches*/
#define SWI_u8_SWI0     (u8)0
#define SWI_u8_SWI1     (u8)1
#define SWI_u8_SWI2     (u8)2

/*Macros for checking the switch states */
#define SWI_u8_PRESSED 1
#define SWI_u8_RELEASED 0

/*
 * Description: Function to get the state of switch whether it is released or pressed
 * Inputs: the switch ID according to the config file and the container variable which will hold the state of this switch
 * Output: the Error state of the function
 */
u8 SWI_u8GetSwitchState (u8 Copy_u8SwitchNb, u8 *Copy_u8SwiState);

#endif /* SWI_INTERFACE_H_ */

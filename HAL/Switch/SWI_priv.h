/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Private file for Switch driver							        */
/*                                                                  */
/*                                                                  */
/********************************************************************/

/* Preprocessor Guard */
#ifndef SWI_PRIV_H_
#define SWI_PRIV_H_

/*Private macro in case of switch connected to pull up resistor*/
#define SWI_u8_PULL_UP    (u8)1

/*Private macro in case of switch connected to pull down resistor*/
#define SWI_u8_PULL_DOWN  (u8)0

/*Private macro for checking the input voltage applied on the led */
#define SWI_u8_INPUT_HIGH 1
#define SWI_u8_INPUT_LOW  0

#endif /* SWI_PRIV_H_ */

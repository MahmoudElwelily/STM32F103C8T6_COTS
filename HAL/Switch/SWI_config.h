/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Configuration file for Switch driver						        */
/*                                                                  */
/*                                                                  */
/********************************************************************/

/* Preprocessor Guard */
#ifndef SWI_CONFIG_H_
#define SWI_CONFIG_H_

/*macro for determining the number of used switches in the system*/
#define SWI_u8_NO_OF_SWI 1

/*
 * macro for determining the type of each switch
 * Range: SWI_u8_PULL_UP
 * 		  SWI_u8_PULL_DOWN
 */
#define SWI_u8_1_TYPE  SWI_u8_PULL_DOWN

/*Array for determining the pins connected to each used switch*/
u8 SWI_Au8SwCh[SWI_u8_NO_OF_SWI] = {DIO_u8_PIN31};

/*Array to collect the type of each used switch*/
u8 SWI_Au8SwSt[SWI_u8_NO_OF_SWI] = {SWI_u8_1_TYPE};

#endif /* SWI_CONFIG_H_ */

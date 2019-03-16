/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V03                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Private header file for using DIO peripheral in STM32F103        */
/* It is included by interface.c and it is completely hidden from   */
/* any file in the HAL                                                  */
/********************************************************************/
/* PreProcessor Guard */
#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_

/*=========================================================== */
/* Macros for pins initialized states in case the pin is output */
#define DIO_u8_INIT_HIGH 1
#define DIO_u8_INIT_LOW  0
/*============================================================ */
/* Macro for maximum number of available ports */
#define DIO_u8MAXPortNB (u8)4

/*Macro to define input pull up and down mode*/
#define DIO_u8_INPUT_PULL_UP_DOWN         0b1000

/* Macro for number of pins in a single port */
#define DIO_u8NUMBER_OF_PINS_IN_PORT (u8)16
/**********************************************************/
/* STM32F103 DIO registers */
typedef struct
{
	Register_32Bit CRL;
	Register_32Bit CRH;
	Register_32Bit IDR;
	Register_32Bit ODR;
	Register_32Bit BSRR;
	Register_32Bit BRR;
	Register_32Bit LCKR;
}GPIO;

/*For PORTA*/
#define  DIO_GPIOA    ((GPIO*)0x40010800)
/*For PORTB*/
#define  DIO_GPIOB    ((GPIO*)0x40010C00)
/*For PORTC*/
#define  DIO_GPIOC    ((GPIO*)0x40011000)
/*For PORTD*/
#define  DIO_GPIOD    ((GPIO*)0x40011400)

GPIO *GPIO_AGPIOPorts[DIO_u8MAXPortNB] = {DIO_GPIOA,DIO_GPIOB,DIO_GPIOC,DIO_GPIOD};

#endif /* DIO_PRIV_H_ */





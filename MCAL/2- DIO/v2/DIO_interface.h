/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V02                                                   */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using DIO peripheral in STM32F103                */
/********************************************************************/

/* PreProcessor Guard */
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Direction and Modes Macros for the DIO pins */
#define DIO_u8_INPUT_ANALOG                       0b0000
#define DIO_u8_INPUT_FLOATING                     0b0100
#define DIO_u8_INPUT_PULL_UP                      0b1000
#define DIO_u8_INPUT_PULL_DOWN                    0b1100

#define DIO_u8_OUPUT_10M_PUSHPULL				  0b0001
#define DIO_u8_OUPUT_10M_OPENDRAIN			      0b0101
#define DIO_u8_OUPUT_10M_ALTFUN_PUSHPULL          0b1001
#define DIO_u8_OUPUT_10M_ALTFUN_OPENDRAIN         0b1101

#define DIO_u8_OUPUT_2M_PUSHPULL                  0b0010
#define DIO_u8_OUPUT_2M_OPENDRAIN				  0b0110
#define DIO_u8_OUPUT_2M_ALTFUN_PUSHPULL           0b1010
#define DIO_u8_OUPUT_2M_ALTFUN_OPENDRAIN          0b1110

#define DIO_u8_OUPUT_50M_PUSHPULL				  0b0011
#define DIO_u8_OUPUT_50M_OPENDRAIN		          0b0111
#define DIO_u8_OUPUT_50M_ALTFUN_PUSHPULL	      0b1011
#define DIO_u8_OUPUT_50M_ALTFUN_OPENDRAIN         0b1111

/* Macros for ports mapping */
#define DIO_u8_PORT_A     (u8)0
#define DIO_u8_PORT_B     (u8)1
#define DIO_u8_PORT_C     (u8)2
#define DIO_u8_PORT_D     (u8)3

/* Assignment Macros for pins */
#define DIO_u8_PIN_HIGH   (u8)1
#define DIO_u8_PIN_LOW    (u8)0

/* DIO Pins Macros */
#define DIO_u8_PIN0       (u8)0 	/*PINA0*/
#define DIO_u8_PIN1       (u8)1    	/*PINA1*/
#define DIO_u8_PIN2       (u8)2    	/*PINA2*/
#define DIO_u8_PIN3       (u8)3    	/*PINA3*/
#define DIO_u8_PIN4       (u8)4	    /*PINA4*/
#define DIO_u8_PIN5       (u8)5   	/*PINA5*/
#define DIO_u8_PIN6       (u8)6		/*PINA6*/
#define DIO_u8_PIN7       (u8)7		/*PINA7*/
#define DIO_u8_PIN8 	  (u8)8		/*PINA8*/
#define DIO_u8_PIN9	      (u8)9		/*PINA9*/
#define DIO_u8_PIN10	  (u8)10	/*PINA10*/
#define DIO_u8_PIN11	  (u8)11	/*PINA11*/
#define DIO_u8_PIN12	  (u8)12	/*PINA12*/
#define DIO_u8_PIN13	  (u8)13	/*PINA13*/
#define DIO_u8_PIN14	  (u8)14	/*PINA14*/
#define DIO_u8_PIN15	  (u8)15	/*PINA15*/

#define DIO_u8_PIN16	  (u8)16	/*PINB0*/
#define DIO_u8_PIN17	  (u8)17	/*PINB1*/
#define DIO_u8_PIN18	  (u8)18	/*PINB2*/
#define DIO_u8_PIN19	  (u8)19	/*PINB3*/
#define DIO_u8_PIN20	  (u8)20	/*PINB4*/
#define DIO_u8_PIN21	  (u8)21	/*PINB5*/
#define DIO_u8_PIN22	  (u8)22	/*PINB6*/
#define DIO_u8_PIN23	  (u8)23	/*PINB7*/
#define DIO_u8_PIN24	  (u8)24	/*PINB8*/
#define DIO_u8_PIN25	  (u8)25	/*PINB9*/
#define DIO_u8_PIN26	  (u8)26	/*PINB10*/
#define DIO_u8_PIN27	  (u8)27	/*PINB11*/
#define DIO_u8_PIN28	  (u8)28	/*PINB12*/
#define DIO_u8_PIN29	  (u8)29	/*PINB13*/
#define DIO_u8_PIN30	  (u8)30	/*PINB14*/
#define DIO_u8_PIN31	  (u8)31	/*PINB15*/

#define DIO_u8_PIN32	  (u8)45	/*PINC13*/
#define DIO_u8_PIN33	  (u8)46	/*PINC14*/
#define DIO_u8_PIN34	  (u8)47	/*PINC15*/

#define DIO_u8_PIN35	  (u8)48	/*PIND0*/
#define DIO_u8_PIN36	  (u8)49	/*PIND1*/

/*
 * Description: Function to set the initialized direction and value of each pin in all ports
 * Inputs: none
 * Output: void
 */
void DIO_vInit (void);

/*
 * Description: Function to set the direction of a specific pin in a specified port
 * Inputs: the pin number , the pin direction
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinDirection (u8 Copy_u8PinNb,u8 Copy_u8Mode);

/*
 * Description: Function to set a specific pin in a specified port with a specified value (INPUT = 0,OUTPUT = 1)
 * Inputs: the pin number , the pin value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPinValue (u8 Copy_u8PinNb, u8 Copy_u8Value);

/*
 * Description: Function to get the value of a certain input pin in a specified port
 * Inputs: the pin number , the container variable which will hold the value on this pin
 * output: the Error state of the function
 */
u8 DIO_u8GetPinValue (u8 Copy_u8PinNb,u8 *Copy_Pu8PinValue);

/*
 * Description: Function to set pins of a specified port with a specified value
 * Inputs: the port number , the port value
 * Output: the Error state of the function
 */
u8 DIO_u8SetPortValue (u8 Copy_u8PortNb,u8 Copy_u8Value);

/*
 * Description: Function to get the value of a specified port
 * Inputs: the port number , the container variable which will hold the value on this port
 * output: the Error state of the function
 */
u8 DIO_u8GetPortValue (u8 Copy_u8PortNb, u8 *Copy_Pu8PortValue);

#endif /* DIO_INTERFACE_H_ */

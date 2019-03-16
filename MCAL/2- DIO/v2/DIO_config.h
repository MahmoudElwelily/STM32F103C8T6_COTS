/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V02                                                    */
/********************************************************************/
/* Description                                                      */
/* ------------                                                     */
/* Header file for using DIO peripheral in STM32F103                */
/********************************************************************/

/* Preprocessor Guard */
#ifndef CONFIG_H_
#define CONFIG_H_

/*
  Initial direction for DIO Pins
  Range: DIO_u8_INPUT_ANALOG
         DIO_u8_INPUT_FLOATING
         DIO_u8_INPUT_PULL_UP_DOWN_DOWN

         DIO_u8_OUPUT_10M_PUSHPULL
         DIO_u8_OUPUT_10M_OPENDRAIN
         DIO_u8_OUPUT_10M_ALTFUN_PUSHPULL
         DIO_u8_OUPUT_10M_ALTFUN_OPENDRAIN

         DIO_u8_OUPUT_2M_PUSHPULL
         DIO_u8_OUPUT_2M_OPENDRAIN
         DIO_u8_OUPUT_2M_ALTFUN_PUSHPULL
         DIO_u8_OUPUT_2M_ALTFUN_OPENDRAIN

         DIO_u8_OUPUT_50M_PUSHPULL
         DIO_u8_OUPUT_50M_OPENDRAIN
         DIO_u8_OUPUT_50M_ALTFUN_PUSHPULL
         DIO_u8_OUPUT_50M_ALTFUN_OPENDRAIN
*/
#define DIO_u8_PIN0_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA0*/
#define DIO_u8_PIN1_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA1*/
#define DIO_u8_PIN2_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA2*/
#define DIO_u8_PIN3_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA3*/
#define DIO_u8_PIN4_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN	   /*PINA4*/
#define DIO_u8_PIN5_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA5*/
#define DIO_u8_PIN6_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA6*/
#define DIO_u8_PIN7_INIT_MODE    DIO_u8_INPUT_PULL_UP_DOWN     /*PINA7*/
#define DIO_u8_PIN8_INIT_MODE	   DIO_u8_INPUT_PULL_UP_DOWN     /*PINA8*/
#define DIO_u8_PIN9_INIT_MODE	   DIO_u8_INPUT_PULL_UP_DOWN     /*PINA9*/
#define DIO_u8_PIN10_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINA10*/
#define DIO_u8_PIN11_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINA11*/
#define DIO_u8_PIN12_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINA12*/
#define DIO_u8_PIN13_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINA13*/
#define DIO_u8_PIN14_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINA14*/
#define DIO_u8_PIN15_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINA15*/

#define DIO_u8_PIN16_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB0*/
#define DIO_u8_PIN17_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB1*/
#define DIO_u8_PIN18_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB2*/
#define DIO_u8_PIN19_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB3*/
#define DIO_u8_PIN20_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB4*/
#define DIO_u8_PIN21_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB5*/
#define DIO_u8_PIN22_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB6*/
#define DIO_u8_PIN23_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB7*/
#define DIO_u8_PIN24_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB8*/
#define DIO_u8_PIN25_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB9*/
#define DIO_u8_PIN26_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB10*/
#define DIO_u8_PIN27_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB11*/
#define DIO_u8_PIN28_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB12*/
#define DIO_u8_PIN29_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB13*/
#define DIO_u8_PIN30_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB14*/
#define DIO_u8_PIN31_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PINB15*/

#define DIO_u8_PIN32_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINC13*/
#define DIO_u8_PIN33_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINC14*/
#define DIO_u8_PIN34_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PINC15*/

#define DIO_u8_PIN35_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN     /*PIND0*/
#define DIO_u8_PIN36_INIT_MODE	 DIO_u8_INPUT_PULL_UP_DOWN	   /*PIND1*/

/*
   Macros of initialized state for DIO Pins
   Range : DIO_u8_INIT_HIGH
	       DIO_u8_INIT_LOW
*/
#define DIO_u8_PIN0_INIT_STATE     DIO_u8_INIT_LOW    	/*PINA0*/
#define DIO_u8_PIN1_INIT_STATE     DIO_u8_INIT_LOW    	/*PINA1*/
#define DIO_u8_PIN2_INIT_STATE     DIO_u8_INIT_LOW    	/*PINA2*/
#define DIO_u8_PIN3_INIT_STATE     DIO_u8_INIT_LOW    	/*PINA3*/
#define DIO_u8_PIN4_INIT_STATE     DIO_u8_INIT_LOW	    /*PINA4*/
#define DIO_u8_PIN5_INIT_STATE     DIO_u8_INIT_LOW    	/*PINA5*/
#define DIO_u8_PIN6_INIT_STATE     DIO_u8_INIT_LOW		/*PINA6*/
#define DIO_u8_PIN7_INIT_STATE     DIO_u8_INIT_LOW		/*PINA7*/
#define DIO_u8_PIN8_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA8*/
#define DIO_u8_PIN9_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA9*/
#define DIO_u8_PIN10_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA10*/
#define DIO_u8_PIN11_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA11*/
#define DIO_u8_PIN12_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA12*/
#define DIO_u8_PIN13_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA13*/
#define DIO_u8_PIN14_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA14*/
#define DIO_u8_PIN15_INIT_STATE	   DIO_u8_INIT_LOW		/*PINA15*/

#define DIO_u8_PIN16_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB0*/
#define DIO_u8_PIN17_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB1*/
#define DIO_u8_PIN18_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB2*/
#define DIO_u8_PIN19_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB3*/
#define DIO_u8_PIN20_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB4*/
#define DIO_u8_PIN21_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB5*/
#define DIO_u8_PIN22_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB6*/
#define DIO_u8_PIN23_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB7*/
#define DIO_u8_PIN24_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB8*/
#define DIO_u8_PIN25_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB9*/
#define DIO_u8_PIN26_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB10*/
#define DIO_u8_PIN27_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB11*/
#define DIO_u8_PIN28_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB12*/
#define DIO_u8_PIN29_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB13*/
#define DIO_u8_PIN30_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB14*/
#define DIO_u8_PIN31_INIT_STATE	   DIO_u8_INIT_LOW		/*PINB15*/

#define DIO_u8_PIN32_INIT_STATE	   DIO_u8_INIT_LOW		/*PINC13*/
#define DIO_u8_PIN33_INIT_STATE	   DIO_u8_INIT_LOW		/*PINC14*/
#define DIO_u8_PIN34_INIT_STATE	   DIO_u8_INIT_LOW		/*PINC15*/

#define DIO_u8_PIN35_INIT_STATE	   DIO_u8_INIT_LOW		/*PIND0*/
#define DIO_u8_PIN36_INIT_STATE	   DIO_u8_INIT_LOW		/*PIND1*/

#endif /* CONFIG_H_ */

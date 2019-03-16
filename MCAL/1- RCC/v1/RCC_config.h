/******************************************************************/
/* Author: Mahmoud Alaa Elwelily                            	  */
/* Date: 24-Feb-19                                                */
/* Version: 02                                                    */
/* Description: Configuration file for RCC Driver  in STM32F103   */
/******************************************************************/

/*Preprocessor Guard*/
#ifndef RCC_CONFIG_H 
#define RCC_CONFIG_H 

/*
*  Initial configuration of the System Clock
*  Range: RCC_u8_HSI
* 		  RCC_u8_HSE
* 		  RCC_u8_PLL
*/
#define RCC_u8_SYS_CLOCK      RCC_u8_HSI


/*
* Initial states of the different clocks
*     Range: RCC_u8_ENABLE
* 	    	   RCC_u8_DISABLE
*/
#define RCC_u8_HSI_STATE 	  RCC_u8_ENABLE
#define RCC_u8_HSE_STATE    RCC_u8_DISABLE
#define RCC_u8_PLL_STATE    RCC_u8_DISABLE

/********************Macros configured in case of using PLL as the system clock****************************************/

/*
 * Macro to determine if the PLL input clock will be divided by 2 or not
 * (in case you are choosing HSE as the input clock for PLL)
 * Range: RCC_u8_HSE_DIVIDED_BY_2
 *        RCC_u8_HSE_NOT_DIVIDED
*/
#define RCC_u8_PLLXTPRE        RCC_u8_HSE_NOT_DIVIDED

/*
*  Macro to determine the PLL entry source (in case PLL is chosen as the system clock)
*  Range: RCC_u8_HSI_DIVIDED_BY_2
* 		  RCC_u8_HSE_CLK_SOURCE
*/
#define RCC_u8_PLLSRC           RCC_u8_HSI_DIVIDED_BY_2

/*
 * Macro to determine the PLL multiplication factor
*  Range:   RCC_u8_PLL_MULTIPLED_BY_2
*  			RCC_u8_PLL_MULTIPLED_BY_3
*  			RCC_u8_PLL_MULTIPLED_BY_4
* 		    RCC_u8_PLL_MULTIPLED_BY_5
* 		    RCC_u8_PLL_MULTIPLED_BY_6
* 		    RCC_u8_PLL_MULTIPLED_BY_7
* 		    RCC_u8_PLL_MULTIPLED_BY_8
* 		    RCC_u8_PLL_MULTIPLED_BY_9
* 		    RCC_u8_PLL_MULTIPLED_BY_10
* 		    RCC_u8_PLL_MULTIPLED_BY_11
* 		    RCC_u8_PLL_MULTIPLED_BY_12
* 		    RCC_u8_PLL_MULTIPLED_BY_13
* 		    RCC_u8_PLL_MULTIPLED_BY_14
* 		    RCC_u8_PLL_MULTIPLED_BY_15
* 		    RCC_u8_PLL_MULTIPLED_BY_16
*/
#define RCC_u8_PLLMUL        RCC_u8_PLL_MULTIPLED_BY_4

/************************************************************************************************************************/
/*
*  Initial configuration of AHB prescaler
*  Range: RCC_u8_NOT_DIVIDED
* 		    RCC_u8_DIVIDED_BY_2
* 		    RCC_u8_DIVIDED_BY_4
* 		    RCC_u8_DIVIDED_BY_8
* 		    RCC_u8_DIVIDED_BY_16
* 		    RCC_u8_DIVIDED_BY_64
* 		    RCC_u8_DIVIDED_BY_128
* 		    RCC_u8_DIVIDED_BY_256
* 		    RCC_u8_DIVIDED_BY_512
*/
#define RCC_u8_AHB_PRESCALER  RCC_u8_NOT_DIVIDED

/*
*  Initial configuration of APB1 prescaler
*  Range: RCC_u8_NOT_DIVIDED
* 		    RCC_u8_DIVIDED_BY_2
* 		    RCC_u8_DIVIDED_BY_4
* 		    RCC_u8_DIVIDED_BY_8
* 		    RCC_u8_DIVIDED_BY_16
*/
#define RCC_u8_APB1_PRESCALER  RCC_u8_NOT_DIVIDED

/*
*  Initial configuration of APB2 prescaler
*  Range: RCC_u8_NOT_DIVIDED
* 		    RCC_u8_DIVIDED_BY_2
* 		    RCC_u8_DIVIDED_BY_4
* 		    RCC_u8_DIVIDED_BY_8
* 		    RCC_u8_DIVIDED_BY_16
*/
#define RCC_u8_APB2_PRESCALER  RCC_u8_NOT_DIVIDED

#endif /* RCC_CONFIG_H */ 


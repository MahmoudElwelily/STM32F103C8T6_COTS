/************************************************************/
/* Author: Mahmoud Alaa Elwelily                            */
/* Date: 24-Feb-19                                          */
/* Version: 02                                              */
/* Description: Interface file for RCC Driver in STM32F103  */
/************************************************************/

/*Preprocessor Guard*/
#ifndef RCC_INTERFACE_H 
#define RCC_INTERFACE_H 

/*Macros for APB2 peripherals*/
#define RCC_u8_USART1            (u8)1
#define RCC_u8_SPI1              (u8)2
#define RCC_u8_TIM1              (u8)3
#define RCC_u8_ADC2              (u8)4
#define RCC_u8_ADC1              (u8)5
#define RCC_u8_IOPD              (u8)6
#define RCC_u8_IOPC              (u8)7
#define RCC_u8_IOPB              (u8)8
#define RCC_u8_IOPA              (u8)9
#define RCC_u8_AFIO              (u8)10

/*Macros for APB1 peripherals*/
#define RCC_u8_DAC            (u8)11
#define RCC_u8_PWR            (u8)12
#define RCC_u8_BKP            (u8)13
#define RCC_u8_CAN2           (u8)14
#define RCC_u8_CAN1           (u8)15
#define RCC_u8_I2C2           (u8)16
#define RCC_u8_I2C1           (u8)17
#define RCC_u8_USART5         (u8)18
#define RCC_u8_USART4         (u8)19
#define RCC_u8_USART3         (u8)20
#define RCC_u8_USART2         (u8)21
#define RCC_u8_SPI3           (u8)22
#define RCC_u8_SPI2           (u8)23
#define RCC_u8_WWDG           (u8)24
#define RCC_u8_TIM7           (u8)25
#define RCC_u8_TIM6           (u8)26
#define RCC_u8_TIM5           (u8)27
#define RCC_u8_TIM4           (u8)28
#define RCC_u8_TIM3           (u8)29
#define RCC_u8_TIM2           (u8)30

/*Macros for AHB peripherals*/
#define RCC_u8_OTGFS          (u8)31
#define RCC_u8_CRC            (u8)32
#define RCC_u8_SRAM           (u8)33
#define RCC_u8_DMA2           (u8)34
#define RCC_u8_DMA1           (u8)35

/*Macros for the peripheral probable states (Enabled/Disabled)*/
#define RCC_u8_PERI_ENABLE      (u8)0
#define RCC_u8_PERI_DISABLE     (u8)1

/*
 * Description: Function to initialize Clock source and state (with prescaler or not)
 * Inputs: none
 * Output: void
 */
void RCC_vInit (void);

/*
 * Description: Function to set the state of any peripheral (Enable/disable)
 * Inputs: the peripheral name
 * Output: Error state
 */
u8 RCC_vEnablePeripheralClock (u8 Copy_u8PeriName);

/*
 * Description: Function to set the state of any peripheral (Enable/disable)
 * Inputs: the peripheral name
 * Output: Error state
 */
u8 RCC_vDisablePeripheralClock (u8 Copy_u8PeriName);

#endif /* RCC_INTERFACE_H */ 

/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                   								    */
/* Description: private file for Seven Segment display              */
/********************************************************************/

/* PreProcessor Guard */
#ifndef SSD_PRIV_H_
#define SSD_PRIV_H_

/*Macro for the max digit can be displayed on the SSD*/
#define SSD_u8_MAX_DIGIT_FOR_SSD (u8)9

/*Macro for number of segments in a single SSD*/
#define SSD_u8_NO_OF_SEG         (u8)7

/*Macros for SSD types*/
#define SSD_u8_COMMON_ANODE      (u8)0
#define SSD_u8_COMMON_CATHODE    (u8)1

u8 SSD_Au8SEG_PATTERN_CATHODE[10][7] = {
/*    a                   b               c              d                   e               f                g              */
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW},    // 0
  {DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_LOW , DIO_u8_PIN_LOW , DIO_u8_PIN_LOW},    // 1
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH},   // 2
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH},   // 3
  {DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH},   // 4
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH},   // 5
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH},   // 6
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW , DIO_u8_PIN_LOW , DIO_u8_PIN_LOW , DIO_u8_PIN_LOW},    // 7
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH},   // 8
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH,DIO_u8_PIN_HIGH , DIO_u8_PIN_LOW , DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH}    // 9
};

u8 SSD_Au8SEG_PATTERN_ANODE[10][7] = {
/*    a                   b               c              d                   e               f                g              */
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH},    // 0
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH},    // 1
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW},     // 2
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW},     // 3
  {DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW},     // 4
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW},     // 5
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW},     // 6
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH, DIO_u8_PIN_HIGH},    // 7
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW},     // 8
  {DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW,  DIO_u8_PIN_HIGH, DIO_u8_PIN_LOW,  DIO_u8_PIN_LOW}      // 9
};

/*Macros for identifying the init flag*/
#define SSD_u8_SSD_INIT_FLAG_ZERO (u8)0
#define SSD_u8_SSD_INIT_FLAG_ONE  (u8)1


/*Macro for identifying the SetOff flag*/
#define SSD_u8_SSD_SET_OFF_FLAG_OFF (u8)0
#define SSD_u8_SSD_SET_OFF_FLAG_ON  (u8)1

/*Macro for identifying the init value of the last digit on each connected SSD*/
#define SSD_u8_SSD_LAST_DIG_INIT_VAL (u8)0

/*Macro for the for loop starting from 0*/
#define SSD_u8_INIT_ITER (u8)0
#endif /* SSD_PRIV_H_ */

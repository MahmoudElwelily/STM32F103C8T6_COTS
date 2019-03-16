/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: private file for LMD interface                      */
/********************************************************************/

/*PreProccessor Guard*/
#ifndef LMD_PRIV_H_
#define LMD_PRIV_H_

/*Private macros for the determining  the active port*/
#define LMD_u8_ACTIVE_ROW	    (u8)0
#define LMD_u8_ACTIVE_COLUMN    (u8)1

/*Private macros for the activity type of the actove port */
#define LMD_u8_ACTIVE_LOW       (u8)0
#define LMD_u8_ACTIVE_HIGH      (u8)1

/*macro for number of leds within one column or row*/
#define LMD_u8_SIZE    (u8)8

/*Array holding the active port assignment (in case of active high)*/
u8 LMD_Au8ActivePort[LMD_u8_SIZE] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80};

#endif /* LMD_PRIV_H_ */

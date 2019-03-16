/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 5 Feb 2019                                             */
/* Version : V01                                                    */
/* Description: header file for LMD interface                       */
/********************************************************************/

/*PreProccessor Guard*/
#ifndef LMD_H_INTERFACE_
#define LMD_H_INTERFACE_

/*Macro for determining the color you want to display on the LMD*/
#define LMD_u8_RED        (u8)0
#define LMD_u8_GREEN      (u8)1

u8 LMD_u8Display (u8 *Copy_Pu8Image,u8 Copy_u8Color);

#endif /* LMD_H_INTERFACE_ */

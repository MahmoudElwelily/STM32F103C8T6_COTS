/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/* Description: This header file is dedicated for defining fixed    */
/* size data types which are required to be used                    */
/* Embedded System development.                                     */                               
/********************************************************************/

/*
This header file is dedicated for defining fixed size data types which are realable to be used
Embedded System development.
*/

#ifndef STD_TYPES
#define STD_TYPES

/* unsigned 8 bit type */
typedef unsigned char      u8   ;

/* signed 8 bit type */
typedef signed char        s8   ;

/* unsigned 16 bit type */
typedef unsigned short int u16  ;

/* signed 16 bit type */
typedef signed short int   s16  ;

/* unsigned 32 bit type */
typedef unsigned long int  u32  ;

/* signed 32 bit type */
typedef signed long int    s32  ;

/* floating type 32 bit */
typedef float              f32  ;

/* floating type 64 bit */
typedef double             f64  ;

/* Register 32 bits */
typedef union {
	struct
	{
		u8 Bit0 : 1;
		u8 Bit1 : 1;
		u8 Bit2 : 1;
		u8 Bit3 : 1;
		u8 Bit4 : 1;
		u8 Bit5 : 1;
		u8 Bit6 : 1;
		u8 Bit7 : 1;
		u8 Bit8 : 1;
		u8 Bit9 : 1;
		u8 Bit10 : 1;
		u8 Bit11 : 1;
		u8 Bit12 : 1;
		u8 Bit13 : 1;
		u8 Bit14 : 1;
		u8 Bit15 : 1;
		u8 Bit16 : 1;
		u8 Bit17 : 1;
		u8 Bit18 : 1;
		u8 Bit19 : 1;
		u8 Bit20 : 1;
		u8 Bit21 : 1;
		u8 Bit22 : 1;
		u8 Bit23 : 1;
		u8 Bit24 : 1;
		u8 Bit25 : 1;
		u8 Bit26 : 1;
		u8 Bit27 : 1;
		u8 Bit28 : 1;
		u8 Bit29 : 1;
		u8 Bit30 : 1;
		u8 Bit31 : 1;
	}BitAccess;
	u32 WordAccess;
} Register_32Bit;

/* Error status */
#define ERROR_NOK (u8)1
#define ERROR_OK  (u8)0

/* Macro for NULL */
#define NULL ((void*)0)
#define ZERO 0

#endif

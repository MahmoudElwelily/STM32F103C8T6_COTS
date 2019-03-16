/********************************************************************/
/* Author  : Mahmoud Alaa Elwelily                                  */
/* Date    : 29 Jan 2019                                            */
/* Version : V01                                                    */
/********************************************************************/
/* Preprocessor Guard */
#ifndef BIT_CALC_H
#define BIT_CALC_H

/* 
Macro definition to set a specific bit in a variable
Input: (1) the variable itself (2) the bit number of the variable needed to be set
*/
#define SET_BIT(var,bit_no)      ((var)|=(1<<(bit_no)))
//========================================================
//Another method with lower clock cycle (it takes about 3 Cycles here)
#define BITSET0 0b00000001
#define BITSET1 0b00000010
#define BITSET2 0b00000100
#define BITSET3 0b00001000

#define BITSET4 0b00010000
#define BITSET5 0b00100000
#define BITSET6 0b01000000
#define BITSET7 0b10000000

#define SET(bit_no)  BITSET##bit_no    
#define SET_BITT(var,bit_no)      ((var)|=SET(bit_no))
//=============================================================================

/* 
Macro definition to clear a specific bit in a variable
Input: (1) the variable itself (2) the bit number of the variable needed to be cleared
*/
#define CLEAR_BIT(var,bit_no)    ((var)&=~(1<<(bit_no)))
//========================================================
//Another method with lower clock cycle (it takes about 3 Cycles here)
#define BITCLEAR0 0b11111110
#define BITCLEAR1 0b11111101
#define BITCLEAR2 0b11111011
#define BITCLEAR3 0b11110111

#define BITCLEAR4 0b11101111
#define BITCLEAR5 0b11011111
#define BITCLEAR6 0b10111111
#define BITCLEAR7 0b01111111

#define CLEAR(bit_no)  BITCLEAR##bit_no    
#define CLEAR_BITT(var,bit_no)      ((var)&=CLEAR(bit_no))
//===============================================================================

/* 
Macro definition to toggle a specific bit in a variable
Inputs: (1) the variable itself (2) the bit number of the variable needed to be toggled
*/
#define TOGGLE_BIT(var,bit_no)   ((var)^=(1<<(bit_no)))
//========================================================
//Another method with lower clock cycle (it takes about 3 Cycles here)
#define BITTOGGLE0 0b00000001
#define BITTOGGLE1 0b00000010
#define BITTOGGLE2 0b00000100
#define BITTOGGLE3 0b00001000

#define BITTOGGLE4 0b00010000
#define BITTOGGLE5 0b00100000
#define BITTOGGLE6 0b01000000
#define BITTOGGLE7 0b10000000

#define TOGGLE(bit_no)  BITTOGGLE##bit_no    
#define TOGGLE_BITT(var,bit_no)      ((var)^=TOGGLE(bit_no))
//=================================================================================

/* 
Macro definition to assign a specific bit in a variable with a specific value entered as a parameter to the function like macro
Inputs: (1) the variable itself (2) the bit number of the variable needed to be Assigned (3) the value should be assigned to the bit
(it takes about 3 Cycles here in the worst condition)
*/
#define ASSIGN_BIT(var,bit_no,value)   if(value) SET_BIT(var,bit_no); else CLEAR_BIT(var,bit_no)

/* 
Macro definition to get the state of a specific bit in a variable 
Inputs: (1) the variable itself (2) the bit number of the variable we need to get its state
*/
#define GET_BIT(var,bit_no)         (((var) >> (bit_no)) & 0x01)

/* 
Macro definition to assign the 8 bit variable with a certain value
Inputs: the variable itself 
*/
#define ASSIGN_BITS(var,value) 	 	((var) = (value))

/*
Macro definition to set the high nibble of a variable
Inputs: the variable itself
*/
#define HIGH_NIBBLE_SET    0xF0
#define SET_HIGH_NIBBLE(var) 	 	((var)|= HIGH_NIBBLE_SET)

/*
Macro definition to shift a nibble with a certain value along the register
Inputs: the register (variable) you want to add this in + the number of nibble movement needed to shift this nibble
        + the value of the nibble required to add
*/
#define ASSIGN_NIBBLE(Reg,NibbleNo,value)    Reg=((Reg)&(~(0xF << (NibbleNo)*4))) | ((value) << ((NibbleNo)*4))
//(Reg=(((Reg)&(~(0xf<<((NibbleNo)*4))))|((value)<<((NibbleNo)*4))))

/*
Macro definition to set the low nibble of a variable 
Inputs: the variable itself 
*/
#define LOW_NIBBLE_SET   0x0F
#define SET_LOW_NIBBLE(var)   		((var)|= LOW_NIBBLE_SET)

/* 
Macro definition to clear the high nibble of a variable 
Inputs: the variable itself 
*/
#define HIGH_NIBBLE_CLEAR   0x0F  
#define CLEAR_HIGH_NIBBLE(var)		((var)&= HIGH_NIBBLE_CLEAR)

/* 
Macro definition to clear the low nibble of a variable 
Inputs: the variable itself 
*/
#define LOW_NIBBLE_CLEAR    0xF0 
#define CLEAR_LOW_NIBBLE(var)       ((var)&= LOW_NIBBLE_CLEAR)

/* 
Macro definition to toggle the high nibble of a variable 
Inputs: the variable itself 
*/
#define HIGH_NIBBLE_TOGGLE   0xF0
#define TOGGLE_HIGH_NIBBLE(var)     ((var)^= HIGH_NIBBLE_TOGGLE)

/* 
Macro definition to toggle the low nibble of a variable 
Inputs: the variable itself 
*/
#define LOW_NIBBLE_TOGGLE   0x0F
#define TOGGLE_LOW_NIBBLE(var)      ((var)^= LOW_NIBBLE_TOGGLE)

/*
Macro definition to assign the high nibble of a variable entered as a parameter to the function like macro
Inputs: (1) the variable itself (2) the value according to it the high nibble of the variable will be set or cleared
*/
#define ASSIGN_HIGH_NIBBLE(var,value)   if(value) SET_HIGH_NIBBLE(var); else CLEAR_HIGH_NIBBLE(var)

/*
Macro definition to assign the low nibble of a variable entered as a parameter to the function like macro
Inputs: (1) the variable itself (2) the value according to it the low nibble of the variable will be set or cleared
*/
#define ASSIGN_LOW_NIBBLE(var,value)   if(value) SET_LOW_NIBBLE(var); else CLEAR_LOW_NIBBLE(var)

/*
Macro definition to concatenate 8 bits
Inputs: 8 input bits in 0 or 1
*/
#define CONC_BITS(b0,b1,b2,b3,b4,b5,b6,b7)     CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)
#define CONC_HELPER(b0,b1,b2,b3,b4,b5,b6,b7)   0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif


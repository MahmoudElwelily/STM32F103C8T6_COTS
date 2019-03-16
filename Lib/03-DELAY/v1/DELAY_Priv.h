#ifndef DELAY_PRIV_
#define DELAY_PRIV_

/* Macro for the time of context switching (to the function) */
#define DELAY_u32_T1 (u32)5.141
/* Macro for the time of context switching (return from the function) */
#define DELAY_u32_T2 (u32)2
/* Macro for the time of the required arithmetic operations needed to make the delay */
#define DELAY_u32_T3 (u32)800

/*Macro for the time of the time of a single for loop with a single NOP instruction within it*/
#define DELAY_u32_LOOPTIME (u32)172

/*Macro need to be multiplied to the function argument to apply the arithmatic operations in microsecond scale*/
#define DELAY_u32_IN_MILLI (u32)1000

#endif /* DELAY_PRIV_ */
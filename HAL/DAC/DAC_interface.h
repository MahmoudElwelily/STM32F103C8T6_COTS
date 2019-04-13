/**********************************************************/
/* Author: Mahmoud Alaa Elwelily                          */
/* Date: 28-Mar-19                                        */
/* Version: 01                                            */
/* Description: Interface file for DAC Driver             */
/**********************************************************/

/*Preprocessor Guard*/
#ifndef DAC_INTERFACE_H 
#define DAC_INTERFACE_H 


/*
 * Description: Function to calculate the step value according to the configured resolution and the max voltage
 * Inputs: no input
 * Output: void
 */
void DAC_vInit (void);

/*
 * Description: Function to generate digital voltage on the DAC pins according to required analong voltage
 * Inputs: the required analog voltage
 * Output: void
 */
void DAC_vSetOuputVoltage (u16 Copy_u16Voltage);



#endif /* DAC_INTERFACE_H */ 

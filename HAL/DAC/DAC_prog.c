/**************************************************************/
/* Author: Mahmoud Alaa Elwelily                              */
/* Date: 28-Mar-19                                            */
/* Version: 01                                                */
/* Description: Program file for DAC Driver                   */
/**************************************************************/
#include "STD_TYPES.h" 
#include "BIT_CALC.h" 
#include "DIO_interface.h"
#include "DAC_interface.h" 
#include "DAC_priv.h" 
#include "DAC_config.h" 

static u8 DAC_u8Step;

/*
 * Description: Function to calculate the step value according to the configured resolution and the max voltage
 * Inputs: no input
 * Output: void
 */
void DAC_vInit (void)
{
	DAC_u8Step = DAC_u8_MAX_VOLTAGE/pow(2,DAC_u8_RESOLUTION);
	return;
}

/*
 * Description: Function to generate digital voltage on the DAC pins according to required analong voltage
 * Inputs: the required analog voltage (in mV)
 * Output: void
 */
void DAC_vSetOuputVoltage (u16 Copy_u16AnalogVoltage)
{
	u8 Local_u8Index;
	u32 Local_u32DigitalVoltage = Copy_u16AnalogVoltage/DAC_u8Step;

	for (Local_u8Index = UNSIGNED_MIN; Local_u8Index < DAC_u8_RESOLUTION; Local_u8Index++)
	{
		DIO_u8SetPinValue(DAC_Au8ConnectedPins[Local_u8Index],GET_BIT(Local_u32DigitalVoltage,Local_u8Index));
	}
}

/******************************************************************************************/
/*                               Static Functions                                         */

/*
Static function to make power calculation
Inputs: The base and the exponent
Outputs: The result
*/
static u32 pow (u8 Copy_u8Base,u8 Copy_u8Exponent)
{
    u8 Local_u8Index;
    u32 Local_u32Result = Copy_u8Base;
    for (Local_u8Index = UNSIGNED_MIN; Local_u8Index < Copy_u8Exponent-1;Local_u8Index++)
    {
    	Local_u32Result *=Copy_u8Base;
    }
    return Local_u32Result;
}

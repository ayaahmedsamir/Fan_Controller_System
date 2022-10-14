/******************************************************************************************
 * Module: ADC
 * description: Source file for ADC driver for AvR
 * file name:adc.c
 * Author: Aya Ahmed
 ****************************************************************************************/

#include"adc.h"
#include"avr/io.h" /* to use the AVR registers*/
#include"common_macros.h"/* to use macros like SET_BIT*/

/*************************************************************************
                      *function definitions *
 *************************************************************************/


/*Description:
 * function to initialize the ADC
 */
void ADC_Init(const ADC_ConfigType* Config_Ptr)
{
	/* Set ADMUX to zero at first
	 * to make MUX0:4 to zero (channel 0)
	 * and to clear the bits of the reference voltage at first
	 */
	ADMUX=0;
	/* set the reference voltage in the bits REFS0,REFS1 and make it
	 * configurable.
	 * shift left 6 because start from pin6 in register.
	 */
	ADMUX|=(Config_Ptr->ref_volt << 6);

	/* Enable the ADC
	 * Disable the interrupt
	 * set the prescaler in bits ADPS2:0 ,make it configurable
	 */
	ADCSRA=(1<<ADEN); /* clear the ADPS2:0 before the configuration*/
	ADCSRA|=(Config_Ptr->prescalar);
}


/* description:
 * function to read the analog value and return the digital value
 */

uint16 ADC_readChannel(uint8 channel_num)
{
	ADMUX &= 0xE0; /* clear the first five bits in ADMUX before set the required channel*/
	ADMUX|=channel_num; /* set the required channel to read*/
	ADCSRA|=(1<<ADSC); /* start conversion from analog to digital*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait until conversion completes*/
	SET_BIT(ADCSRA,ADIF); /*clear flag after conversion*/
	return ADC; /* read the digital value form data register*/
}


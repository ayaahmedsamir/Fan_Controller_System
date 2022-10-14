/**************************************************************************
 * Module: ADC
 *
 * file name: adc.h
 *
 * description: header file for ADC driver
 *
 * Author: Aya Ahmed
 *************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include"common_header.h"

#define MAX_ADC_VALUE      1023
#define ADC_REF_VOLTAGE    2.56

typedef enum{
	ARef_VOLT,AVCC_VOLT,Reserved,Internal_VOLT

}ADC_RefrenceVoltage;


typedef enum{
	PRE_2,PRE_2_AGAIN_,PRE_4,PRE_8,PRE_16,PRE_32,PRE_64,PRE_128
}ADC_Prescalar;

/* the members of the structure are the configurable parameters
 * then make the enum to define the values of the configurable parameters
 */
typedef struct{

	ADC_RefrenceVoltage ref_volt;
	ADC_Prescalar prescalar;

}ADC_ConfigType;


/************************************************************************
 *                         function prototypes
 *************************************************************************/

/*Description:
 * function to initialize the ADC
 */
void ADC_Init(const ADC_ConfigType* Config_Ptr);


/* description:
 * function to read the analog value and return the digital value
 */
uint16 ADC_readChannel(uint8 channel_num);


#endif /* ADC_H_ */

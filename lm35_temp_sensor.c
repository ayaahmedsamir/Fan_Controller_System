/*******************************************************************************************
 * Module: Temp sensor
 * description: source file for temp sensor drive
 * file name:lm35_temp_sensor
 * Author: Aya Ahmed
 ****************************************************************************************/


#include"adc.h"
#include"lm35_temp_sensor.h"

/*************************************************************************
                      *function definitions *
 *************************************************************************/


uint8 LM35_getTemprature(void)
{
	uint16 adc_value = 0; // uin16 because digital range (0-1023)
	uint8 temp_value = 0; //uint8 because temperature range (0-150)//

	/* read the digital value of the ADC*/
	adc_value=ADC_readChannel(CHANNEL_OF_SENSOR);

	/*calculate the temperature value from the ADC value
	 * make casting because the multiplication will result in no. greater than 255
	 * when we divide, the result is (0-150) which is uint8
	 * another solution:make temp_value of uint32
	 */
	temp_value= (uint8)(((uint32)adc_value*MAX_TEMP_VALUE*ADC_REF_VOLTAGE)/(MAX_ADC_VALUE*MAX_VOLTAGE_SENSOR_VALUE));

	/*return the temperature value*/
	return temp_value;

}


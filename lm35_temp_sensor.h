/********************************************************************************************
 * Module: temperature sensor
 * Description: header file for the temperature sensor driver
 * file name: lm35_temp_sensor.h
 * Author: Aya Ahmed Samir
 *****************************************************************************************/

#ifndef LM35_TEMP_SENSOR_H_
#define LM35_TEMP_SENSOR_H_


#include"common_header.h"

#define MAX_TEMP_VALUE                  150
#define MAX_VOLTAGE_SENSOR_VALUE        1.5
#define CHANNEL_OF_SENSOR                2

/************************************************************************
 *                         function prototypes
 *************************************************************************/

/*description:
 * function prototype to get the temperature of the sensor from the ADC value
 */
uint8 LM35_getTemprature(void);



#endif /* LM35_TEMP_SENSOR_H_ */

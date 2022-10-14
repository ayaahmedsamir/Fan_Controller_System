# Fan_Controller_System
######
An embedded project using ATmega32 microcontroller responsible for controlling the fan wether it is on or off depends on the temperature of the room, also controlling the speed of the fan depends on the temperature. Using LM35 temperature sensor will give continuous analog output corresponding to the temperature sensed by it. This analog signal is given to the ADC, which converts the analog values to digital values.The microcontroller will continuously monitor the temperature and based on the temperature value, the microcontroller will drive the fan according to:
1- if the temp is less than 30C turn OFF the fann. 
2- If the temperature is greater than or equal 30C turn on the fan with 25% of its maximum speed. 
3-f the temperature is greater than or equal 60C turn on the fan with 50% of its maximum speed. 
4-If the temperature is greater than or equal 90C turn on the fan with 75% of its maximum speed. 
5-If the temperature is greater than or equal 120C turn on the fan with 100% of its maximum speed.
-The fan is connected to a DC motor which rotates and stops based on the fan state
-The DC motor speed is controlled by generating a PWM signal generated from Timer0.

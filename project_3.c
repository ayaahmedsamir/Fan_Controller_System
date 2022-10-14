/***************************************************************************************
 *module: project 3
 *file name : project_3
 *description: application to control a fan
 *date: 10/12/2022
 *Author:  Aya Ahmed
 ****************************************************************************************/


#include"gpio.h"
#include"lcd.h"
#include"adc.h"
#include"motor.h"
#include<avr/io.h>


#define FAN_ON      1
#define FAN_OFF     0

int main(void)
{
	uint8 value;
	ADC_ConfigType configuration={Internal_VOLT,PRE_8};
	/* to initialize the LCD */
	LCD_Init();
	/* to initialize the DC motor*/
	DcMotor_Init();
	/* to initialize the ADC */
	ADC_Init(&configuration);

	/*to move the cursor and starting writing on the screen from coloumn 6, row0*/
	LCD_moveCursor(0,4);
	LCD_displayString("Fan is");

	/*to move the cursor and starting writing on the screen from coloumn 6, row1*/
	LCD_moveCursor(1,4);
	LCD_displayString("Temp=   ");


	while(1)
	{

		value = LM35_getTemprature();
		/* to control the speed of motor and its state(ON-OFF)*/
		if (value < 30)
		{
			DcMotor_Rotate(STATE_STOP,0);
			LCD_moveCursor(0,11);
			LCD_displayString("OFF");
		}
		else if(value>=30 && value < 60)
		{
			DcMotor_Rotate(STATE_CW,25);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
		}
		else if(value>=60 && value < 90)
		{
			DcMotor_Rotate(STATE_CW,50);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
		}
		else if(value>=90 && value < 120)
		{
			DcMotor_Rotate(STATE_CW,75);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
		}
		else if(value>=120)
		{
			DcMotor_Rotate(STATE_CW,100);
			LCD_moveCursor(0,11);
			LCD_displayString("ON ");
		}
		/* to display the temp on the screen everytime at the same place*/
		if (value>=100)
		{
			LCD_moveCursor(1,9);
			LCD_integerTostring(value);
		}
		else
		{
			LCD_moveCursor(1,9);
			LCD_integerTostring(value);
			LCD_displayCharacter(' ');
		}

	}
}

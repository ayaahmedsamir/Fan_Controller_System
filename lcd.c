/*************************************************************************
 * Module:LCD
 * file name:lcd.c
 * description: source file for lcd driver
 * author: Aya Ahmed
 *************************************************************************/


#include<avr/io.h>
#include"lcd.h"
#include"common_macros.h"
#include"gpio.h"
#include<util/delay.h>


/*************************************************************************
                      *function definitions *
 *************************************************************************/

/* description:
 * intialize the LCD
 * Set up the pins direction and set the settings of LCD (2-lines-8bit)
 */
void LCD_Init(void)
{
	/*configure pin4, pin5 in PORTD as output for RS and Enable*/
	GPIO_setUpPinDirection(PORT_RS_ID,PIN_RS_NUM,PIN_OUTPUT);
	GPIO_setUpPinDirection(PORT_EN_ID,PIN_EN_NUM,PIN_OUTPUT);

	_delay_ms(20); /* delay 20 ms for the LCD To turn ON*/
	/*configure PORTC as output for Sending data*/
	GPIO_setUpPortDirection(PORT_DATA_ID,PORT_OUTPUT);



	/* configure LCD as two lines and 8 bit*/
	LCD_sendCommand(TWO_LINES_8_BITS);
	/*make cursor OFF*/
	LCD_sendCommand(CURSOR_OFF);
	/*Clear the display screen*/
	LCD_sendCommand(CLEAR_DISPLAY);
}


/*description:
 * fucntion to send command to the LCD
 */
void LCD_sendCommand(uint8 command)
{
	/* configure pin of RS=0 for sending command*/
	GPIO_writePin(PORT_RS_ID,PIN_RS_NUM,LOGIC_LOW);
	_delay_ms(1);
	/* to configure pin 5 in PORTD as high*/
	GPIO_writePin(PORT_EN_ID,PIN_EN_NUM,LOGIC_HIGH);

	_delay_ms(1);

	/* to send the required command*/
	GPIO_writePort(PORT_DATA_ID,command);

	_delay_ms(1);
	GPIO_writePin(PORT_EN_ID,PIN_EN_NUM,LOGIC_LOW);
	_delay_ms(1);


}

/*description:
 * fucntion to send character to the LCD
 */
void LCD_displayCharacter(uint8 command)
{
	/* configure pin of RS=0 for sending command*/
	GPIO_writePin(PORT_RS_ID,PIN_RS_NUM,LOGIC_HIGH);
	_delay_ms(1);
	/* to configure pin 5 in PORTD as high*/
	GPIO_writePin(PORT_EN_ID,PIN_EN_NUM,LOGIC_HIGH);

	_delay_ms(1);

	/* to send the required command*/
	GPIO_writePort(PORT_DATA_ID,command);

	_delay_ms(1);
	GPIO_writePin(PORT_EN_ID,PIN_EN_NUM,LOGIC_LOW);
	_delay_ms(1);

}

/*description:
 * fucntion to send string to the LCD
 */
void LCD_displayString(const char* str)
{
	uint8 i;

	while(str[i]!='\0')
	{
		LCD_displayCharacter(str[i]);
		i++;
	}
}

/*description:
 * to move the cursor to a specified row and coloumn on the screen
 * and display the required char or string
 */
void LCD_moveCursor(uint8 row,uint8 coloumn)
{
	uint8 lcd_memory_address;

	switch(row)
	{
	case 0:
		lcd_memory_address=coloumn;
		break;
	case 1:
		lcd_memory_address=coloumn + 0x40;
		break;
	}

	LCD_sendCommand(lcd_memory_address | SET_CURSOR_LOCATION);
}

/* description:
 * display the required string in the required coloumn and row
 */
void LCD_displayStringrRowColoumn(uint8 row,uint8 coloumn,uint8 * str)
{
	LCD_moveCursor(row,coloumn);
	LCD_displayString( str );

}

/* description:
 * to clear the screen
 */
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_DISPLAY);
}

void LCD_integerTostring(uint8 value)
{
	char buff[16];
	itoa(value , buff, 10); /* function to take every no. and bring its ASCII and store in buff*/
	LCD_displayString(buff);

}

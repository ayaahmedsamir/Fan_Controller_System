/*
 * module: LCD
 * description: header file for LCD driver
 * file name: lcd.h
 * Author: Aya Ahmed Samir
 */

#ifndef LCD_H_
#define LCD_H_



#include"common_header.h"
#include"common_macros.h"


#define PORT_RS_ID      PORTD_ID
#define PIN_RS_NUM      PIN0_NUM

#define PORT_EN_ID      PORTD_ID
#define PIN_EN_NUM      PIN2_NUM
#define PORT_DATA_ID    PORTC_ID

#define CLEAR_DISPLAY        0x01
#define CURSOR_OFF           0x0C
#define CURSOR_N             0x0E
#define TWO_LINES_8_BITS     0x38
#define SET_CURSOR_LOCATION  0x80

/************************************************************************
 *                         function prototypes
 *************************************************************************/

/* description:
 * intialize the LCD
 * Set up the pins direction and set the settings of LCD (2-lines-8bit)
 */
void LCD_Init(void);


/*description:
 * fucntion to send command to the LCD
 */
void LCD_sendCommand(uint8 command);


/*description:
 * fucntion to send character to the LCD
 */
void LCD_displayCharacter(uint8 command);

/*description:
 * fucntion to send string to the LCD
 */
void LCD_displayString(const char* str);

/*description:
 * to move the cursor to a specified row and coloumn on the screen
 */
void LCD_moveCursor(uint8 row,uint8 coloumn);

/* description:
 * display the required string in the required coloumn and row
 */
void LCD_displayStringrRowColoumn(uint8 row,uint8 coloumn,uint8 * str);


/* description:
 * to clear the screen
 */
void LCD_clearScreen(void);

/* description:
 * to display numbers on the screen
 */
void LCD_integerTostring(uint8 value);

#endif /* LCD_H_ */

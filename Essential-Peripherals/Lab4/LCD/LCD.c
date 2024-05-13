/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LCD.c
 * @brief The implementation for the LCD driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "LCD.h"
#include <stdio.h>
/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
extern TYPE volatile *Data[NUMBER_OF_PORTS];
extern TYPE volatile *DataDir[NUMBER_OF_PORTS];
vuint16_t count_char = 0;
/**
 * The following arrays contains the bitmaps/pixels patters for some custom shapes **/
vuint8_t bell [ 8 ] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : LCD_isBusy()
 *
 *  Description:
 *  This function is used to make sure the LCD is not receiving data.
 * Through setting the port connected to the LCD as an input port.
 * Select the command register
 * Select the read mode (to read the commands stored in that register if exist)
 * Kick the LCD for reading process.
 * Set the port direction as an output.
 *  PRE-CONDITION: LCD is connected to the MCU.

 *  @return void
 **********************************************************************/
void LCD_isBusy() {
    DIO_PinWrite(LCD_COMMAND_PORT, RS, LOW);
    DIO_PinWrite(LCD_COMMAND_PORT, RW, HIGH); 
#ifdef EIGHT_BIT_MODE
    /** Set the LCD Port to receive data **/
    *(DataDir[LCD_DATA_PORT]) &= ~(0xFF << DATA_SHIFT_8_MODE);
    LCD_Kick();
    DIO_Init(LCD_ConfigGet());
    DIO_PinWrite(LCD_COMMAND_PORT, RW, LOW); 
#endif    
#ifdef FOUR_BIT_MODE
    /** Set the LCD Port to receive data **/
    *(DataDir[LCD_DATA_PORT]) = (*(DataDir[LCD_DATA_PORT]) & 0x0F) & ~(0xFF << DATA_SHIFT_4_MODE);
    LCD_Kick();
    DIO_Init(LCD_ConfigGet());
    DIO_PinWrite(LCD_COMMAND_PORT, RW, LOW); 
#endif
}  
/**********************************************************************
 * Function : LCD_Kick()
 *
 *  Description:
 *  This function is used to enable the LCD 
 *  through generating a high to low pulse from the Enable pin (EN)
 *  of minimum delay of 450 ns
 *  PRE-CONDITION: LCD is initialized and started to received data/commands.

 *  @return void
 **********************************************************************/
void LCD_Kick() {
    DIO_PinWrite(LCD_COMMAND_PORT, EN, HIGH);
    _delay_ms(10);
    DIO_PinWrite(LCD_COMMAND_PORT, EN, LOW);
    _delay_ms(30);
}

/**********************************************************************
 * Function : LCD_Init()
 *
 *  Description:
 *  This function is used to initialize the LCD device through powering it on
 * and waiting for >15ms. Then sending some commands.
 *
 *  PRE-CONDITION: Configuration table needs to populated (sizeof > 0)

 *  @return void
 **********************************************************************/
void LCD_Init() {
    LCD_isBusy();
    DIO_Init(LCD_ConfigGet());
    _delay_ms(50);
#ifdef EIGHT_BIT_MODE
    LCD_sendCommand(LCD_FUNCTION_8BIT_2LINES);
    LCD_sendCommand(LCD_DISP_ON_CURSOR);
    LCD_sendCommand(LCD_ENTRY_INC_);
    LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW); 
    LCD_clearScreen();
#endif
    
#ifdef FOUR_BIT_MODE
    LCD_sendCommand(0x02);
    LCD_sendCommand(LCD_FUNCTION_4BIT_2LINES);
    LCD_sendCommand(LCD_DISP_ON_CURSOR);
    LCD_sendCommand(LCD_ENTRY_INC_);
    LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW);
    LCD_clearScreen();
#endif
}

/**********************************************************************
 * Function : LCD_sendCommand()
 *
 *  Description:
 *  This function is used to send commands to the LCD command register.
 * So we should select the command register and the write operation.
 *
 *  PRE-CONDITION: LCD is initialized
 * @param: command

 *  @return void
 **********************************************************************/
void LCD_sendCommand(vuint8_t command) {
    LCD_isBusy();
    DIO_PinWrite(LCD_COMMAND_PORT, RS, LOW);
    DIO_PinWrite(LCD_COMMAND_PORT, RW, LOW);
#ifdef EIGHT_BIT_MODE
    DIO_WritePort(LCD_DATA_PORT, command);
    LCD_Kick();
#endif
    
#ifdef FOUR_BIT_MODE
    /** Sending the upper nibble **/
    *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0x0F) | (command & 0xF0);    
    _delay_ms(10);
    LCD_Kick();
    /** Sending the lower nibble **/
    *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0x0F) | (command << 4);
    _delay_ms(10);
    LCD_Kick();
#endif
}

/**********************************************************************
 * Function : LCD_sendChar()
 *
 *  Description:
 *  This function is used to send data to the LCD data register.
 * So we should select the data register and the write operation.
 *
 *  PRE-CONDITION: LCD is initialized
 * @param: char_data

 *  @return void
 **********************************************************************/
void LCD_sendChar(vuint8_t char_data) {
    LCD_isBusy();
    DIO_PinWrite(LCD_COMMAND_PORT, RS, HIGH);
    DIO_PinWrite(LCD_COMMAND_PORT, RW, LOW);
    if (count_char == 16) {
        LCD_goToXY(2, 0);        
    }
    else if (count_char >= 32) {
        LCD_clearScreen();
        LCD_goToXY(1, 0);
        count_char = 0;        
    }    
#ifdef EIGHT_BIT_MODE;     
    DIO_WritePort(LCD_DATA_PORT, char_data);
    count_char++;  
    LCD_Kick();
#endif
    
#ifdef FOUR_BIT_MODE
    /** Sending the upper nibble **/
    *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0x0F) | (char_data & 0xF0);
    _delay_ms(10);
    LCD_Kick();
    /** Sending the lower nibble **/
    *(Data[LCD_DATA_PORT]) = (*(Data[LCD_DATA_PORT]) & 0x0F) | (char_data << 4);
    _delay_ms(10);
    LCD_Kick();
    count_char++; 
#endif
}

/**********************************************************************
 * Function : LCD_sendString()
 *
 *  Description:
 *  This function is used to send string of characters
 *  to the LCD data register.
 *
 *  PRE-CONDITION: LCD is initialized
 * @param: str a pointer to unsigned character

 *  @return void
 **********************************************************************/
void LCD_sendString(vuint8_t *str) {
    vuint16_t i = 0, count = 0;
    for (i = 0; str[i]!= 0; i++) {
        if (count == 16) {
            LCD_goToXY(2, 0);        
        }
        else if (count >= 32) {
            LCD_clearScreen();
            LCD_goToXY(1, 0);
            count = 0;        
        }    
        LCD_sendChar(str[i]);
        count++;
    }
}

/**********************************************************************
 * Function : LCD_clearScreen()
 *
 *  Description:
 *  This function is used to enable the LCD 
 *  through generating a high to low pulse from the Enable pin (EN)
 *  of minimum delay of 450 ns
 *  PRE-CONDITION: LCD is initialized and started to received data/commands.

 *  @return void
 **********************************************************************/
void LCD_clearScreen() {
    LCD_sendCommand(LCD_CLEAR_SCREEN);
}
/**********************************************************************
 * Function : LCD_createCustomeCharacter()
 *
 *  Description:
 *  This function is used to send custom characters to the LCD data register.
 *
 *  PRE-CONDITION: LCD is initialized
 * @param: shape an enum object.
 * @param: location

 *  @return void
 **********************************************************************/

void LCD_createCustomeCharacter(EN_Shapes_t shape , vuint8_t location ) {
    vuint8_t *pattern;
    switch (shape) {
        case BELL:
            pattern = bell;
            break;
        default:
            break;
    }
    vuint8_t i = 0;
    LCD_sendCommand( 0x40 + (location * 8) );   /** Send the address of CGRAM **/
    for ( i = 0; i < 8; i++ ) {                 
        LCD_sendChar( pattern [ i ] );          /** Pass the bytes of pattern on LCD **/
    }  
    LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW);
    LCD_sendChar(0);
    _delay_ms(1);
}

/**********************************************************************
 * Function : LCD_goToXY()
 *
 *  Description:
 *  This function is used to modify the locations of the displayed strings
 * on the LCD, so it can start at the beginning of the first row, and the 
 * second column.
 *
 *  PRE-CONDITION: LCD is initialized
 * @param: line and position

 *  @return void
 **********************************************************************/
void LCD_goToXY(vuint8_t line, vuint8_t position){
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_sendCommand(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_sendCommand(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}

/**********************************************************************
 * Function : LCD_sendNumber() and LCD_sendRealNumber()
 *
 *  Description:
 *  These functions are used to display integer/floating point numbers
 * on the LCD. By using the standard function in C sprintf() to store the
 * string format of the numbers then pass this format to LCD_sendString() function
 * for displaying
 *
 *  PRE-CONDITION: LCD is initialized
 * @param: numbers

 *  @return void
 **********************************************************************/
void LCD_sendNumber(vuint32_t number) {
    vuint8_t str[10];
    sprintf(str, "%d", number);
    LCD_sendString(str);
}

void LCD_sendRealNumber(double real_num) {
	vuint8_t str[16];
	vuint8_t* sign = (real_num < 0) ? "-" : "";
	vuint32_t int_num = real_num ;
	float float_part = real_num - int_num;
	vuint32_t float_to_int = float_part * 10000 ;	
	sprintf(str,"%s%d.%04d",sign,int_num,float_to_int);	
	LCD_sendString(str);
}
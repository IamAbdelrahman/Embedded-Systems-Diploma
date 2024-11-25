/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LCD.h
 * @brief The interface definition for the LCD Driver
 *
 * This is the header file for the definition of the interface for
 * the LCD driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */
#ifndef LCD_H
#define LCD_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "LCD_Config.h"

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**
 * Defines an enumerated list of some shapes created on the LCD
 * device.
 */
typedef enum { BELL, HEART, SPEAKER, MUSIC, SMILE } EN_Shapes_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void LCD_Init();
void LCD_Kick();
void LCD_sendCommand(vuint8_t command);
void LCD_sendChar(vuint8_t char_data);
void LCD_sendString(vuint8_t *str);
void LCD_clearScreen();
void LCD_createCustomeCharacter(EN_Shapes_t shape, vuint8_t location);
void LCD_goToXY(vuint8_t line, vuint8_t position);
void setCursor(vuint8_t counter);
void LCD_sendNumber(vint64_t number);
void LCD_sendRealNumber(float real_num);
#endif /* LCD_H */
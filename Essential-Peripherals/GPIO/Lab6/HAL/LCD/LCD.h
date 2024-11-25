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
 * Defines an enumerated list of some errors handling related to the LCD
 * device.
 */
typedef enum {
  ZERO_DIVISION_ERROR,
  OUT_OF_RANGE_ERROR,
} EN_ErrorHandling_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void LCD_Init();
void LCD_Kick();
void LCD_sendCommand(vuint8_t command);
void LCD_sendChar(vuint8_t char_data);
void LCD_sendString(vuint8_t *str);
void LCD_clearScreen();
void LCD_goToXY(vuint8_t line, vuint8_t position);
void LCD_sendNumber(vint64_t number);
void LCD_sendRealNumber(float real_num);
void LCD_errorHandling(EN_ErrorHandling_t err);
#endif /* LCD_H */

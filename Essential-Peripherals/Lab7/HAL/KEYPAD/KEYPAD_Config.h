/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LCD_Config.h
 * @brief This module contains interface definitions for the
 *  LCD configuration.
 * @author Abdelrahman Kamal
 *
 */

#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include <GPIO.h>

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define KEYPAD_PORT PORTB
#define ROW0 PIN0
#define ROW1 PIN1
#define ROW2 PIN3
#define ROW3 PIN4
#define COL0 PIN5
#define COL1 PIN6
#define COL2 PIN7
#define COL3 PIN8

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GpioConfig_t *const KEYPAD_ConfigGet(void);
#endif /* KEYPAD_CONFIG_H */

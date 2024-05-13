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
#define	KEYPAD_CONFIG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

 /**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define KEYPAD_PORT PORTD
#define ROW0        0
#define ROW1        1
#define ROW2        2
#define ROW3        3
#define COL0        4
#define COL1        5
#define COL2        6
#define COL3        7

 /**********************************************************************
 * Typedefs
 **********************************************************************/

 /**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GpioConfig_t* const KEYPAD_ConfigGet(void);
#endif	/* KEYPAD_CONFIG_H */


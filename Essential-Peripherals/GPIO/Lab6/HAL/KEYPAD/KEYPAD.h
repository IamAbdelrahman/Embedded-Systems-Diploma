/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file KEYPAD.h
 * @brief The interface definition for the Keypad Driver
 *
 * This is the header file for the definition of the interface for
 * the KEYPAD driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */
#ifndef KEYPAD_H
#define KEYPAD_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "KEYPAD_Config.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void KEYPAD_Init();
vuint8_t KEYPAD_getKey();
#endif /* KEYPAD_H */

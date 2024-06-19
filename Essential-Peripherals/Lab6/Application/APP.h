/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.h
 * @brief The interface definition for the application Driver
 *
 * This is the header file for the definition of the interface for
 * the application driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef APP_H_
#define APP_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "KEYPAD.h"
#include "LCD.h"
#include "stdlib.h"
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
vint64_t getNumber1(void);
vint64_t getNumber2(void);
void Calculate(vint64_t num1, vint64_t num2);
void APP_Init(void);
void APP_Start(void);
#endif /* APP_H_ */
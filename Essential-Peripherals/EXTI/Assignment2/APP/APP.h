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
#include "BUTTON.h"
#include "EXTI.h"
#include "KEYPAD.h"
#include "LCD.h"
#include "LED.h"
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void MCAL_Init(void);
void HAL_Init(void);
void APP_Init(void);
void APP_Start(void);
#endif /* APP_H_ */
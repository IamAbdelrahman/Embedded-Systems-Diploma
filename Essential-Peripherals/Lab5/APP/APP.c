/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.c
 * @brief The implementation of the application driver.
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "APP.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Functions :APP_Init()
 *
 * Description:
 *
 * This function is used to initialize the applications
 *
 * PRE-CONDITION: The MCAL and HAL are configured and initialized
 *
 * POST-CONDITION: The application is initialized

 **********************************************************************/
void APP_Init(void) { LCD_Init(); }

/**********************************************************************
 * Function :APP_Start()
 *
 * Description: This function is used to start the application
 * of displaying a message on the LCD.
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start() {
  LCD_sendString("Learn in depth");
  _delay_ms(100);
  LCD_clearScreen();
}

/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.c
 * @brief The implementation of the application driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "APP.h"

extern void delay_ms(vuint32_t time);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function :APP_Init()
 *
 * Description:
 *
 * This function is used to initialize the application
 *
 * PRE-CONDITION: The MCAL and HAL are configured and initialized
 *
 * POST-CONDITION: The application is initialized

 **********************************************************************/
void APP_Init(void) {
  Clock_Init();
  LCD_Init();
}
/**********************************************************************
 * Function :APP_Start()
 *
 * Description:
 *
 * This function is used to start the application
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start(void) {
  LCD_sendString("Learn In Depth");
  delay_ms(50);
  LCD_clearScreen();
}

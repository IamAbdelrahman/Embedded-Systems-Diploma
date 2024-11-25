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
 * Function :MCAL/HAL_Init()
 *
 * Description:
 *
 * This function is used to initialize the mcal and hal layers
 *
 * PRE-CONDITION: The MCAL and HAL are configured.
 *
 * POST-CONDITION: The mcal/hal is initialized

 **********************************************************************/
void MCAL_Init() {
  Clock_Init();
  Gpio_Init(Gpio_ConfigGet());
}

void HAL_Init() {
  LCD_Init();
  KEYPAD_Init();
}
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
  LCD_sendString((vuint8_t *)"Hello there!");
  delay_ms(50);
  LCD_clearScreen();
  vuint8_t i = 0;
  for (i = 0; i < 11; i++) {
    LCD_sendNumber(i);
    delay_ms(100);
  }
  LCD_clearScreen();
  LCD_sendString((vuint8_t *)"Keypad is Ready");
  delay_ms(500);
  LCD_clearScreen();
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
  vuint8_t key;
  key = KEYPAD_getKey();
  switch (key) {
  case '!':
    LCD_clearScreen();
  case 'N':
    break;
  default:
    LCD_sendChar(key);
  }
}

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

/**********************************************************************
 * Module Variables
 **********************************************************************/
/**
 * Declare delay_ms function and the global pointer to ISRs.
 */
extern void delay_ms(vuint32_t time);
extern void (*gPf_IRQ_Callback[15])(void);

/**
 * Define a flag to be used in the ISR
 */
vuint8_t flag = 0;

/**
 * Define an ISR function to handle the EXTI9_Pin's interrupt signal
 */
void EXTI9_ISR(void) {
  flag = 1;
  LCD_sendString((vuint8_t *)"EXTI9 IRQ happens..");
  delay_ms(1000);
}
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
  GPIO_Init(GPIO_ConfigGet());
}
void HAL_Init() { LCD_Init(); }
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
  MCAL_Init();
  ST_EXTI_PINConfig_t EXTI_Cfg;
  EXTI_Cfg.EXTI_PIN = EXTI0PB9;
  EXTI_Cfg.EXTI_IRQ = IRQ_ENABLE;
  EXTI_Cfg.EXTI_Trigger = FALLING;
  EXTI_Cfg.EXTI_PIN.CallbackFunction = EXTI9_ISR;
  EXTI_Init(&EXTI_Cfg);
  HAL_Init();
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
  if (flag) {
    LCD_clearScreen();
    flag = 0;
  }
}

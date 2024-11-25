/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.h
 * @brief The interface definition for the GPIO
 *
 * This is the header file for the definition of the interface for a GPIO
 * peripheral on a standard microcontroller.
 * @author Abdelrahman Kamal
 *
 */

#ifndef GPIO__H_
#define GPIO__H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO_Config.h"
#include "Stm32f101x8.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define GPIO_PIN0 0
#define GPIO_PIN1 1
#define GPIO_PIN2 2
#define GPIO_PIN3 3
#define GPIO_PIN4 4
#define GPIO_PIN5 5
#define GPIO_PIN6 6
#define GPIO_PIN7 7
#define GPIO_PIN8 8
#define GPIO_PIN9 9
#define GPIO_PIN10 10
#define GPIO_PIN11 11
#define GPIO_PIN12 12
#define GPIO_PIN13 13
#define GPIO_PIN14 14
#define GPIO_PIN15 15

#define TYPE vuint32_t

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void Clock_Init();
void Gpio_Init(const ST_GpioConfig_t *const Config);
PinState_t Gpio_PinRead(EN_GpioX_t Port, EN_GpioPin_t Pin);
void Gpio_PinWrite(EN_GpioX_t Port, EN_GpioPin_t Pin, PinState_t State);
void Gpio_WritePort(EN_GpioX_t Port, vuint16_t PortValue);

#endif /** GPIO__H_ **/

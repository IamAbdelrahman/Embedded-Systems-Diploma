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
#include "Stm32f101x8.h"
#include "GPIO_Config.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define TYPE vuint32_t

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void Clock_Init();
void Gpio_Init(const GpioConfig_t *const Config);
PinState_t Gpio_PinRead(GpioX_t Port, GpioPin_t Pin);
void Gpio_PinToggle(GpioX_t Port, GpioPin_t Pin);
void Gpio_PinWrite(GpioX_t Port, GpioPin_t Pin, PinState_t State);
void Gpio_Reset (GpioX_t Port);

#endif /** GPIO__H_ **/
/*** End of File ******************************************************/

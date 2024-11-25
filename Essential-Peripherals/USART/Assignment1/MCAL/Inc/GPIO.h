/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO.h
 * 	@brief The interface definition for the GPIO.
 *
 *	@details: This is the header file for the definition of the interface
 *      for a GPIO peripheral on a standard microcontroller.
 *****************************************************************************/

#ifndef INCLUDES_GPIO_H_
#define INCLUDES_GPIO_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../MCAL/inc/GPIO_Cfg.h"
#include "RCC.h"
/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define TYPE vuint32_t

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void Clock_Init();
void GPIO_Init(const ST_GPIOConfig_t *const configPtr);
EN_PIN_STATE_t GPIO_PinRead(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber);
void GPIO_PinWrite(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber, EN_PIN_STATE_t pinState);
void GPIO_PinToggle(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber);
void GPIO_Reset(EN_GPIOX_t portNumber);
vuint16_t GPIO_PortRead(EN_GPIOX_t portNumber);
void GPIO_PortWrite(EN_GPIOX_t portNumber, vuint16_t portValue);
EN_GPIO_LOCK_STATE_t GPIO_LockPin(EN_GPIOX_t portNumber, EN_GPIO_PIN_t pinNumber);


#endif /* INCLUDES_GPIO_H_ */

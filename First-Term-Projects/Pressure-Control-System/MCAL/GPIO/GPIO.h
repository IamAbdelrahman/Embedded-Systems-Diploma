/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.h
 * 
 * This header file Header is containing frequently used macros and functions
 * for GPIO (General Purpose Input/Output) configuration.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "../../Utilities/Macros.h"

// Enumeration to represent different GPIO states
typedef enum {
    GPIO_STATE_ENABLE_CLOCK,   // Enable clock for GPIO
    GPIO_STATE_INIT,   // GPIO initialization
    GPIO_STATE_WRITE,  // GPIO write operation
    GPIO_STATE_ERROR   // GPIO error
} GPIO_STATE_t;

// Base addresses for GPIO and RCC (Reset and Clock Control)
#define GPIO_PORTA   0x40010800
#define BASE_RCC     0x40021000

// Register addresses for GPIO configuration
#define APB2ENR      *(volatile uint32_t *)(BASE_RCC + 0x18)
#define GPIOA_CRL    *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH    *(volatile uint32_t *)(GPIO_PORTA + 0x04)
#define GPIOA_IDR    *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR    *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

/**
 * @brief  Enable clock for GPIO Port A
 *
 * This function enables the clock for GPIO Port A, allowing it to function.
 *
 * @return GPIO_STATE_t indicating whether the clock enabling was successful.
 */
GPIO_STATE_t enableClk(void); 
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Initialize GPIO module.
 *
 * This function initializes the GPIO module by enabling the clock for GPIO peripherals,
 * specifically for Port A.
 *
 * @return GPIO_STATE_t indicating whether the initialization was successful.
 */                         
GPIO_STATE_t gpioInit(void);   
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Write a logic level to a GPIO pin.
 *
 * This function allows you to set a specific logic level (HIGH or LOW) on a GPIO pin
 * within a selected port (e.g., Port A).
 *
 * @param portName The name of the port to which the pin belongs (e.g., 'A').
 * @param pinNumber The number of the pin to be written.
 * @param value The logic level to set (HIGH or LOW).
 *
 * @return GPIO_STATE_t indicating the success or failure of the operation.
 */                         
GPIO_STATE_t gpioWritePin(vuint8_t, vuint8_t, vuint8_t);  

#endif // !GPIO_H_

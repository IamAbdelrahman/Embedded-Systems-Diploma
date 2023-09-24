/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO.c
 *
 * Source file containing GPIO (General Purpose Input/Output)
 * functions' implementations and low-level hardware access for STM32 microcontrollers.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "GPIO.h"

GPIO_STATE_t enableClk(void)
{
	SET_BIT(APB2ENR, 2);
	return GPIO_STATE_ENABLE_CLOCK;
}
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Initialize GPIO module.
 *
 * This function initializes the GPIO module by enabling the clock for GPIO peripherals,
 * specifically for Port A.
 *
 * @return GPIO_STATE_t indicating whether the initialization was successful.
 */
GPIO_STATE_t gpioInit(void)
{
	if (enableClk() == GPIO_STATE_ENABLE_CLOCK)
	{
		return GPIO_STATE_INIT;
	}
	else
	{
		return GPIO_STATE_ERROR;
	}
}
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
GPIO_STATE_t gpioWritePin(vuint8_t portName, vuint8_t pinNumber, vuint8_t value)
{
	switch (portName)
	{
	case 'A':
		if (value == HIGH)
		{
			SET_BIT(GPIOA_ODR, pinNumber);
		}
		else if (value == LOW)
		{
			CLEAR_BIT(GPIOA_ODR, pinNumber);
		}
		else
		{
			return GPIO_STATE_ERROR;
		}
		break;

	default:
		break;
	}
	return GPIO_STATE_WRITE;
}

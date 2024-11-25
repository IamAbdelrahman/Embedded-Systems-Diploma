/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED.c
 * @brief The implementation for the LED driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "LED.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : LED_Toggle()
 *
 *  Description:
 *  This function is used to toggle a led connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as GPIO
 *  PRE-CONDITION: The channel is within the maximum GpioPin_t definition

 *  @param Port is the port of the pin to write using the GpioX_t enum definition
 *  @param Pin is the pin to write using the GpioPin_t enum definition

 *  @return void
 **********************************************************************/
void LED_Toggle(GpioX_t Port, GpioPin_t Pin) {
	Gpio_PinToggle(Port, Pin);
}


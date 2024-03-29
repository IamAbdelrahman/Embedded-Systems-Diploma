/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUTTON.c
 * @brief The implementation for the BUTTON driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "BUTTON.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : BUTTON_Read()
 *
 * Description:
 *
 * This function is used to read the state of a Button
 * connected to the MCU's channel (pin)
 *
 * PRE-CONDITION: The channel is configured as INPUT
 * PRE-CONDITION: The channel is configured and initialized as GPIO
 * PRE-CONDITION: The channel is within the maximum GpioChannel_t
 * definition
 *
 * POST-CONDITION: The channel state is returned.
 * @param Port is the port of the pin to read from using the GpioX_t enum definition
 * @param Pin is the GpioChannel_t that represents a pin
 *
 * @return The state of the pin as HIGH or LOW
 **********************************************************************/
PinState_t BUTTON_Read(GpioX_t Port, GpioPin_t Pin) {
	return (Gpio_PinRead(Port, Pin));
}

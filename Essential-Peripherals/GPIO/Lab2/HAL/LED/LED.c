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
 * Function : LED_On()
 *
 *  Description:
 *  This function is used to turn on a led connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param Pin is the pin to write using the DIOPin_t enum definition

 *  @return void
 **********************************************************************/
void LED_On(DIOPORTX_t Port, DIOPin_t Pin) {
	DIO_PinWrite(Port, Pin, HIGH);
}

/**********************************************************************
 * Function : LED_Off()
 *
 *  Description:
 *  This function is used to turn off a led connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param Pin is the pin to write using the DIOPin_t enum definition

 *  @return void
 **********************************************************************/
void LED_Off(DIOPORTX_t Port, DIOPin_t Pin) {
	DIO_PinWrite(Port, Pin, LOW);
}

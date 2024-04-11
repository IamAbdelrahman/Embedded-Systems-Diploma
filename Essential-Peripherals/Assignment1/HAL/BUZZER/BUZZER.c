/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUZZER.c
 * @brief The implementation for the BUZZER driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "BUZZER.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : BUZZER_On()
 *
 *  Description:
 *  This function is used to turn on a buzzer connected to the MCU's channel(pin)
 *
 *  PRE-CONDITION: The channel is configured as OUTPUT
 *  PRE-CONDITION: The channel is configured and initialized as DIO
 *  PRE-CONDITION: The channel is within the maximum DIOPin_t definition

 *  @param Port is the port of the pin to write using the DIOPORTX_t enum definition
 *  @param Pin is the pin to write using the DIOPin_t enum definition

 *  @return void
 **********************************************************************/
void BUZZER_On(DIOPORTX_t Port, DIOPin_t Pin) {
	DIO_PinWrite(Port, Pin, HIGH);
}


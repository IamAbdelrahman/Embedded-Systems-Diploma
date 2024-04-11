/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED.h
 * @brief The interface definition for the LED Driver
 *
 * This is the header file for the definition of the interface for
 * the LED driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */


#ifndef LED_LED_H_
#define LED_LED_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void LED_On(DIOPORTX_t Port, DIOPin_t Pin);
#endif /* LED_LED_H_ */
/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED.h
 *
 * This header file Header is containing frequently used functions
 * for the alarm devide (LED).
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "../../MCAL/GPIO/GPIO.h"

typedef enum alarm_state
{
    ALARM_STATE_INIT, // LED initialization state
    ALARM_STATE_ON,   // LED turn on state
    ALARM_STATE_OFF,  // LED turn off state
    ALARM_STATE_ERROR // LED error state
} ALARM_STATE_t;
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Initializes the LED module.
 *
 * This function initializes the GPIO pins associated with the LED.
 * It sets up the GPIO pins and prepares them for LED control.
 *
 * @return ALARM_STATE_t - The initialization state of the LED module.
 */
ALARM_STATE_t ledInit(void);
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Turns on the LED.
 *
 * This function turns on the LED by setting the corresponding GPIO pin to a low logic level.
 * Note that the led here is connected in an active-low state.
 *
 * @param portName - The name of the GPIO port where the LED is connected.
 * @param pinNumber - The number of the GPIO pin connected to the LED.
 * 
 * @return ALARM_STATE_t - The state of the LED after the operation.
 */
ALARM_STATE_t ledOn(vuint8_t, vuint8_t);
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Turns off the LED.
 *
 * This function turns off the LED by setting the corresponding GPIO pin to a high logic level.
 * Note that the led here is connected in an active-low state.
 * 
 * @param portName - The name of the GPIO port where the LED is connected.
 * @param pinNumber - The number of the GPIO pin connected to the LED.
 *
 * @return ALARM_STATE_t - The state of the LED after the operation.
 */
ALARM_STATE_t ledOff(vuint8_t, vuint8_t);

/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LED.c
 *
 * Source file contains functions' implementations
 * for controlling the alarm device (LED).
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "LED.h"

ALARM_STATE_t ledInit()
{
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x22222222;
    return ALARM_STATE_INIT;
}

ALARM_STATE_t ledOn(vuint8_t portName, vuint8_t pinNumber)
{
    if (gpioWritePin(portName, pinNumber, LOW) == GPIO_STATE_WRITE)
    {
        return ALARM_STATE_ON;
    }

    return ALARM_STATE_ERROR;
}

ALARM_STATE_t ledOff(vuint8_t portName, vuint8_t pinNumber)
{
    if (gpioWritePin(portName, pinNumber, HIGH) == GPIO_STATE_WRITE)
    {
        return ALARM_STATE_OFF;
    }

    return ALARM_STATE_ERROR;
}

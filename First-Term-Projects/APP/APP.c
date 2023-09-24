/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.c
 *
 * Source file is containing the functions' implementation
 * for the application layer.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */

#include "APP.h"
vuint8_t PValue = 0;

int appInit(void)
{
    if (gpioInit() == GPIO_STATE_INIT)
    {
        if (ledInit() == ALARM_STATE_INIT)
        {
            if (psInit() == PRESSURE_SENSOR_STATE_INIT)
                return 1;
        }
    }
    return 0;
}

APP_STATE_t highPressureDetect()
{
    if (getPressureVal(&PValue) == PRESSURE_SENSOR_STATE_READING)
    {
        if (PValue > THRESHOLD)
        {
            return APP_STATE_HIGH_PRESSURE_DETECT;
        }
        else
        {
            return APP_STATE_PRESSURE_DETECT;
        }
    }
    return APP_STATE_ERROR;
}

APP_STATE_t alarmMonitor()
{
    if (highPressureDetect() == APP_STATE_HIGH_PRESSURE_DETECT)
    {
        ledOn('A', 13);
        Delay(6000);
        ledOff('A', 13);
        Delay(6000);
        return APP_STATE_START_ALARM;
    }
    else if (highPressureDetect() == APP_STATE_PRESSURE_DETECT)
    {
        ledOff('A', 13);
        return APP_STATE_STOP_ALARM;
    }
    return APP_STATE_ERROR;
}

int appStart(void)
{
    if (alarmMonitor() == APP_STATE_START_ALARM)
    {
        return 1;
    }
    else if (alarmMonitor() == APP_STATE_STOP_ALARM)
    {
        return 1;
    }
    return 0;
}

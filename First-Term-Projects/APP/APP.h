/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.h
 *
 * This header file Header is containing frequently used macros and functions
 * for the application layer.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "../HAL/LED/LED.h"
#include "../HAL/Pressure_Sensor/P_Sensor.h"
#define THRESHOLD 20

typedef enum APP_STATE_state
{
    APP_STATE_ERROR,                // Application error state
    APP_STATE_INIT,                 // Application initialization state
    APP_STATE_PRESSURE_DETECT,      // Application pressure detect state
    APP_STATE_HIGH_PRESSURE_DETECT, // Application high pressure detect state
    APP_STATE_START_ALARM,          // Application led-on state
    APP_STATE_STOP_ALARM            // Application led-off state
} APP_STATE_t;

/**
 * @brief Application Initialization Function
 *
 * This function initializes the APP_STATElication, including GPIO, LED, and
 * pressure sensor modules. It ensures that all necessary components
 * are set up for the proper functioning of the pressure control system.
 *
 * @return 1 if initialization is successful, 0 if initialization fails.
 */
int appInit(void);
/*------------------------------------------------------------------------------------------*/

/**
 * @brief High Pressure Detection Function
 *
 * This function checks the pressure value from the pressure sensor and
 * determines whether the pressure is high or not compared to the threshold.
 * It returns the appropriate state based on the pressure reading.
 *
 * @return APP_STATE_HIGH_PRESSURE_DETECT if high pressure is detected,
 *         APP_STATE_PRESSURE_DETECT if normal pressure is detected,
 *         APP_STATE ERROR if an error occurs during the detection process.
 */
APP_STATE_t highPressureDetect(void);
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Alarm Monitor Function
 *
 * This function monitors the pressure and controls the LED alarm.
 * It checks the pressure level and toggles the alarm LED if a high
 * pressure condition is detected. It also handles turning off the alarm
 * when the pressure returns to a normal level.
 *
 * @return APP_STATE_START_ALARM if the alarm LED is turned on,
 *         APP_STATE_STOP_ALARM if the alarm LED is turned off,
 *         APP_STATE_ERROR if an error occurs during the monitoring process.
 */
APP_STATE_t alarmMonitor(void);
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Application Start Function
 *
 * This function starts the application and monitors the pressure to
 * control the alarm LED. It returns appropriate values based on the
 * monitoring results.
 *
 * @return 1 if the alarm is started or stopped successfully, 0 if an error occurs.
 */
int appStart(void);

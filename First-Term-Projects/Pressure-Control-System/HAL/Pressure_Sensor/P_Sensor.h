/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file P_Sensor.h
 *
 * This header file Header is containing frequently used macros and functions
 * for the pressure sensor device.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#ifndef P_SENSOR_H_
#define P_SENSOR_H_
#include "../../MCAL/GPIO/GPIO.h"
#define PRESSURE_POLL_TIME 100

// Enumeration to represent different pressure_sensor states
typedef enum pressure_sensor_state
{
    PRESSURE_SENSOR_STATE_INIT,    // Pressure sensor initialization state
    PRESSURE_SENSOR_STATE_WAITING, // Pressure sensor waiting state
    PRESSURE_SENSOR_STATE_READING, // Pressure sensor reading state
    PRESSURE_SENSOR_STATE_ERROR    // Pressure sensor error state
} PS_STATE_t;

/**
 * @brief Initializes the pressure sensor module.
 *
 * @return PS_INIT if the pressure sensor module is successfully initialized.
 */
PS_STATE_t psInit(void);
/*------------------------------------------------------------------------------------------*/

/** @brief Reads the pressure value from the sensor.
 *
 * @param PPValue A pointer to a variable where the pressure value will be stored.
 * @return PS_READING if the pressure value was successfully read,
 *         PS_WAITING if the pressure sensor is waiting for a valid reading,
 *         PS_ERROR if a valid reading could not be obtained within the specified poll time.
 */
PS_STATE_t getPressureVal(vuint8_t *);
/*------------------------------------------------------------------------------------------*/

/**
 * @brief Delay function
 *
 * This function introduces a delay of a specified period in a blocking manner.
 * It uses a simple loop to consume CPU cycles and create a time delay.
 *
 * @param Period: The duration of the delay in arbitrary units.
 *
 * @note This function can be used for introducing time delays in applications where
 * precise timing is not critical. However, it's a blocking function, meaning it will
 * halt the program's execution for the specified duration.
 */
void Delay(vuint32_t);

#endif // !P_SENSOR_H_

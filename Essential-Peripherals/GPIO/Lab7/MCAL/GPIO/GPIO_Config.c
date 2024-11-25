/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO_Config.c
 * @brief This module contains the implementation for the GPIO peripheral
 * configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each GPIO peripheral
 * pin. Each row represents a single pin. Each column is representing a member
 * of the GpioConfig_t structure. This table is read in by Gpio_Init(), where
 * each pin is then set up based on this table.
 */
const ST_GpioConfig_t GpioConfig[] = {
    /*PORT		PIN					STATE									MODE
     */
    {PORTA, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN2, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN3, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN6, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN8, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN9, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTA, PIN10, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN3, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN6, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {PORTB, PIN8, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
};

vuint32_t ConfigSize = sizeof(GpioConfig) / sizeof(GpioConfig[0]);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : Dio_ConfigGet()
 *
 * This function is used to initialize the GPIO based on the configuration
 * table defined in dio_cfg module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GpioConfig_t *const Gpio_ConfigGet(void) {
  return (ST_GpioConfig_t *const) & GpioConfig[0];
}

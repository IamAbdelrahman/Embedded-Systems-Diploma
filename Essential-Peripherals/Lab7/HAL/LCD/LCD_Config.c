/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LCD_Config.c
 * @brief This module contains the implementation for the LCD configuration
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "LCD_Config.h"

/**********************************************************************
 * Module Variable Definitions
 **********************************************************************/
/**
 * The following array contains the configuration data for each LCD driver
 * Each row represents a single pin. Each column is representing a member of the
 * GpioConfig_t structure. This table is read in by LCD_Init(), where each pin
 * is then set up based on this table.
 */
const ST_GpioConfig_t LCDConfig[] = {
    /* PORT						   PIN					STATE									MODE
     */
    {LCD_COMMAND_PORT, RS, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_COMMAND_PORT, RW, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_COMMAND_PORT, EN, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
#ifdef EIGHT_BIT_MODE
    {LCD_DATA_PORT, PIN0, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN1, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN2, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN3, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN4, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN5, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN6, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN7, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ}
#endif

#ifdef FOUR_BIT_MODE
    {LCD_DATA_PORT, PIN4, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN5, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN6, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {LCD_DATA_PORT, PIN7, GPIO_OUTPUT_PUSHPULL,
     GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ}
#endif
};

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : LCD_ConfigGet()
 *
 * This function is used to initialize the LCD based on the configuration
 * table defined in LCDConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GpioConfig_t *const LCD_ConfigGet(void) {
  return (ST_GpioConfig_t *const) & LCDConfig[0];
}

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
    /*  PORT           PIN	STATE */
    {LCD_COMMAND_PORT, RS, DIO_OUTPUT},
    {LCD_COMMAND_PORT, RW, DIO_OUTPUT},
    {LCD_COMMAND_PORT, EN, DIO_OUTPUT},
#ifdef EIGHT_BIT_MODE
    {LCD_DATA_PORT, Pin0, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin1, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin2, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin3, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin4, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin5, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin6, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin7, DIO_OUTPUT}
#endif

#ifdef FOUR_BIT_MODE
    {LCD_DATA_PORT, Pin4, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin5, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin6, DIO_OUTPUT},
    {LCD_DATA_PORT, Pin7, DIO_OUTPUT}
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

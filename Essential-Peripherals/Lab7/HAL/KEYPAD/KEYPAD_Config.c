/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file KEYPAD_Config.c
 * @brief This module contains the implementation for the KEYPAD configuration
 *
 * @author Abdelrahman Kamal
 *
 */
/**********************************************************************
 * Includes
 **********************************************************************/
#include <KEYPAD_Config.h>

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Module Variables
 **********************************************************************/
/**
 * The following array contains the configuration data for each KEYPAD driver
 * Each row represents a single pin.
 * Each column is representing a member of the GpioConfig_t structure.
 * This table is read in by KEYPAD_Init(), where each pin is then set up based
 * on this table.
 */
const ST_GpioConfig_t KEYPADConfig[] = {
/* PORT           PIN		STATE				MODE */
    {KEYPAD_PORT, PIN0, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {KEYPAD_PORT, PIN1, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {KEYPAD_PORT, PIN3, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {KEYPAD_PORT, PIN4, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ},
    {KEYPAD_PORT, PIN5, GPIO_INPUT_PULLDOWN,
     GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {KEYPAD_PORT, PIN6, GPIO_INPUT_PULLDOWN,
     GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {KEYPAD_PORT, PIN7, GPIO_INPUT_PULLDOWN,
     GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED},
    {KEYPAD_PORT, PIN8, GPIO_INPUT_PULLDOWN,
     GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED}};
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : KEYPAD_ConfigGet()
 *
 * This function is used to initialize the KEYPAD based on the configuration
 * table defined in LCDConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GpioConfig_t *const KEYPAD_ConfigGet(void) {
  return (ST_GpioConfig_t *const) & KEYPADConfig[0];
}

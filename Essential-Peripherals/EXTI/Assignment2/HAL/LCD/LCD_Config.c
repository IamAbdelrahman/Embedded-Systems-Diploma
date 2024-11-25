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
 * GPIOConfig_t structure. This table is read in by LCD_Init(), where each pin
 * is then set up based on this table.
 */
const ST_GPIOConfig_t LCDConfig[] = {LCD_COMMAND_RS,
                                     LCD_COMMAND_RW,
                                     LCD_COMMAND_EN,
#ifdef EIGHT_BIT_MODE
                                     LCD_DATA0,
                                     LCD_DATA1,
                                     LCD_DATA2,
                                     LCD_DATA3,
                                     LCD_DATA4,
                                     LCD_DATA5,
                                     LCD_DATA6,
                                     LCD_DATA7
#endif

#ifdef FOUR_BIT_MODE
                                     LCD_DATA4,
                                     LCD_DATA5,
                                     LCD_DATA6,
                                     LCD_DATA7
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
const ST_GPIOConfig_t *const LCD_ConfigGet(void) {
  return (ST_GPIOConfig_t *const) & LCDConfig[0];
}

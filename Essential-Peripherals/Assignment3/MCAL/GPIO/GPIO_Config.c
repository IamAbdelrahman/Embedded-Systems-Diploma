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
 * of the GPIOConfig_t structure. This table is read in by GPIO_Init(), where
 * each pin is then set up based on this table.
 */
const ST_GPIOConfig_t GPIOConfig[] = {
    GPIOA0, GPIOA1, GPIOA2, GPIOA3, GPIOA4, GPIOA5, GPIOA6, GPIOA7,
    GPIOB0, GPIOB1, GPIOB2, GPIOB3, GPIOB4, GPIOB5, GPIOB6, GPIOB7,
    GPIOC0, GPIOC1, GPIOC2, GPIOC3, GPIOC4, GPIOC5, GPIOC6, GPIOC7,
    GPIOD0, GPIOD1, GPIOD2, GPIOD3, GPIOD4, GPIOD5, GPIOD6, GPIOD7,
};

/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : GPIOConfig_t()
 *
 * This function is used to initialize the GPIO based on the configuration
 * table defined in GPIOConfig module.
 *
 * PRE-CONDITION: Configuration table needs to populated (sizeof > 0)
 *
 * POST-CONDITION: A constant pointer to the first member of the
 * configuration table will be returned.
 *
 ** @return A pointer to the configuration table.

 **********************************************************************/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void) {
  return (ST_GPIOConfig_t *const) & GPIOConfig[0];
}

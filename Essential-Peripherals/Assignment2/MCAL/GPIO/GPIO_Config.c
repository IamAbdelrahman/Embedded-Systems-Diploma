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
    GPIOA0,  GPIOA1,  GPIOA2,  GPIOA3,  GPIOA4,  GPIOA5,  GPIOA6,  GPIOA7,
    GPIOA8,  GPIOA9,  GPIOA10, GPIOA11, GPIOA12, GPIOA13, GPIOA14, GPIOA15,
    GPIOB0,  GPIOB1,  GPIOB2,  GPIOB3,  GPIOB4,  GPIOB5,  GPIOB6,  GPIOB7,
    GPIOB8,  GPIOB9,  GPIOB10, GPIOB11, GPIOB12, GPIOB13, GPIOB14, GPIOB15,
    GPIOC13, GPIOC14, GPIOC15, GPIOD0,  GPIOD1};

vuint32_t ConfigSize = sizeof(GPIOConfig) / sizeof(GPIOConfig[0]);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function : GPIO_ConfigGet()
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
const ST_GPIOConfig_t *const GPIO_ConfigGet(void) {
  return (ST_GPIOConfig_t *const) & GPIOConfig[0];
}

/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO_Lcfg.h
 *	@brief This file includes the implementation for the GPIO peripheral
 *configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../MCAL/inc/GPIO_Cfg.h"

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
/*- GPIO CONFIGURATION TABLE */
const static ST_GPIOConfig_t configGpio[] = {
    GPIOA0,  GPIOA1,  GPIOA2,  GPIOA3,  GPIOA4,  GPIOA5,  GPIOA6,  GPIOA7,
    GPIOA8,  GPIOA9,  GPIOA10, GPIOA11, GPIOA12, GPIOA13, GPIOA14, GPIOA15,
    GPIOB0,  GPIOB1,  GPIOB2,  GPIOB3,  GPIOB4,  GPIOB5,  GPIOB6,  GPIOB7,
    GPIOB8,  GPIOB9,  GPIOB10, GPIOB11, GPIOB12, GPIOB13, GPIOB14, GPIOB15,
    GPIOC13, GPIOC14, GPIOC15, GPIOD0,  GPIOD1};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeGpio = sizeof(configGpio) / sizeof(configGpio[0]);

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: GPIO_ConfigGet
 * Synatax: const ST_GPIOConfig_t* const GPIO_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the GPIO based on a config
 *table. PRE-CONDITION: Config table needs to populated (configGpio > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: A const pointer to the first member of the config table is
 *returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_GPIOConfig_t* const
 *************************************************************************/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void) {
  return (ST_GPIOConfig_t *const) & configGpio[0];
}

/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: RCC_Lcfg.c
 *	@brief This file includes the implementation for the RCC peripheral
 *	configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../MCAL/inc/RCC_Cfg.h"

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/

static const ST_RCC_Config_t configRcc[] = {
    {RCC_SELECT_HSI,
     {RCC_GPIOA, RCC_GPIOB, RCC_GPIOC, RCC_GPIOD, RCC_AFIO, RCC_USART1}}};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeRcc = sizeof(configRcc) / sizeof(configRcc[0]);
ST_PLL_Config_t configPll = {HSI_CLK_BY2, PREDIV1_NULL, PLL_X8};

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: RCC_ConfigGet
 * Synatax: const ST_RCC_Config_t *const RCC_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the RCC based on a config
 *table. PRE-CONDITION: Config table needs to populated (configRcc > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * POST-CONDITION: A const pointer to the first member of the config table is
 *returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_RCC_Config_t* const
 *************************************************************************/
const ST_RCC_Config_t *const RCC_ConfigGet(void) {
  return (ST_RCC_Config_t *const) & configRcc[0];
}

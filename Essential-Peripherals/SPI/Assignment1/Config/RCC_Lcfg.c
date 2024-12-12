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
#include "../inc/RCC_Cfg.h"

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/

static const ST_RCC_Config_t configRcc[] = {
    {RCC_SELECT_HSI,
     {RCC_GPIOA, RCC_GPIOB, RCC_GPIOC, RCC_GPIOD, RCC_AFIO, RCC_USART1,
     RCC_SPI1, RCC_SPI2}}};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeRcc = sizeof(configRcc) / sizeof(configRcc[0]);
ST_PLL_Config_t configPll = {HSI_CLK_BY2, PREDIV1_NULL, PLL_X8};

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
const ST_RCC_Config_t *const RCC_ConfigGet(void) {
  return (ST_RCC_Config_t *const) & configRcc[0];
}

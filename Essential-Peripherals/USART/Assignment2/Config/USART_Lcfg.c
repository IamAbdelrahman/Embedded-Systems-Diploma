/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: UART_Lcfg.c
 *	@brief This file includes the implementation for the UART peripheral
 *	configuration
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../MCAL/inc/USART_Cfg.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL Datatypes
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
static ST_UARTConfig_t configUsart[] = {UART1_CFG};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeUsart = sizeof(configUsart) / sizeof(configUsart[0]);

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: UART_ConfigGet
 * Synatax: const ST_GPIOConfig_t *const UART_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the UART based on a config
 *table. PRE-CONDITION: Config table needs to populated (configUsart > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: A const pointer to the first member of the config table is
 *returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_GPIOConfig_t* const
 *************************************************************************/
ST_UARTConfig_t *const UART_ConfigGet(void) {
  return (ST_UARTConfig_t *const) & configUsart[0];
}

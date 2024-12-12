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
#include "../inc/USART_Cfg.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- LOCAL VARIABLES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
static ST_UARTConfig_t configUsart[] = {UART1_CFG};

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeUsart = sizeof(configUsart) / sizeof(configUsart[0]);

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
ST_UARTConfig_t *const UART_ConfigGet(void) {
  return (ST_UARTConfig_t *const) & configUsart[0];
}

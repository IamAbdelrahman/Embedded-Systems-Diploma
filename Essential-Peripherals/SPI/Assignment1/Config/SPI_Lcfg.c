/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: SPI_Lcfg.c
 *	@brief This file includes the implementation for the SPI peripheral
 *	configuration
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../inc/SPI_Cfg.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/

/*- LOCAL VARIABLES
 -----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
#if SPI_MODE == MASTER
static ST_SPIConfig_t configSpi[] = { SPI1MASTER_CFG };
#elif SPI_MODE == SLAVE
static ST_SPIConfig_t configSpi[] = { SPI1SLAVE_CFG };
#endif

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
vuint32_t configSizeSpi = sizeof(configSpi) / sizeof(configSpi[0]);

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
ST_SPIConfig_t* const SPI_ConfigGet(void) {
	return (ST_SPIConfig_t* const ) &configSpi[0];
}

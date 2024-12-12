/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI_Lcfg.h
 *	@brief This file includes the implementation for the EXII peripheral
 *  configuration
 *
 *****************************************************************************/


/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../inc/EXTI_Cfg.h"

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/
/*- EXTI CONFIGURATION TABLE */
const static ST_EXTIConfig_t configExti[] = { EXTIPB9_CFG };

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint32_t configSizeExti = sizeof(configExti) / sizeof(configExti[0]);

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
ST_EXTIConfig_t* const EXTI_ConfigGet(void) {
  return (ST_EXTIConfig_t *const) & configExti[0];
}

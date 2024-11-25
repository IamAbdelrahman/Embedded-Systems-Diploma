/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.h
 *   @brief The interface definition for the application Driver
 *
 *	@details: This is the header file for the definition of the interface
 *for the application driver connected to the microcontroller
 *****************************************************************************/

#ifndef APP_H_
#define APP_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "LCD.h"
#include "USART.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: MCAL_Init
 * Syntax: void MCAL_Init(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize MCAL layer
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void MCAL_Init(void);

/************************************************************************
 * Service Name: HAL_Init
 * Syntax: void HAL_Init(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize HAL layer
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void HAL_Init(void);

/************************************************************************
 * Service Name: APP_Init
 * Syntax: void APP_Init(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the application
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void APP_Init(void);

/************************************************************************
 * Service Name: APP_Start
 * Syntax: void APP_Start(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Run the application
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void APP_Start(void);

#endif /* APP_H_ */
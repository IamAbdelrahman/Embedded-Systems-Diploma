/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint16_t data;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/

/************************************************************************
 * Service Name: APP_Init
 * Synatax: void APP_Init(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the application
 * PRE-CONDITION: MCAL layer is configured and initialized
 * POST-CONDITION: The APP is initialized
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void APP_Init(void) {
    UART_Init(UART_ConfigGet());
    LCD_Init();
    LCD_WriteString((vuint8_t*)"UART Lab");
    LCD_XY(2, 0);
}

/************************************************************************
 * Service Name: APP_Start
 * Synatax: void APP_Start(void)
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * @description: Start the application
 * PRE-CONDITION: The APP is initialized
 * POST-CONDITION: APP starts
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void APP_Start(void) {
    UART_ReceiveData(&data);
    LCD_WriteChar((vuint8_t)data);
}
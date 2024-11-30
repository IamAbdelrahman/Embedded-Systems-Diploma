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

typedef struct {
    vuint8_t transmitEmpty : 1;
    vuint8_t transmitComplete : 1;
    vuint8_t receiveComplete : 1;
} ST_IRQFlags_t;

ST_IRQFlags_t irqFlag = {0};

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void IRQ_SetFlags(EN_UART_IRQ_t);
void UART_CallBack(void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
void IRQ_SetFlags(EN_UART_IRQ_t Flag) {
    switch (Flag) {
        case UART_IRQ_RXC:
            irqFlag.receiveComplete = 1U;
            break;
        case UART_IRQ_TXC:
            irqFlag.transmitComplete = 1U;
            break;
        case UART_IRQ_TXE:
            irqFlag.transmitEmpty = 1U;
            break;
        default:
            break;
    }
}

void UART_CallBack(void) {
    if (irqFlag.receiveComplete) {
        UART_ReceiveData(&data);
        UART_SendData(&data);
    }
    /* TODO the remaining interrupt signals (flags) */
}
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
    ST_UARTConfig_t *const configPtr = UART_ConfigGet();
    configPtr->callBackFunctionUart = UART_CallBack;
    IRQ_SetFlags(configPtr->Irq);
    UART_Init(configPtr);
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
    ;
}

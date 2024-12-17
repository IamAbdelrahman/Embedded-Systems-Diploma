/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * 	@file: UART.h
 * 	@brief The interface definition for the UART.
 *
 * 	@details: This is the header file for the definition of the interface
 *	for a UART peripheral on a standard microcontroller.
 *****************************************************************************/

#ifndef INCLUDES_USART_H_
#define INCLUDES_USART_H_
/*- INCLUDES
-----------------------------------------------------------------------*/
#include "GPIO.h"
#include "USART_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define TERMINATOR  '\r' // '\r' 

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef enum {
    UART_ERROR = 0, UART_SUCCESS
}EN_UART_STATUS_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: UART_Init
 * Syntax: void UART_Init(const ST_UARTConfig_t* const configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize UART module.
 * @param (in): configPtr a pointer to UART_Config struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_Init(ST_UARTConfig_t *const configPtr);

/************************************************************************
 * Service Name: UART_SendData
 * Syntax: void UART_SendData(vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send data by UART module.
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_SendData(vuint16_t *pBuffer);

/************************************************************************
 * Service Name: UART_ReceiveData
 * Syntax: void UART_ReceiveData(vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Receive data by UART module.
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: an enum represents an error state
 *************************************************************************/
EN_UART_STATUS_t UART_ReceiveData(vuint16_t *pBuffer);

/************************************************************************
 * Service Name: UART_SendString
 * Syntax: void UART_SendString(vuint8_t *pStr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send a user-defined-terminated string by UART module.
 * @param (in): pStr a pointer to a character
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_SendString(vuint8_t *pStr);

/************************************************************************
 * Service Name: UART_ReceiveString
 * Syntax: void UART_ReceiveString (vuint8_t *pStr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Receive a null-terminated string by UART module.
 * @param (in): pStr a pointer to a character
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_ReceiveString (vuint8_t *pStr);

/************************************************************************
 * Service Name: UART_SendIntNum
 * Syntax: void UART_SendIntNum (vuint32_t Num)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send an integer number.
 * @param (in): Num an integer number to be sent
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_SendIntNum (vuint32_t Num);

/************************************************************************
 * Service Name: UART_ReceiveIntNum
 * Syntax: void UART_ReceiveIntNum (vuint32_t *pNum)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send an integer number.
 * @param (in): pNum a pointer to an integer number to store the received number
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_ReceiveIntNum (vuint32_t *pNum);

/************************************************************************
 * Service Name: UART_TXStringAsync
 * Syntax: void UART_TXStringAsync(vuint8_t* pStr)
 * Sync/Async: Asynchronous
 * Reentrancy: Non reentrant
 * @description: Send a string
 * @param (in): pStr a pointer to a character
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_TXStringAsync(vuint8_t* pStr);

/************************************************************************
 * Service Name: UART_RXStringAsync
 * Syntax: void UART_RXStringAsync(vuint8_t* pStr)
 * Sync/Async: Asynchronous
 * Reentrancy: Non reentrant
 * @description: Receive a string
 * @param (in): pStr a pointer to a character
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_RXStringAsync(vuint8_t* pStr);

/*
 * TODO
 * void USART_Init() 		- Using the Synchronous Mode
 */

#endif /* INCLUDES_USART_H_ */
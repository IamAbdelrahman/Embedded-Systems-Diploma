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
#include "../Config/inc/USART_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define TERMINATOR 13

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

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
 * @param (in): usartNumber represents the instance number of the UART
 *peripheral
 * @param (in): configPtr a pointer to UART_Config struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_Init(ST_UARTConfig_t *const configPtr);

/************************************************************************
 * Service Name: UART_Reset
 * Syntax: void UART_Reset(EN_UARTX_t usartNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset UART module.
 * @param (in): usartNumber represents the instance number of the UART
 *peripheral
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_Reset(EN_UARTX_t usartNumber);

 /************************************************************************
  * Service Name: UART_SendData
  * Syntax: void UART_SendData(EN_UARTX_t usartNumber, vuint16_t* pBuffer)
  * Sync/Async: Synchronous
  * Reentrancy: Non reentrant
  * @description: Send data by UART module.
  * @param (in): usartNumber represents the instance number of the UART
  *peripheral
  * @param (in): pBuffer a pointer to a buffer that stores the sent data
  * @param (inout): None
  * @param (out): None
  * @return: None
  *************************************************************************/
void UART_SendData(EN_UARTX_t usartNumber, vuint16_t *pBuffer);

/************************************************************************
 * Service Name: UART_ReceiveData
 * Syntax: void UART_ReceiveData(EN_UARTX_t usartNumber, vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Receive data by UART module.
 * @param (in): usartNumber represents the instance number of the UART
 *peripheral
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_ReceiveData(EN_UARTX_t usartNumber, vuint16_t *pBuffer);

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

/*
 * TODO
 * void USART_LIN_Init()
 * void USART_Init() 		- Using the Synchronous Mode
 * void USART_DMA_Init()	- Using the DMA
 */

#endif /* INCLUDES_USART_H_ */

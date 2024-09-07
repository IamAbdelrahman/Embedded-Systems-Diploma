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

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
void UART_Init(ST_UARTConfig_t *const configPtr);
void UART_Reset(EN_UARTX_t usartNumber);
void UART_SendData(EN_UARTX_t usartNumber, vuint16_t *pBuffer);
void UART_ReceiveData(EN_UARTX_t usartNumber, vuint16_t *pBuffer);

/*
 * TODO
 * void USART_LIN_Init()
 * void USART_Init() 		- Using the Synchronous Mode
 * void USART_DMA_Init()	- Using the DMA
 */

#endif /* INCLUDES_USART_H_ */

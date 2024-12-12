/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: UART_Cfg.h
 *	@brief This module contains interface definitions for the
 *	UART configuration related to the LQFP48 package.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the UART configuration table.
 *****************************************************************************/
#ifndef INCLUDES_USART_CFG_H_
#define INCLUDES_USART_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../inc/GPIO_Cfg.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
#define UART1_CFG                                                              \
  (ST_UARTConfig_t) {                                                          \
    &GPIOA9, &GPIOA10, UART_1, NO_PARITY, ONE_STOP_BIT, EIGHT_BITS,            \
        SW_FLOW_CTRL, TX_RX_MODE, BAUD_RATE_115200, UART_IRQ_DISABLE           \
  }

/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
typedef enum { UART_1 = 0, UART_2, UART_3 } EN_UARTX_t;

typedef enum { NO_PARITY = 0, PARITY_ODD, PARITY_EVEN } EN_PARITY_t;

typedef enum {
  HALF_STOP_BIT,
  ONE_STOP_BIT,
  ONE_HALF_STOP_BIT,
  TWO_STOP_BITS
} EN_STOP_BIT_t;

typedef enum { EIGHT_BITS, NINE_BITS } EN_PAYLOAD_LENGTH_t;

typedef enum {
  SW_FLOW_CTRL = 0,
  HW_FLOW_CTRL_RTS,
  HW_FLOW_CTRL_CTS,
  HW_FLOW_CTRL_RTS_CTS
} EN_FLOW_CTRL_t;

typedef enum { TX_MODE, RX_MODE, TX_RX_MODE } EN_UART_MODE_t;

typedef enum {
  BAUD_RATE_2400    = 2400,
  BAUD_RATE_9600    = 9600,
  BAUD_RATE_19200   = 19200,
  BAUD_RATE_57600   = 57600,
  BAUD_RATE_115200  = 115200,
  BAUD_RATE_230400  = 230400,
  BAUD_RATE_460800  = 460800,
  BAUD_RATE_921600  = 921600,
  BAUD_RATE_2250000 = 2250000,
  BAUD_RATE_4500000 = 4500000,
} EN_BAUD_RATE_t;

typedef enum {
  UART_IRQ_DISABLE = -1,
  UART_IRQ_ORE     = 0,
  UART_IRQ_RXNE    = 5,
  UART_IRQ_TC      = 6,
  UART_IRQ_TXE     = 7,
  UART_IRQ_PE      = 8
} EN_UART_IRQ_t;

typedef struct {
  ST_GPIOConfig_t*	const pSetTxPin;
  ST_GPIOConfig_t*	const pSetRxPin;
  EN_UARTX_t 	   	usartNumber;
  EN_PARITY_t 	        parityCheck;
  EN_STOP_BIT_t   	stopBit;
  EN_PAYLOAD_LENGTH_t  payLoadSize;
  EN_FLOW_CTRL_t 	flowCtrl;
  EN_UART_MODE_t 	Mode;
  EN_BAUD_RATE_t 	Baud;
  EN_UART_IRQ_t 	Irq;
  void (*callBackFunctionUart)(void);
} ST_UARTConfig_t;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
ST_UARTConfig_t *const UART_ConfigGet(void);

#endif /* INCLUDES_USART_CFG_H_ */

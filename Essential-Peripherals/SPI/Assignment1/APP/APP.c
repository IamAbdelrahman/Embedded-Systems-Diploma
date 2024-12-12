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

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint16_t data;

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern void Delay(vuint32_t);
extern ST_UARTIrqSrc_t uartIrqSrc;

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void UART_CallBack(ST_UARTIrqSrc_t);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
#if SPI_MODE == MASTER
void UART_CallBack(ST_UARTIrqSrc_t irqSrc) {
	if (irqSrc.RXNE) {
		UART_ReceiveData(UART_1, &data);
		UART_SendData(UART_1, &data);
		GPIO_PinWrite(PORTA, PIN4, LOW);
		SPI_SendData(SPI_1, &data);
		GPIO_PinWrite(PORTA, PIN4, HIGH);
	}
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
	RCC_Init(RCC_ConfigGet());
	ST_UARTConfig_t *pUART = UART_ConfigGet();
	pUART->callBackFunctionUart = UART_CallBack;
	UART_Init(pUART);
    SPI_Init(SPI_ConfigGet());
    /* Set NSS Pin */
    GPIO_PinWrite(PORTA, PIN4, HIGH);
}

void APP_Start(void) {
	;
}

#elif SPI_MODE == SLAVE
void APP_Init(void) {

}

void APP_Start (void) {

}
#endif

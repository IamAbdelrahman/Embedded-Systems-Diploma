/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *  @description: Send string asynchronously
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint8_t *TX_Buffer;
extern bool TX_Flag;
extern void (*gPf_IRQ_Callback_Usart)(void);

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint8_t Buffer[100];
vuint32_t x = 0;
static vuint8_t i = 1;

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void UART_CallBack(void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
void UART_CallBack(void) {
    if (TX_Buffer[i] != '\0')
        UART_TX_NoBlock(TX_Buffer[i++]);
    else
        i = 1, TX_Flag = 1;
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
    UART_Init(UART_ConfigGet());
    LCD_Init();
    gPf_IRQ_Callback_Usart = UART_CallBack;
    UART_TXStringAsync((vuint8_t*) "Abdo");
}

void APP_Start(void) {
    LCD_XY(1, 0);
    UART_ReceiveString(Buffer);
    LCD_WriteString(Buffer);
    LCD_ClearScreen();
    LCD_XY(2, 0);
    LCD_WriteInt(x++);
    if (x == 10) x = 0;
    _delay_ms(200);
}





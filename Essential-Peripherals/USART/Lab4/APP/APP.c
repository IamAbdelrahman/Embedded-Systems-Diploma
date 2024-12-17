/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.c
 *	@brief The implementation of the application driver
 *  @description: Receive strings asynchronously
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "APP.h"

/*- LOCAL MACROS
-----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/
extern vuint8_t *RX_Buffer;
extern void (*gPf_IRQ_Callback_Usart)(void);
extern vuint8_t UART_RX_NoBlock(void);
/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
vuint8_t Buffer[100];
vuint8_t data;
vuint32_t x = 0;
static vuint8_t i = 0;
static bool EOT_Flag = false;

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/
void UART_CallBack(void);

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/
void UART_CallBack(void) {
    data = UART_RX_NoBlock();
    if (data != '\r') 
        RX_Buffer[i++] = data;
    else 
        RX_Buffer[i] = '\0', EOT_Flag = true, i = 0;
}

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
void APP_Init(void) {
    UART_Init(UART_ConfigGet());
    LCD_Init();
    gPf_IRQ_Callback_Usart = UART_CallBack;
    UART_RXStringAsync(Buffer);
}

void APP_Start(void) {
    if (EOT_Flag) {
        LCD_XY(1, 0);
        LCD_WriteString(Buffer);
        LCD_ClearScreen();
        EOT_Flag = false;
    }
    LCD_XY(2, 0);
    LCD_WriteInt(x++);
    if (x == 10) x = 0;
    _delay_ms(200);
}

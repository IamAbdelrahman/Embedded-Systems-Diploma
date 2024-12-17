/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: USART.c
 *	@brief The implementation for the USART peripheral
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "USART.h"
#include "EXTI.h"
#include "QUEUE.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/
#define TERMINATOR  '\r' 
#define USARTDIV(Fosc, Baud) (((Fosc) / (16.0F * Baud)) - 1)

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
void (*gPf_IRQ_Callback_Usart)(void) = NULL;

typedef struct {
    vuint8_t payLoad_9 : 1;
    vuint8_t pollingTx : 1;
    vuint8_t pollingRx : 1;
    vuint8_t Parity : 1;
} ST_Flags_t;

ST_Flags_t Flags = {0U, 0U, 0U, 0U};
vuint8_t *TX_Buffer, *RX_Buffer;
bool TX_Flag = true, RX_Flag = true;

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE A POINTER TO USART  */
static ST_USART_t * const pUSART = USART;

/*- DEFINE A CIRCULAR FIFO */
static ST_Queue_t Q;
static QueueEntry data;

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void UART_InitPins(ST_UARTConfig_t * const);
void UART_CalculateBaudRate(EN_BAUD_RATE_t);
void UART_ModeCfg(EN_UART_MODE_t);
void UART_ParityCfg(EN_PARITY_t);
void UART_StopBitsCfg(EN_STOP_BIT_t);
void UART_PayloadCfg(EN_PAYLOAD_LENGTH_t);
void UART_IRQCfg(EN_UART_IRQ_t);
void USART_Flush(void);
static inline void TXC_EnableIRQ(void);
static inline void TXC_DisableIRQ(void);
static inline void RXC_EnableIRQ(void);
static inline void RXC_DisableIRQ(void);
void UART_TX_NoBlock(vuint8_t);
vuint8_t UART_RX_NoBlock(void);
void UART_SendStringAsync(vuint8_t*);
void UART_ReceiveStringAsync(vuint8_t*);

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
void UART_InitPins(ST_UARTConfig_t * const configPtr) {
    GPIO_Init(configPtr->pSetTxPin, 1);
    GPIO_Init(configPtr->pSetRxPin, 1);
}

void UART_CalculateBaudRate(EN_BAUD_RATE_t Baud) {
    volatile float Div = USARTDIV(F_CPU, Baud);
    vuint16_t baudValue = 0;
    if (Div - (vuint16_t) Div >= 0.5) {
        baudValue = (vuint16_t) Div + 1;
        UBRRL = (vuint8_t) baudValue; /* Lower Nibble */
        CLR_BIT(pUSART->UCSRC, 7);
        UBRRH = (vuint8_t) (baudValue >> 8); /* Higher Nibble */
    } else {
        baudValue = (vuint16_t) Div;
        UBRRL = (vuint8_t) baudValue;
        CLR_BIT(pUSART->UCSRC, 7);
        UBRRH = (vuint8_t) (baudValue >> 8);
    }
}

void UART_ModeCfg(EN_UART_MODE_t Mode) {
    switch (Mode) {
        case TX_MODE:
            SET_BIT(pUSART->UCSRB, 3);
            SET_BIT(pUSART->UCSRA, 6);
            break;
        case RX_MODE:
            SET_BIT(pUSART->UCSRB, 4);
            break;
        case TX_RX_MODE:
            SET_BIT(pUSART->UCSRB, 3);
            SET_BIT(pUSART->UCSRB, 4);
            break;
        default:
            break;
    }
}

void UART_ParityCfg(EN_PARITY_t Parity) {
    SET_BIT(pUSART->UCSRC, 7); // Enable UCSRC selection
    switch (Parity) {
        case NO_PARITY:
            CLR_2BITS(pUSART->UCSRC, 4);
            Flags.Parity = 0;
            break;
        case PARITY_ODD:
            SET_2BITS(pUSART->UCSRC, 4);
            Flags.Parity = 1;
            break;
        case PARITY_EVEN:
            WRITE_2BITS(pUSART->UCSRC, 0b10, 4);
            Flags.Parity = 1;
            break;
        default:
            break;
    }
}

void UART_StopBitsCfg(EN_STOP_BIT_t stopBit) {
    SET_BIT(pUSART->UCSRC, 7);
    if (stopBit == TWO_STOP_BITS) {
        SET_BIT(pUSART->UCSRC, 3);
    } else {
        CLR_BIT(pUSART->UCSRC, 3);
    }
}

void UART_PayloadCfg(EN_PAYLOAD_LENGTH_t Size) {
    SET_BIT(pUSART->UCSRC, 7); // Enable UCSRC selection
    switch (Size) {
        case FIVE_BITS:
            CLR_2BITS(pUSART->UCSRC, 1);
            CLR_BIT(pUSART->UCSRB, 2);
            break;
        case SIX_BITS:
            WRITE_2BITS(pUSART->UCSRC, 0b01, 1);
            CLR_BIT(pUSART->UCSRB, 2);
            break;
        case SEVEN_BITS:
            WRITE_2BITS(pUSART->UCSRC, 0b10, 1);
            CLR_BIT(pUSART->UCSRB, 2);
            break;
        case EIGHT_BITS:
            SET_2BITS(pUSART->UCSRC, 1);
            CLR_BIT(pUSART->UCSRB, 2);
            break;
        case NINE_BITS:
            SET_2BITS(pUSART->UCSRC, 1);
            SET_BIT(pUSART->UCSRB, 2);
            Flags.payLoad_9 = 1;
            break;
        default:
            break;
    }
}

void UART_IRQCfg(EN_UART_IRQ_t Irq) {
    switch (Irq) {
        case UART_IRQ_DISABLE:
            cli();
            Flags.pollingTx = 1U;
            Flags.pollingRx = 1U;
            break;
        case UART_IRQ_TXC:
            SET_BIT(pUSART->UCSRB, 6);
            sei();
            break;
        case UART_IRQ_UDRE:
            SET_BIT(pUSART->UCSRB, 5);
            sei();
            break;
        case UART_IRQ_RXC:
            SET_BIT(pUSART->UCSRB, 7);
            sei();
            break;
        case UART_IRQ_TXC_RXC:
            SET_BIT(pUSART->UCSRB, 6);
            SET_BIT(pUSART->UCSRB, 7);
            sei();
        default:
            break;
    }
}

ISR(USART_RXC) {
    gPf_IRQ_Callback_Usart();
}

ISR(USART_UDRE) {
    gPf_IRQ_Callback_Usart();
}

ISR(USART_TXC) {
    gPf_IRQ_Callback_Usart();
}

void USART_Flush(void) {
    vuint8_t dummy;
    while (READ_BIT(pUSART->UCSRA, 7))
        dummy = pUSART->UDR;
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/

void UART_Init(ST_UARTConfig_t * const configPtr) {
    /* Initialize UART GPIO Pins */
    UART_InitPins(configPtr);

    /* Calculate the UART baud rate */
    UART_CalculateBaudRate(configPtr->Baud);

    /* Configure UART Modes */
    UART_ModeCfg(configPtr->Mode);

    /* Configure UART Parity */
    UART_ParityCfg(configPtr->parityCheck);

    /* Configure UART Stop Bits */
    UART_StopBitsCfg(configPtr->stopBit);

    /* Configure UART Payload Length */
    UART_PayloadCfg(configPtr->payLoadSize);

    /* Configure UART IRQ */
    UART_IRQCfg(configPtr->Irq);
    gPf_IRQ_Callback_Usart = configPtr->callBackFunctionUart;
}

void UART_SendData(vuint16_t *pBuffer) {
    /* Wait for empty transmitter buffer */
    if (Flags.pollingTx) {
        while (!READ_BIT(pUSART->UCSRA, 5))
            ;
    }

    if (Flags.payLoad_9) {
        WRITE_BIT(pUSART->UCSRB, READ_BIT(*pBuffer, 8), 0);
    }
    pUSART->UDR = (*pBuffer & (vuint8_t) 0XFF);
}

EN_UART_STATUS_t UART_ReceiveData(vuint16_t *pBuffer) {
    /* Wait for data to be received completely */
    if (Flags.pollingRx) {
        while (!READ_BIT(pUSART->UCSRA, 7))
            ;
    }
    /* Check the error flags first before reading the data */
    if (READ_3BITS(pUSART->UCSRA, 2)) {
        USART_Flush();
        return UART_ERROR;
    }
    if (Flags.payLoad_9) {
        vuint8_t resH = READ_BIT(pUSART->UCSRB, 1);
        vuint8_t resL = (pUSART->UDR & (vuint16_t) 0XFF);
        *pBuffer = (resL | (resH << 8));
    } else {
        *pBuffer = (pUSART->UDR & (vuint16_t) 0XFF);
    }
    return UART_SUCCESS;
}

void UART_SendString(vuint8_t *pStr) {
    while (*pStr > 0) {
        UART_SendData(pStr++);
    }
    vuint8_t defaultStop = TERMINATOR;
    UART_SendData(&defaultStop);
}


void UART_ReceiveString(vuint8_t *pStr) {
    Queue_init(&Q);
    vuint8_t data;
    /* Store the string in a queue */
    do {
        UART_ReceiveData(&data);
        Enqueue(data, &Q);
    } while (data != TERMINATOR);

    /* Dequeue the string and put it into another buffer */
    Dequeue(pStr, &Q);
    while (Q.size && *pStr != TERMINATOR) {
        Dequeue(++pStr, &Q);
    }
    *pStr = '\0';
}

void UART_SendIntNum(vint32_t Num) {
    vint8_t Size = 0, i, sign = '-', zero = 48;
    vuint8_t Str[10];
    if (Num > 0) {
        while (Num != 0) {
            Str[Size++] = Num % 10;
            Num /= 10;
        }
        for (i = Size - 1; i >= 0; i--) {
            vuint8_t data = Str[i] + 48;
            UART_SendData(&data);
        }
    } else if (Num < 0) {
        Num *= -1;
        while (Num != 0) {
            Str[Size++] = Num % 10;
            Num /= 10;
        }
        UART_SendData(&sign);
        for (i = Size - 1; i >= 0; i--) {
            vuint8_t data = Str[i] + 48;
            UART_SendData(&data);
        }
    } else {
        UART_SendData(&zero);
    }
    vuint8_t defaultStop = TERMINATOR;
    UART_SendData(&defaultStop);
}

void UART_ReceiveIntNum (vuint32_t *pNum) {
    *pNum = 0;
    vuint8_t Str[10] = {0}, i = 0;
    vuint32_t p = 1;
    while (true) {
        UART_ReceiveData(&Str[i]);
        if (Str[i] == TERMINATOR)
            break;
        i++;
    }
    while (i--) {
        *pNum += (p * (Str[i] - '0'));
        p *= 10;
    }
}

/* No-Block Mechanism */

inline void TXC_EnableIRQ(void) {
    SET_BIT(pUSART->UCSRB, 6);
}

inline void TXC_DisableIRQ(void) {
    CLR_BIT(pUSART->UCSRB, 6);
}

inline void RXC_EnableIRQ(void) {
    SET_BIT(pUSART->UCSRB, 7);
}

inline void RXC_DisableIRQ(void) {
    CLR_BIT(pUSART->UCSRB, 6);
}

inline void UART_TX_NoBlock(vuint8_t data) {
    if(READ_BIT(pUSART->UCSRA, 5))
    pUSART->UDR = data;
}

inline vuint8_t UART_RX_NoBlock(void) {
    if(READ_BIT(pUSART->UCSRA, 7))
        return (pUSART->UDR);
}

void UART_TXStringAsync(vuint8_t* pStr) {
    if (TX_Flag) {
        TXC_EnableIRQ();
        sei();
        UART_TX_NoBlock(pStr[0]); /* Send first character */
        TX_Buffer = pStr;
        TX_Flag = false; /* TX operation is busy */
    }
}

void UART_RXStringAsync(vuint8_t* pStr) {
    if (RX_Flag) {
        RXC_EnableIRQ(); /* Enable RXC IRQ */
        sei();
        RX_Buffer = pStr;
        RX_Flag = false; /* RX operation is busy */
    }
}

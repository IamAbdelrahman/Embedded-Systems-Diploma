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
#include "inc/USART.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/
#define NUMBER_OF_USART 		3U
#define USARTDIV(pClk, Baud) 		(vuint32_t)((pClk) / (Baud * 16))
#define USARTDIV_MUL100(pClk, Baud) 	(vuint32_t)((25 * pClk) / (Baud * 4))
#define MANTISA_MUL100(pClk, Baud) 	(vuint32_t)(100 * USARTDIV(pClk, Baud))
#define MANTISA(pClk, Baud) 		(vuint32_t)(USARTDIV(pClk, Baud))
#define DIV_FRACTION(pClk, Baud)                                               \
  (vuint32_t)((USARTDIV_MUL100(pClk, Baud) - MANTISA_MUL100(pClk, Baud)) * 16 / 100)

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
void (*gPf_IRQ_Callback_Usart[3])(void) = {NULL, NULL, NULL};
typedef struct {
  vuint8_t payLoad_8 : 1;
  vuint8_t pollingTx : 1;
  vuint8_t pollingRx : 1;
  vuint8_t Parity    : 1;
} ST_Flags_t;

ST_Flags_t Flag = {1U, 1U, 1U, 1U};

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF GPIO INSTANCES */
static const ST_USART_t *const USARTx[NUMBER_OF_USART] = {USART1, USART2,
                                                          USART3};

/*- DEFINE A TABLE OF POINTER TO THE STATUS REGISTER */
static TYPE volatile *const Status[NUMBER_OF_USART] = {
    (TYPE *)&USARTx[0]->SR, (TYPE *)&USARTx[1]->SR, (TYPE *)&USARTx[2]->SR};

/*- DEFINE A TABLE OF POINTER TO THE DATA REGISTER */
static TYPE volatile *const Data[NUMBER_OF_USART] = {
    (TYPE *)&USARTx[0]->DR, (TYPE *)&USARTx[1]->DR, (TYPE *)&USARTx[2]->DR};

/*- DEFINE A TABLE OF POINTER TO THE BAUDRATE REGISTER */
static TYPE volatile *const baudRate[NUMBER_OF_USART] = {
    (TYPE *)&USARTx[0]->BRR,
    (TYPE *)&USARTx[1]->BRR,
    (TYPE *)&USARTx[2]->BRR,
};

/*- DEFINE A TABLE OF POINTER TO THE CONTROL REGISTER1 */
static TYPE volatile *const Control1[NUMBER_OF_USART] = {
    (TYPE *)&USARTx[0]->CR1, (TYPE *)&USARTx[1]->CR1, (TYPE *)&USARTx[2]->CR1};

/*- DEFINE A TABLE OF POINTER TO THE CONTROL REGISTER2 */
static TYPE volatile *const Control2[NUMBER_OF_USART] = {
    (TYPE *)&USARTx[0]->CR2, (TYPE *)&USARTx[1]->CR2, (TYPE *)&USARTx[2]->CR2};

/*- DEFINE A TABLE OF POINTER TO THE CONTROL REGISTER3 */
static TYPE volatile *const Control3[NUMBER_OF_USART] = {
    (TYPE *)&USARTx[0]->CR3, (TYPE *)&USARTx[1]->CR3, (TYPE *)&USARTx[2]->CR3};

/*- DEFINE A TABLE OF POINTER TO THE GUARD TIME AND PRESCALER REGISTER */
/*static TYPE volatile *const guardTime[NUMBER_OF_USART] = {
                (TYPE*) &USARTx[0]->GTPR, (TYPE*) &USARTx[1]->GTPR,
                (TYPE*) &USARTx[2]->GTPR };*/

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint32_t configSizeUsart;

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void CalculateBaud(EN_UARTX_t, EN_BAUD_RATE_t);

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
void CalculateBaud(EN_UARTX_t usartNumber, EN_BAUD_RATE_t Baud) {
  vuint32_t PClk1, PClk2;
  switch (usartNumber) {
  case UART_1:
    PClk2 = RCC_GetPClk2();
    WRITE_NIBBLE_VALUE(*(baudRate[UART_1]), DIV_FRACTION(PClk2, Baud), 0);
    WRITE_VALUE(*(baudRate[UART_1]), MANTISA(PClk2, Baud), 4);
    break;
  case UART_2:
    PClk1 = RCC_GetPClk1();
    WRITE_NIBBLE_VALUE(*(baudRate[UART_2]), DIV_FRACTION(PClk1, Baud), 0);
    WRITE_VALUE(*(baudRate[UART_2]), MANTISA(PClk1, Baud), 4);
    break;
  case UART_3:
    PClk1 = RCC_GetPClk1();
    WRITE_NIBBLE_VALUE(*(baudRate[UART_3]), DIV_FRACTION(PClk1, Baud), 0);
    WRITE_VALUE(*(baudRate[UART_3]), MANTISA(PClk1, Baud), 4);
    break;
  default:
    break;
  }
}

void USART1_IRQHandler(void) { gPf_IRQ_Callback_Usart[0](); }

void USART2_IRQHandler(void) { gPf_IRQ_Callback_Usart[1](); }

void USART3_IRQHandler(void) { gPf_IRQ_Callback_Usart[2](); }

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: UART_Init
 * Synatax: void UART_Init(const ST_UARTConfig_t* const configPtr)
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
void UART_Init(ST_UARTConfig_t *const configPtr) {
  vuint8_t i = 0;
  for (i = 0; i < configSizeUsart; i++) {
    /*- Set the UART pins */
    GPIO_Init(configPtr[i].pSetTxPin);
    GPIO_Init(configPtr[i].pSetRxPin);

    /*- Enable the UART module */
    SET_BIT(*(Control1[configPtr[i].usartNumber]), 13);

    /*- Configure the UART mode
     * NOTE: there is a 1 bit-time delay before the transmission starts.
     * */
    switch (configPtr[i].Mode) {
    case TX_MODE:
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 3);
      while (!READ_BIT(*(Control1[configPtr[i].usartNumber]), 3))
        ;
      break;
    case RX_MODE:
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 2);
      break;
    case TX_RX_MODE:
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 2);
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 3);
      while (!READ_BIT(*(Control1[configPtr[i].usartNumber]), 3))
        ;
      break;
    default:
      break;
    }

    /*- Configure the UART parity */
    switch (configPtr[i].parityCheck) {
    case NO_PARITY:
      CLR_BIT(*(Control1[configPtr[i].usartNumber]), 10);
      Flag.Parity = 0;
      break;
    case PARITY_ODD:
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 10);
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 9);
      Flag.Parity = 1;
      break;
    case PARITY_EVEN:
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 10);
      CLR_BIT(*(Control1[configPtr[i].usartNumber]), 9);
      Flag.Parity = 1;
      break;
    default:
      break;
    }

    /*- Configure the UART stop bits */
    switch (configPtr[i].stopBit) {
    case HALF_STOP_BIT:
      WRITE_2BITS(*(Control2[configPtr[i].usartNumber]), 0b01, 12);
      break;
    case ONE_STOP_BIT:
      WRITE_2BITS(*(Control2[configPtr[i].usartNumber]), 0b00, 12);
      break;
    case ONE_HALF_STOP_BIT:
      WRITE_2BITS(*(Control2[configPtr[i].usartNumber]), 0b11, 12);
      break;
    case TWO_STOP_BITS:
      WRITE_2BITS(*(Control2[configPtr[i].usartNumber]), 0b10, 12);
      break;
    default:
      break;
    }

    /*- Configure the UART payload length */
    switch (configPtr[i].payLoadSize) {
    case EIGHT_BITS:
      CLR_BIT(*(Control1[configPtr[i].usartNumber]), 12);
      Flag.payLoad_8 = 1;
      break;
    case NINE_BITS:
      SET_BIT(*(Control1[configPtr[i].usartNumber]), 12);
      Flag.payLoad_8 = 0;
      break;
    default:
      break;
    }

    /*- Configure the UART flow Control */
    switch (configPtr[i].flowCtrl) {
    case SW_FLOW_CTRL:
      CLR_BIT(*(Control3[configPtr[i].usartNumber]), 8);
      CLR_BIT(*(Control3[configPtr[i].usartNumber]), 9);
      break;
    case HW_FLOW_CTRL_RTS:
      SET_BIT(*(Control3[configPtr[i].usartNumber]), 8);
      break;
    case HW_FLOW_CTRL_CTS:
      SET_BIT(*(Control3[configPtr[i].usartNumber]), 9);
      break;
    case HW_FLOW_CTRL_RTS_CTS:
      SET_BIT(*(Control3[configPtr[i].usartNumber]), 8);
      SET_BIT(*(Control3[configPtr[i].usartNumber]), 9);
      break;
    default:
      break;
    }

    /*- Calculate the UART baud rate */
    CalculateBaud(configPtr[i].usartNumber, configPtr[i].Baud);

    /* Configure UART IRQ */
    gPf_IRQ_Callback_Usart[configPtr[i].usartNumber] =
        configPtr[i].callBackFunctionUart;
    switch (configPtr[i].usartNumber) {
    case UART_1:
      if (configPtr[i].Irq != UART_IRQ_DISABLE) {
        if (configPtr[i].Irq != UART_IRQ_ORE)
          SET_BIT(*(Control1[UART_1]), configPtr[i].Irq);
        else
          SET_BIT(*(Control3[UART_1]), configPtr[i].Irq);
        NVIC_EnableIRQ(USART1_IRQ);
        (configPtr[i].Irq == UART_IRQ_RXNE)
            ? Flag.pollingRx = 0
            : (configPtr[i].Irq == UART_IRQ_TXE) ? Flag.pollingTx = 0 : 0U;
      }
      break;
    case UART_2:
      if (configPtr[i].Irq != UART_IRQ_DISABLE) {
        if (configPtr[i].Irq != UART_IRQ_ORE)
          SET_BIT(*(Control1[UART_2]), configPtr[i].Irq);
        else
          SET_BIT(*(Control3[UART_2]), configPtr[i].Irq);
        NVIC_EnableIRQ(USART2_IRQ);
        (configPtr[i].Irq == UART_IRQ_RXNE)
            ? Flag.pollingRx = 0
            : (configPtr[i].Irq == UART_IRQ_TXE) ? Flag.pollingTx = 0 : 0U;
      }
      break;
    case UART_3:
      if (configPtr[i].Irq != UART_IRQ_DISABLE) {
        if (configPtr[i].Irq != UART_IRQ_ORE)
          SET_BIT(*(Control1[UART_3]), configPtr[i].Irq);
        else
          SET_BIT(*(Control3[UART_3]), configPtr[i].Irq);
        NVIC_EnableIRQ(USART3_IRQ);
        (configPtr[i].Irq == UART_IRQ_RXNE)
            ? Flag.pollingRx = 0
            : (configPtr[i].Irq == UART_IRQ_TXE) ? Flag.pollingTx = 0 : 0U;
      }
      break;
    default:
      break;
    }
  }
}

/************************************************************************
 * Service Name: UART_Reset
 * Synatax: void UART_Reset(EN_UARTX_t usartNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset UART module.
 * @param (in): usartNumber represents the instance number of the UART
 *peripheral
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void UART_Reset(EN_UARTX_t usartNumber) {
  switch (usartNumber) {
  case UART_1:
    RCC_ModuleReset(RCC_USART1);
    NVIC_DisableIRQ(USART1_IRQ);
    break;
  case UART_2:
    RCC_ModuleReset(RCC_USART2);
    NVIC_DisableIRQ(USART2_IRQ);
    break;
  case UART_3:
    RCC_ModuleReset(RCC_USART3);
    NVIC_DisableIRQ(USART3_IRQ);
    break;
  default:
    break;
  }
}

/************************************************************************
 * Service Name: UART_SendData
 * Synatax: void UART_SendData(EN_UARTX_t usartNumber, vuint16_t* pBuffer)
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
void UART_SendData(EN_UARTX_t usartNumber, vuint16_t *pBuffer) {
  if (Flag.pollingTx) {
    while (!READ_BIT((*Status[usartNumber]), 7))
      ;
  }

  if (Flag.payLoad_8) {
    *Data[usartNumber] = (*pBuffer & (vuint16_t)0xFF);
  } else {
    *Data[usartNumber] = (*pBuffer & (vuint16_t)0x01FF);
  }
}

/************************************************************************
 * Service Name: UART_ReceiveData
 * Synatax: void UART_ReceiveData(EN_UARTX_t usartNumber, vuint16_t* pBuffer)
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
void UART_ReceiveData(EN_UARTX_t usartNumber, vuint16_t *pBuffer) {
  if (Flag.pollingRx) {
    while (!READ_BIT((*Status[usartNumber]), 5))
      ;
  }

  if (Flag.payLoad_8) {
    if (Flag.Parity) {
      *pBuffer = (*Data[usartNumber] & (vuint16_t)0X7F);
    } else {
      *pBuffer = (*Data[usartNumber] & (vuint16_t)0XFF);
    }
  } else {
    if (Flag.Parity) {
      *pBuffer = (*Data[usartNumber] & (vuint16_t)0XFF);
    } else {
      *pBuffer = (*Data[usartNumber] & (vuint16_t)0X01FF);
    }
  }
}

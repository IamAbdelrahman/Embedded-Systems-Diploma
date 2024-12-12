/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: SPI.c
 *	@brief The implementation for the SPI peripheral
 *
 *****************************************************************************/

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "../inc/SPI.h"
#include "../../Inc/Data_Structures/Queue.h"

/*- LOCAL MACROS
 -----------------------------------------------------------------------*/
#define NUMBER_OF_SPI 			2U
#define SPI_TYPE				vuint16_t

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/
/*- DECLARE A FIFO BUFFER TO PROCESS STRINGS */
ST_Queue_t Fifo;
ST_SPI_IRQSrc_t irqSrc = {1U, 0U, 0U, 0U };
void (*gPf_IRQ_Callback_Spi[3])(ST_SPI_IRQSrc_t) = {NULL, NULL, NULL };
typedef struct {
	vuint8_t pollingTx :1;
	vuint8_t pollingRx :1;
	vuint8_t spiNo :1;
} ST_Flags_t;

ST_Flags_t SpiFlag = { 1U, 1U, 0U };

/*- GLOBAL STATIC VARIABLES
 -----------------------------------------------------------------------*/
/*- DEFINE AN ARRAY OF GPIO INSTANCES */
static const ST_SPI_t *const SPIx[NUMBER_OF_SPI] = { SPI1, SPI2 };

/*- DEFINE A TABLE OF POINTER TO THE STATUS REGISTER */
static SPI_TYPE volatile *const Status[NUMBER_OF_SPI] = {
		(SPI_TYPE*) &SPIx[0]->SR, (SPI_TYPE*) &SPIx[1]->SR };

/*- DEFINE A TABLE OF POINTER TO THE DATA REGISTER */
static SPI_TYPE volatile *const Data[NUMBER_OF_SPI] = {
		(SPI_TYPE*) &SPIx[0]->DR, (SPI_TYPE*) &SPIx[1]->DR };

/*- DEFINE A TABLE OF POINTER TO THE CONTROL REGISTER1 */
static SPI_TYPE volatile *const Control1[NUMBER_OF_SPI] = {
		(SPI_TYPE*) &SPIx[0]->CR1, (SPI_TYPE*) &SPIx[1]->CR1 };

/*- DEFINE A TABLE OF POINTER TO THE CONTROL REGISTER2 */
static SPI_TYPE volatile *const Control2[NUMBER_OF_SPI] = {
		(SPI_TYPE*) &SPIx[0]->CR2, (SPI_TYPE*) &SPIx[1]->CR2 };

/*- GLOBAL EXTERN VARIABLES
 -----------------------------------------------------------------------*/
extern vuint32_t configSizeSpi;

/*- LOCAL FUNCTIONS PROTOTYPES
 -----------------------------------------------------------------------*/
void ConfigBaud(EN_SPIX_t, EN_BAUD_t);

/*- LOCAL FUNCTIONS IMPLEMENTATION
 -----------------------------------------------------------------------*/
void ConfigBaud(EN_SPIX_t spiNumber, EN_BAUD_t Baud) {
	/* Assume pClk2 = 8 MHz */
	switch (spiNumber) {
	case SPI_1:
		WRITE_3BITS(*Control1[SPI_1], Baud, 3);
		break;
	case SPI_2:
		WRITE_3BITS(*Control1[SPI_2], Baud, 3);
		break;
	default:
		break;
	}
}

void SPI1_IRQHandler(void) {
	irqSrc.TXE = READ_BIT((*Status[SPI_1]), 1);
	irqSrc.RXNE = READ_BIT((*Status[SPI_1]), 0);
	irqSrc.ERR = READ_BIT((*Status[SPI_1]), 4);
	gPf_IRQ_Callback_Spi[0](irqSrc);
}

void SPI2_IRQHandler(void) {
	irqSrc.TXE = READ_BIT((*Status[SPI_2]), 1);
	irqSrc.RXNE = READ_BIT((*Status[SPI_2]), 0);
	irqSrc.ERR = READ_BIT((*Status[SPI_2]), 4);
	gPf_IRQ_Callback_Spi[1](irqSrc);
}

/*- APIs IMPLEMENTATION
 -----------------------------------------------------------------------*/
void SPI_Init(ST_SPIConfig_t *const configPtr) {
	vuint8_t i = 0;
	for (i = 0; i < configSizeSpi; i++) {
		/*- Set the SPI pins */
		GPIO_Init(configPtr[i].pSetMosiPin, 1);
		GPIO_Init(configPtr[i].pSetMisoPin, 1);
		GPIO_Init(configPtr[i].pSetSckPin, 1);
		GPIO_Init(configPtr[i].pSetNssPin, 1);

		/*- Calculate the SPI baud rate */
		ConfigBaud(configPtr[i].spiNumber, configPtr[i].Baud);

		/*- Eable the SPI CLK Signal */
		WRITE_BIT(*Control1[configPtr[i].spiNumber], configPtr[i].clkPol, 1);
		WRITE_BIT(*Control1[configPtr[i].spiNumber], configPtr[i].clkPha, 0);

		/*- Configure the SPI payload length */
		switch (configPtr[i].payLoadSize) {
		case ONE_BYTE:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 11);
			break;
		case TWO_BYTES:
			SET_BIT(*(Control1[configPtr[i].spiNumber]), 11);
			break;
		default:
			break;
		}

		/*- Configure the SPI payload's frame formate */
		switch (configPtr[i].frameFormat) {
		case LSB_FIRST:
			SET_BIT(*(Control1[configPtr[i].spiNumber]), 7);
			break;
		case MSB_FIRST:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 7);
			break;
		default:
			break;
		}

		/*- Configure the SPI NSS pin */
		switch (configPtr[i].slaveSelectPin) {
		case NSS_MASTER_HW_DISABLE:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 9);
			CLR_BIT(*(Control2[configPtr[i].spiNumber]), 2);
			break;
		case NSS_MASTER_HW_ENABLE:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 9);
			SET_BIT(*(Control2[configPtr[i].spiNumber]), 2);
			break;
		case NSS_SLAVE_HW:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 9);
			break;
		case NSS_SW_SET:
			SET_BIT(*(Control1[configPtr[i].spiNumber]), 9);
			SET_BIT(*(Control1[configPtr[i].spiNumber]), 8);
			break;
		case NSS_SW_RESET:
			SET_BIT(*(Control1[configPtr[i].spiNumber]), 9);
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 8);
			break;
		default:
			break;
		}

		/*- Configure the SPI mode*/
		switch (configPtr[i].Mode) {
		case MASTER_MODE:
			SET_BIT(*(Control1[configPtr[i].spiNumber]), 2);
			break;
		case SLAVE_MODE:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 2);
			break;
		default:
			break;
		}

		/*- Configure the SPI communication mode */
		switch (configPtr[i].commMode) {
		case FULL_DUPLEX:
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 15);
			CLR_BIT(*(Control1[configPtr[i].spiNumber]), 10);
			break;
		case HALF_DUPLEX:
			/*
			 * TODO:
			 * HALF-DUPLEX AND SIMPLEX

			 SET_BIT(*(Control1[configPtr[i].spiNumber]), 15);
			 CLR_BIT(*(Control1[configPtr[i].spiNumber]), 10);
			 break;
			 case SIMPLEX:
			 break;
			 */
		default:
			break;
		}

		/* Configure SPI IRQ */
		gPf_IRQ_Callback_Spi[configPtr[i].spiNumber] =
				configPtr[i].callBackFunctionSpi;
		switch (configPtr[i].spiNumber) {
		case SPI_1:
			if (configPtr[i].Irq != SPI_IRQ_DISABLE) {
				SET_BIT(*(Control2[SPI_1]), configPtr[i].Irq);
				NVIC_EnableIRQ(SPI1_IRQ);
				(configPtr[i].Irq == SPI_IRQ_RXNE) ? SpiFlag.pollingRx = 0 :
				(configPtr[i].Irq == SPI_IRQ_TXE) ? SpiFlag.pollingTx = 0 : 0U;
				irqSrc.None = 0U;
			}
			break;
		case SPI_2:
			if (configPtr[i].Irq != SPI_IRQ_DISABLE) {
				SET_BIT(*(Control2[SPI_2]), configPtr[i].Irq);
				NVIC_EnableIRQ(SPI2_IRQ);
				(configPtr[i].Irq == SPI_IRQ_RXNE) ? SpiFlag.pollingRx = 0 :
				(configPtr[i].Irq == SPI_IRQ_TXE) ? SpiFlag.pollingTx = 0 : 0U;
				irqSrc.None = 0U;
			}
			break;
		default:
			break;
		}

		/*- Enable the SPI module */
		SET_BIT(*(Control1[configPtr[i].spiNumber]), 6);
	}
}

void SPI_Reset(EN_SPIX_t spiNumber) {
	switch (spiNumber) {
	case SPI_1:
		RCC_ModuleReset(RCC_SPI1);
		NVIC_DisableIRQ(SPI1_IRQ);
		break;
	case SPI_2:
		RCC_ModuleReset(RCC_SPI2);
		NVIC_DisableIRQ(SPI2_IRQ);
		break;
	default:
		break;
	}
}

void SPI_SendData(EN_SPIX_t spiNumber, vuint16_t *pBuffer) {
	if (SpiFlag.pollingTx) {
		while (!READ_BIT((*Status[spiNumber]), 1))
			;
	}
	*Data[spiNumber] = (*pBuffer & (vuint16_t) 0XFFFF);
}

void SPI_ReceiveData(EN_SPIX_t spiNumber, vuint16_t *pBuffer) {
	if (SpiFlag.pollingRx) {
		while (!READ_BIT((*Status[spiNumber]), 0))
			;
	}

	*pBuffer = (*Data[spiNumber] & (vuint16_t) 0XFFFF);
}

vuint16_t SPI_TX_RX (EN_SPIX_t spiNumber, vuint16_t *pBuffer) {
	if (SpiFlag.pollingTx) {
		while (!READ_BIT((*Status[spiNumber]), 1))
			;
	}
	*Data[spiNumber] = (*pBuffer & (vuint16_t) 0XFFFF);
	if (SpiFlag.pollingRx) {
		while (!READ_BIT((*Status[spiNumber]), 0))
			;
	}

	return ((*Data[spiNumber] & (vuint16_t) 0XFFFF));
}

void SPI_SendString(vuint8_t *pStr) {
	while (*pStr > 0) {
		SPI_SendData(SpiFlag.spiNo, pStr++);
	}
	vuint8_t defaultStop = TERMINATOR;
	SPI_SendData(SpiFlag.spiNo, &defaultStop);
}

void SPI_ReceiveString(vuint8_t *pStr) {
	Queue_init(&Fifo);
	vuint8_t data;
	/* Store the string in a queue */
	do {
		SPI_ReceiveData(SpiFlag.spiNo, &data);
		Enqueue(data, &Fifo);
	} while (data != TERMINATOR);

	/* Dequeue the string and put it into another buffer */
	Dequeue(pStr, &Fifo);
	while (Fifo.size && *pStr != TERMINATOR) {
		Dequeue(++pStr, &Fifo);
	}
	*pStr = '\0';
}

void SPI_SendIntNum(vuint32_t Num) {
	vuint8_t *pByt = (vuint8_t*) &Num, i = 0;
	for (i = 0; i < 4; i++) {
		SPI_SendData(SpiFlag.spiNo, pByt++);
	}
}

void SPI_ReceiveIntNum(vuint32_t *pNum) {
	vuint8_t *pByt, i = 0;
	pByt = (vuint8_t*) pNum;
	for (i = 0; i < 4; i++)
		SPI_ReceiveData(SpiFlag.spiNo, pByt++);
}

/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: SPI_Cfg.h
 *	@brief This module contains interface definitions for the
 *	SPI configuration related to the LQFP48 package.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the SPI configuration table.
 *****************************************************************************/
#ifndef INCLUDES_SPI_CFG_H_
#define INCLUDES_SPI_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO_Cfg.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
#define MASTER 	1U
#define SLAVE	-1
#define SPI_MODE	MASTER

#if SPI_MODE == MASTER
#define SPI1MASTER_CFG 																	\
		(ST_SPIConfig_t) {																\
	&GPIOA7, &GPIOA6, &GPIOA5, &GPIOA4, SPI_1, FULL_DUPLEX, MSB_FIRST, ONE_BYTE, 		\
	NSS_SW_SET, CLK_POLARITY_1, CLK_PHASE_1, MASTER_MODE, BAUD_RATE_8, 		\
	SPI_IRQ_DISABLE, NULL 																\
}

#elif SPI_MODE == SLAVE

#define SLAVE_NSS                                                                 \
		(ST_GPIOConfig_t) {                                                          \
	PORTA, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
}
#define SLAVE_SCK                                                                 \
		(ST_GPIOConfig_t) {                                                          \
	PORTA, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
}
#define SLAVE_MISO                                                                 \
		(ST_GPIOConfig_t) {                                                          \
	PORTA, PIN6, GPIO_ALTERNATE_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ      \
}
#define SLAVE_MOSI                                                                 \
		(ST_GPIOConfig_t) {                                                          \
	PORTA, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
}
#define SPI1SLAVE_CFG 																	\
		(ST_SPIConfig_t) {																\
	&SLAVE_MOSI, &SLAVE_MISO, &SLAVE_SCK, &SLAVE_NSS, SPI_1, FULL_DUPLEX, 				\
	MSB_FIRST, ONE_BYTE, NSS_SW_RESET, SLAVE, SLAVE, SLAVE_MODE, 						\
	BAUD_RATE_8, SPI_IRQ_DISABLE, NULL 													\
}
#endif
/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
/*- DEFINE THE CONFIGURABLE ITEMS OF SPI */
typedef enum {
	SPI_1 = 0, SPI_2
} EN_SPIX_t;

typedef enum {
	FULL_DUPLEX, HALF_DUPLEX, SIMPLEX
} EN_SPI_COMM_MODE_t;

typedef enum {
	LSB_FIRST, MSB_FIRST
} EN_FRAME_FORMAT_t;

typedef enum {
	ONE_BYTE, TWO_BYTES
} EN_DATA_LENGTH_t;

typedef enum {
	NSS_MASTER_HW_DISABLE,
	NSS_MASTER_HW_ENABLE,
	NSS_SLAVE_HW,
	NSS_SW_SET,
	NSS_SW_RESET
} EN_NSS_t;

typedef enum {
	CLK_POLARITY_0, CLK_POLARITY_1
} EN_CLOCK_POLARITY_t;

typedef enum {
	CLK_PHASE_0, CLK_PHASE_1
} EN_CLOCK_PHASE_t;

typedef enum {
	MASTER_MODE, SLAVE_MODE
} EN_SPI_MODE_t;

typedef enum {
	BAUD_RATE_2 = 0,
	BAUD_RATE_4,
	BAUD_RATE_8,
	BAUD_RATE_16,
	BAUD_RATE_32,
	BAUD_RATE_64,
	BAUD_RATE_128,
	BAUD_RATE_256,
} EN_BAUD_t;

typedef enum {
	SPI_IRQ_DISABLE = 0, SPI_IRQ_ERR = 5, SPI_IRQ_RXNE, SPI_IRQ_TXE
} EN_SPI_IRQ_t;

typedef struct {
	vuint8_t None :1;
	vuint8_t TXE :1;
	vuint8_t RXNE :1;
	vuint8_t ERR :1;
	vuint8_t Reserved :4;
} ST_SPI_IRQSrc_t;

typedef struct {
	ST_GPIOConfig_t *const pSetMosiPin;
	ST_GPIOConfig_t *const pSetMisoPin;
	ST_GPIOConfig_t *const pSetSckPin;
	ST_GPIOConfig_t *const pSetNssPin;
	EN_SPIX_t spiNumber;
	EN_SPI_COMM_MODE_t commMode;
	EN_FRAME_FORMAT_t frameFormat;
	EN_DATA_LENGTH_t payLoadSize;
	EN_NSS_t slaveSelectPin;
	EN_CLOCK_POLARITY_t clkPol;
	EN_CLOCK_PHASE_t clkPha;
	EN_SPI_MODE_t Mode;
	EN_BAUD_t Baud;
	EN_SPI_IRQ_t Irq;
	void (*callBackFunctionSpi)(ST_SPI_IRQSrc_t irqSrc);
} ST_SPIConfig_t;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: SPI_ConfigGet
 * Syntax: const ST_GPIOConfig_t *const SPI_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the SPI based on a config
 * table.
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_GPIOConfig_t* const
 *************************************************************************/
ST_SPIConfig_t* const SPI_ConfigGet(void);

#endif /* INCLUDES_SPI_CFG_H_ */


/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 * 	@file: SPI.h
 * 	@brief The interface definition for the SPI.
 *
 * 	@details: This is the header file for the definition of the interface
 *	for a SPI peripheral on a standard microcontroller.
 *****************************************************************************/

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_
/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO.h"
#include "../Config/inc/SPI_Cfg.h"

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
 * Service Name: SPI_Init
 * Syntax: void SPI_Init(const ST_SPIConfig_t* const configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize SPI module.
 * @param (in): SPINumber represents the instance number of the SPI
 *peripheral
 * @param (in): configPtr a pointer to SPI_Config struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_Init(ST_SPIConfig_t *const configPtr);

/************************************************************************
 * Service Name: SPI_Reset
 * Syntax: void SPI_Reset(EN_SPIX_t spiNumber)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset SPI module.
 * @param (in): spiNumber represents the instance number of the SPI
 *peripheral
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_Reset(EN_SPIX_t spiNumber);

/************************************************************************
 * Service Name: SPI_SendData
 * Syntax: void SPI_SendData(EN_SPIX_t spiNumber, vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send data by SPI module.
 * @param (in): spiNumber represents the instance number of the SPI
 *peripheral
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_SendData(EN_SPIX_t spiNumber, vuint16_t *pBuffer);

/************************************************************************
 * Service Name: SPI_ReceiveData
 * Syntax: void SPI_ReceiveData(EN_SPIX_t spiNumber, vuint16_t* pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Receive data by SPI module.
 * @param (in): spiNumber represents the instance number of the SPI
 *peripheral
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_ReceiveData(EN_SPIX_t spiNumber, vuint16_t *pBuffer);

/************************************************************************
 * Service Name: SPI_TX_RX
 * Syntax: void SPI_TX_RX (EN_SPIX_t spiNumber, vuint16_t *pBuffer)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send and Receive data by SPI module (Full-Duplex).
 * @param (in): spiNumber represents the instance number of the SPI
 *peripheral
 * @param (in): pBuffer a pointer to a buffer that stores the sent data
 * @param (inout): None
 * @param (out): None
 * @return: unsigned short int
 *************************************************************************/
vuint16_t SPI_TX_RX (EN_SPIX_t spiNumber, vuint16_t *pBuffer);

/************************************************************************
 * Service Name: SPI_SendString
 * Syntax: void SPI_SendString(vuint8_t *pStr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send a user-defined-terminated string by SPI module.
 * @param (in): pStr a pointer to a character
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_SendString(vuint8_t *pStr);

/************************************************************************
 * Service Name: SPI_ReceiveString
 * Syntax: void SPI_ReceiveString (vuint8_t *pStr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Receive a null-terminated string by SPI module.
 * @param (in): pStr a pointer to a character
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_ReceiveString(vuint8_t *pStr);

/************************************************************************
 * Service Name: SPI_SendIntNum
 * Syntax: void SPI_SendIntNum (vuint32_t Num)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send an integer number.
 * @param (in): Num an integer number to be sent
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_SendIntNum(vuint32_t Num);

/************************************************************************
 * Service Name: SPI_ReceiveIntNum
 * Syntax: void SPI_ReceiveIntNum (vuint32_t *pNum)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Send an integer number.
 * @param (in): pNum a pointer to an integer number to store the received number
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void SPI_ReceiveIntNum(vuint32_t *pNum);

/*
 * TODO
 * void SPI_LIN_Init()
 * void SPI_Init() 		- Using the Synchronous Mode
 * void SPI_DMA_Init()	- Using the DMA
 */

#endif /* INCLUDES_SPI_H_ */

/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file 7-SEG-BCD.h
 * @brief The interface definition for the 7-segment Driver
 *
 * This is the header file for the definition of the interface for
 * the 7-segment-BCD driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef _SEG_H
#define	_SEG_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
vuint8_t SevenSegment_Enable (DIOPin_t Pin);
void SevenSegment_DisplayDigit(DIOPORTX_t Port, DIOPin_t Pin, vuint8_t digit);

#endif	/* _SEG_H */


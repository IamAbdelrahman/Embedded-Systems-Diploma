/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file DIO.h
 * @brief The interface definition for the DIO
 *
 * This is the header file for the definition of the interface for a DIO
 * peripheral on a standard microcontroller.
 * @author Abdelrahman Kamal
 *
 */

#ifndef DIO_H
#define DIO_H
/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO_Config.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define TYPE vuint8_t

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void DIO_Init(const ST_GpioConfig_t *const Config);
void DIO_PinWrite(EN_GpioX_t Port, EN_GpioPin_t Pin, EN_State_t state);

#endif /* DIO_H */

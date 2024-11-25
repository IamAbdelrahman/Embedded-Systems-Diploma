/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUZZER.h
 * @brief The interface definition for the BUZZER Driver
 *
 * This is the header file for the definition of the interface for
 * the BUZZER driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */

#ifndef BUZZER_H
#define	BUZZER_H
/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void BUZZER_On(DIOPORTX_t Port, DIOPin_t Pin);
void BUZZER_Off(DIOPORTX_t Port, DIOPin_t Pin);
#endif	/* BUZZER_H */
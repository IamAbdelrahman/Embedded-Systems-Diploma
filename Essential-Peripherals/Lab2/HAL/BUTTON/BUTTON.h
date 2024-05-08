/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file BUTTON.h
 * @brief The interface definition for the BUTTON Driver
 *
 * This is the header file for the definition of the interface for
 * the BUTTON driver connected to the microcontroller
 * @author Abdelrahman Kamal
 *
 */


#ifndef BUTTON_BUTTON_H_
#define BUTTON_BUTTON_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "DIO.h"

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
State_t BUTTON_Read(DIOPORTX_t Port, DIOPin_t Pin);

#endif /* BUTTON_BUTTON_H_ */
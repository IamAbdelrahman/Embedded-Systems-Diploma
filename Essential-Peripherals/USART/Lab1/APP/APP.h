/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: APP.h
 *	@brief The interface definition for the application Driver
 *
 *	@details: This is the header file for the definition of the interface
 *	for the application driver connected to the microcontroller
 *****************************************************************************/

#ifndef APP_H_
#define APP_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "USART.h"
#include "LCD.h"

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
void APP_Init(void);
void APP_Start(void);

#endif /* APP_H_ */
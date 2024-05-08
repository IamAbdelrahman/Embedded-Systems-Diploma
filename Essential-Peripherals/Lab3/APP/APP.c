/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.h
 * @brief The interface definition for the application Driver
 *
 * Using 7-SEG-Decoder for multiplexing between two 7-SEGs to count
*  from 1:99.
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "APP.h"

/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Function :APP_Init()
 *
 * Description:
 *
 * This function is used to initialize the application.
 *
 * PRE-CONDITION: The MCAL and HAL are configured and initialized
 *
 * POST-CONDITION: The application is initialized

 **********************************************************************/
void APP_Init(void) {
    DIO_Init(DIO_ConfigGet());
}

/**********************************************************************
 * Function :APP_Start()
 *
 * Description:
 *
 * This function is used to start the application
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start(void) {
    vuint8_t i = 0, j = 0, c = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            for (c = 0; c < 10; c++) {
            DIO_WritePort(PORTC, (SevenSegment_Enable(Pin3) | (i << 4)));
            _delay_ms(50);
            DIO_WritePort(PORTC, (SevenSegment_Enable(Pin2) | (j << 4)));
            _delay_ms(50);
            }
            
        }
    }
}

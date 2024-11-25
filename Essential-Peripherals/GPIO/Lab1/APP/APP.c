/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.h
 * @brief The interface definition for the application Driver
 *
 * This is the header file for the definition of the interface for
 * the application driver connected to the microcontroller
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
 * This function is used to intiailize the application of toggling leds
 * in a result of pressing buttons all connected to the MCU's pins.
 *
 * PRE-CONDITION: The MCAL and HAL are configured and initialized
 *
 * POST-CONDITION: The application is initialized

 **********************************************************************/
void APP_Init(void) {
	Clock_Init();
	Gpio_Init(Gpio_ConfigGet());
}

/**********************************************************************
 * Function :APP_Start()
 *
 * Description:
 *
 * This function is used to start the application of toggling leds
 * in a result of pressing buttons all connected to the MCU's pins.
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start(void) {
	if (BUTTON_Read(PORTA, PIN13) == HIGH) {
		LED_Toggle(PORTB, PIN13);
	}
	if (BUTTON_Read(PORTA, PIN1) == LOW) {
		LED_Toggle(PORTB, PIN1);
		while((BUTTON_Read(PORTA, PIN1)) == LOW);	// single pressing
	}
}

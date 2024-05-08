/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.h
 * @brief The interface definition for the application Driver
 *
 * This is the header file for the definition of the interface for
 * the application of toggling leds and turning on a buzzer
 * connected to the microcontroller
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
 * This function is used to initialize the application of toggling leds
 * in a result of pressing buttons all connected to the MCU's pins.
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
 * Description: This function is used to start the application
 * if the button1 is pressed, the first led only is on, 
 * if the button2 is pressed, the first and the second led are on
 * and if the button3 is pressed, all leds are on.
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start(void) {
    if (BUTTON_Read(PORTD, Pin0) == HIGH) {
        BUZZER_On(PORTD, Pin4);
        _delay_ms(1000);
        BUZZER_Off(PORTD, Pin4);
        _delay_ms(1000);
        LED_Off(PORTD, Pin5);
        LED_Off(PORTD, Pin6);
    }
    
    else if(BUTTON_Read(PORTD, Pin1) == HIGH) {
        LED_On(PORTD, Pin5);
        LED_Off(PORTD, Pin6);
    }
    else if(BUTTON_Read(PORTD, Pin2) == HIGH) {
        LED_On(PORTD, Pin5);
        LED_On(PORTD, Pin6);
    }
    else {
        LED_Off(PORTD, Pin5);
        LED_Off(PORTD, Pin6);

    }
}
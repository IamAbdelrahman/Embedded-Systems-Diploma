/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file KEYPAD.c
 * @brief The implementation for the KEYPAD driver
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "KEYPAD.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Module Variables
 **********************************************************************/
const vuint8_t Keypad_Rows [] = {ROW0, ROW1, ROW2, ROW3};
const vuint8_t Keypad_Cols [] = {COL0, COL1, COL2, COL3};

/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Function : KEYPAD_Init()
 *
 *  Description:
 *  This function is used to initialize the KEYPAD device 
 *  through setting the row pins as output and columns pins as input.
 *  PRE-CONDITION: Configuration table needs to populated (sizeof > 0)

 *  @return void
 **********************************************************************/
void KEYPAD_Init() {
    DIO_Init(KEYPAD_ConfigGet());
    DIO_PinWrite(KEYPAD_PORT, ROW0, HIGH);
    DIO_PinWrite(KEYPAD_PORT, ROW1, HIGH);
    DIO_PinWrite(KEYPAD_PORT, ROW2, HIGH);
    DIO_PinWrite(KEYPAD_PORT, ROW3, HIGH);
}

/**********************************************************************
 * Function : KEYPAD_getKey()
 *
 *  Description:
 *  This function is used to get the key pressed on the KEYPAD
 * through applying the key-detection algorithm.
 *  PRE-CONDITION: KEYPAD is initialized

 *  @return key pressed.
 **********************************************************************/
vuint8_t KEYPAD_getKey() {
    vuint8_t i, j = 0;
    for (i = 0; i < 4; i++) {
        DIO_PinWrite(KEYPAD_PORT, ROW0, HIGH);
        DIO_PinWrite(KEYPAD_PORT, ROW1, HIGH);
        DIO_PinWrite(KEYPAD_PORT, ROW2, HIGH);
        DIO_PinWrite(KEYPAD_PORT, ROW3, HIGH);
        DIO_PinWrite(KEYPAD_PORT, Keypad_Rows[i], LOW);
        for (j = 0; j < 4; j++) {
            if (!(DIO_PinRead(KEYPAD_PORT, Keypad_Cols[j]))) {
                while(!(DIO_PinRead(KEYPAD_PORT, Keypad_Cols[j])));
                switch (i) {
                    case ROW0:
                        if (j == 0) return '7';
                        if (j == 1) return '8';
                        if (j == 2) return '9';
                        if (j == 3) return '/';
                        break;
                    case ROW1:
                        if (j == 0) return '4';
                        if (j == 1) return '5';
                        if (j == 2) return '6';
                        if (j == 3) return '*';
                        break;
                    case ROW2:
                        if (j == 0) return '1';
                        if (j == 1) return '2';
                        if (j == 2) return '3';
                        if (j == 3) return '-';
                        break;
                    case ROW3:
                        if (j == 0) return '!';
                        if (j == 1) return '0';
                        if (j == 2) return '=';
                        if (j == 3) return '+';
                        break;
                    default:
                        break;

                }
            }
        }
    }
    return 'N';
}
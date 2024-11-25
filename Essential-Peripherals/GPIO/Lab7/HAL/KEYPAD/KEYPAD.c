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
#include <KEYPAD.h>

/**********************************************************************
 * Module Variables
 **********************************************************************/
const vuint8_t Keypad_Rows[] = {ROW0, ROW1, ROW2, ROW3};
const vuint8_t Keypad_Cols[] = {COL0, COL1, COL2, COL3};
vuint8_t Row_Size = sizeof(Keypad_Rows) / sizeof(Keypad_Rows[0]);
vuint8_t Col_Size = sizeof(Keypad_Cols) / sizeof(Keypad_Cols[0]);
/**********************************************************************
 * Function Definitions
 **********************************************************************/
void KEYPAD_Init(void) {
  Gpio_Init(KEYPAD_ConfigGet());
  vuint8_t i = 0;
  for (i = 0; i < Row_Size; i++) {
    Gpio_PinWrite(KEYPAD_PORT, Keypad_Rows[i], LOW);
  }
}

vuint8_t KEYPAD_getKey(void) {
  vuint8_t i = 0, j = 0;
  for (i = 0; i < Row_Size; i++) {
    Gpio_PinWrite(KEYPAD_PORT, Keypad_Rows[i], HIGH);
    for (j = 0; j < Col_Size; j++) {
      if (Gpio_PinRead(KEYPAD_PORT, Keypad_Cols[j])) {
        while (Gpio_PinRead(KEYPAD_PORT, Keypad_Cols[j]))
          ;
        Gpio_PinWrite(KEYPAD_PORT, Keypad_Rows[i], LOW);
        switch (i) {
        case 0:
          if (j == 0)
            return '7';
          if (j == 1)
            return '8';
          if (j == 2)
            return '9';
          if (j == 3)
            return '/';
          break;
        case 1:
          if (j == 0)
            return '4';
          if (j == 1)
            return '5';
          if (j == 2)
            return '6';
          if (j == 3)
            return '*';
          break;
        case 2:
          if (j == 0)
            return '1';
          if (j == 1)
            return '2';
          if (j == 2)
            return '3';
          if (j == 3)
            return '-';
          break;
        case 3:
          if (j == 0)
            return '!';
          if (j == 1)
            return '0';
          if (j == 2)
            return '=';
          if (j == 3)
            return '+';
          break;
        }
      }
    }
    Gpio_PinWrite(KEYPAD_PORT, Keypad_Rows[i], LOW);
  }
  return 'N'; // No key pressed
}

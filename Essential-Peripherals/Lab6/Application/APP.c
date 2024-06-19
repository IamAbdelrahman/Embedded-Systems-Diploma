/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file APP.c
 * @brief The implementation file for the application Driver
 *
 * This is the source file for the implementation for
 * the application of implementing a basic calculator.
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "APP.h"

/**********************************************************************
 * Module Variables
 **********************************************************************/
vuint8_t static operator= '!';
vuint8_t counter = 0;
/**********************************************************************
 * Function Definitions
 **********************************************************************/

/**********************************************************************
 * Functions :APP_Init()
 *
 * Description:
 *
 * This function is used to initialize the calculator
 *
 * PRE-CONDITION: The MCAL and HAL are configured and initialized
 *
 * POST-CONDITION: The application is initialized

 **********************************************************************/
void APP_Init(void) {
  LCD_Init();
  KEYPAD_Init();
}

/**********************************************************************
 * Functions :getNumber1()
 *
 * Description:
 *
 * This function is used to get the 1st number from the user through getting
 * the key from the keypad then sending it to the lcd.
 *
 * PRE-CONDITION: The application is initialized
 *
 * POST-CONDITION: The 1st number is returned
 *
 * @return: It returns long int.

 **********************************************************************/
vint64_t getNumber1(void) {
  vint8_t number1[16];
  vuint8_t i = 0, key, count = 0;
  for (;;) {
    key = KEYPAD_getKey();
    switch (key) {
    case '+':
      operator= '+';
      LCD_sendChar('+');
      break;
    case '-':
      operator= '-';
      LCD_sendChar('-');
      break;
    case '*':
      operator= '*';
      LCD_sendChar('*');
      break;
    case '/':
      operator= '/';
      LCD_sendChar('/');
      break;
    case 'N':
      break;
    case '!':
      LCD_clearScreen();
      count = 0;
      break;
    default:
      number1[i++] = key;
      LCD_sendChar(key);
      count++;
      if (count >= 16) {
        LCD_errorHandling(OUT_OF_RANGE_ERROR);
        operator= 'N';
        return -1;
      }
      break;
    }
    if (operator!= '!') {
      count++;
      if (count >= 16) {
        LCD_errorHandling(OUT_OF_RANGE_ERROR);
        operator= 'N';
        return -1;
      }
      number1[i] = '\0';
      counter = count;
      break;
    }
  }
  return (atol(number1));
}

/**********************************************************************
 * Functions :getNumber2()
 *
 * Description:
 *
 * This function is used to get the 2nd number from the user through getting
 * the key from the keypad then sending it to the lcd.
 *
 * PRE-CONDITION: The 1st number is returned.
 *
 * POST-CONDITION: The 2nd number is returned.
 *
 * @return: It returns long int.

 **********************************************************************/
vint64_t getNumber2(void) {
  if ('N' == operator)
    return -1;
  vint8_t number2[16];
  vuint8_t i = 0, key, count = counter;
  for (;;) {
    key = KEYPAD_getKey();
    switch (key) {
    case '!':
      LCD_clearScreen();
      counter = 0;
      break;
    case 'N':
      break;
    default:
      number2[i++] = key;
      LCD_sendChar(key);
      count++;
      if (count >= 16) {
        LCD_errorHandling(OUT_OF_RANGE_ERROR);
        operator= 'N';
        return -1;
      }
      break;
    }
    if (key == '=') {
      number2[i] = '\0';
      break;
    }
  }
  return (atol(number2));
}

/**********************************************************************
 * Functions :Calculate()
 *
 * Description:
 *
 * This function is used to calculate the arithmetic operations.
 *
 * PRE-CONDITION: The 1st and 2nd numbers are got.
 *
 * POST-CONDITION: The calculation is done.
 *
 * @param num1: long int argument represents the 1st number.
 * @param num2: long int argument represents the 2nd number.
 *
 **********************************************************************/
void Calculate(vint64_t num1, vint64_t num2) {
  switch (operator) {
  case 'N':
    break;
  case '+':
    LCD_goToXY(2, 0);
    LCD_sendNumber((num1 + num2));
    break;
  case '-':
    LCD_goToXY(2, 0);
    LCD_sendNumber((num1 - num2));
    break;
  case '*':
    LCD_goToXY(2, 0);
    LCD_sendNumber((num1 * num2));
    break;
  case '/':
    if (num2 == 0) {
      LCD_errorHandling(ZERO_DIVISION_ERROR);
      break;
    }
    LCD_goToXY(2, 0);
    LCD_sendRealNumber(((float)num1 / num2));
    break;
  default:
    break;
  }
  operator= '!';
  counter = 0;
}

/**********************************************************************
 * Function :APP_Start()
 *
 * Description: This function is used to start the application
 * of the calculator so it performs the basic arithmetic operations.
 *
 * PRE-CONDITION: The calculation is done.
 *
 * POST-CONDITION: The application runs

 **********************************************************************/
void APP_Start() {
  vint64_t num1 = getNumber1();
  vint64_t num2 = getNumber2();
  Calculate(num1, num2);
}

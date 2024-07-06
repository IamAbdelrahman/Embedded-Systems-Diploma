/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO_Config.h
 * @brief This module contains interface definitions for the
 *  GPIO configuration related to the LQFP48 package.
 *
 * This is the header file for the definition of the
 *  interface for retrieving the general purpose input/output configuration
 * table
 * @author Abdelrahman Kamal
 *
 */

#ifndef GPIO_Cfg__H_
#define GPIO_Cfg__H_

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Stm32f101x8.h"
/**********************************************************************
 * Preprocessor Constants
 **********************************************************************/
/**
 * Defines the number of ports on this processor's package.
 */
#define NUMBER_OF_PORTS 		(4U)
/**
 * Defines the number of PINs on each processor port.
 */
#define NUMBER_OF_PINS_PER_PORT 	(15U)
#define GPIO_PIN0 			0
#define GPIO_PIN1 			1
#define GPIO_PIN2 			2
#define GPIO_PIN3 			3
#define GPIO_PIN4 			4
#define GPIO_PIN5 			5
#define GPIO_PIN6 			6
#define GPIO_PIN7 			7
#define GPIO_PIN8 			8
#define GPIO_PIN9 			9
#define GPIO_PIN10	 		10
#define GPIO_PIN11 			11
#define GPIO_PIN12 			12
#define GPIO_PIN13 			13
#define GPIO_PIN14 			14
#define GPIO_PIN15 			15

#define GPIOA0                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA1                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA2                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN2, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA3                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN3, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA4                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA5                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA6                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN6, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA7                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA8                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN8, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA9                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN9, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOA10                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN10, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOA11                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN11, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOA12                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN12, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOA13                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN13, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOA14                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN14, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOA15                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN15, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }

#define GPIOB0                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB1                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB2                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN2, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB3                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN3, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB4                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB5                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB6                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN6, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB7                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB8                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN8, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB9                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN9, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOB10                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN10, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOB11                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN11, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOB12                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN12, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOB13                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN13, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOB14                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN14, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOB15                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN15, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }

#define GPIOC13                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTC, PIN13, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOC14                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTC, PIN14, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define GPIOC15                                                                \
  (ST_GPIOConfig_t) {                                                          \
    PORTC, PIN15, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }

#define GPIOD0                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTD, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define GPIOD1                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTD, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }

/**********************************************************************
 * Typedefs
 **********************************************************************/
/**
 * Defines an enumerated list of all the ports on the MCU
 * device.
 */
typedef enum {
  PORTA = 0,
  PORTB,
  PORTC,
  PORTD,
} EN_GPIOX_t;

/**
 * Defines the possible states for a digital I/O PIN.
 */
typedef enum {
  GPIO_INPUT_ANALOG,
  GPIO_INPUT_FLOATING,
  GPIO_INPUT_PULLUP,
  GPIO_INPUT_PULLDOWN,
  GPIO_OUTPUT_PUSHPULL,
  GPIO_OUTPUT_OPENDRAIN,
  GPIO_ALTERNATE_PUSHPULL,
  GPIO_ALTERNATE_OPENDRAIN
} EN_GPIOPinState_t;

/**
 * Defines an enumerated list of all the channels (PINs) on the MCU
 * device.
 */
typedef enum {
  /** GPIOA PINs */
  PIN0 = 0,
  PIN1,
  PIN2,
  PIN3,
  PIN4,
  PIN5,
  PIN6,
  PIN7,
  PIN8,
  PIN9,
  PIN10,
  PIN11,
  PIN12,
  PIN13,
  PIN14,
  PIN15 = 15,
} EN_GPIOPin_t;

/**
 * Defines the possible GPIO PIN multiplexing values.
 */
typedef enum {
  GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED,
  GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ,
  GPIO_MAX_OUTPUT_MODE_SPEED_2MHZ,
  GPIO_MAX_OUTPUT_MODE_SPEED_50MHZ
} EN_GPIOOutModeSpeed_t;

/**
 * Defines the slew rate settings available
 */
typedef enum { SLOW, MEDIUM, FAST } EN_GPIOSlew_t;

/**
 * Defines the lock configuration
 */
typedef enum { GPIO_LOCK_Enabled, GPIO_LOCK_ERROR } EN_GPIOLockState_t;

/**
 * Defines GPIO configuration table’s elements that are
 used by GPIO_Init to configure the GPIO peripheral.
 */
typedef struct {
  EN_GPIOX_t Port;
  EN_GPIOPin_t Pin;
  EN_GPIOPinState_t State;
  EN_GPIOOutModeSpeed_t Mode;
} ST_GPIOConfig_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void);

#endif /** GPIO_Cfg__H_ **/
/***End of File****************************************************/

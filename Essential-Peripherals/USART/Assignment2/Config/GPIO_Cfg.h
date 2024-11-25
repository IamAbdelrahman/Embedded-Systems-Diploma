/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: GPIO_Cfg.h
 *	@brief This module contains interface definitions for the
 *	GPIO configuration related to the LQFP48 package.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the GPIO configuration table.
 *****************************************************************************/

#ifndef INCLUDES_GPIO_CFG_H_
#define INCLUDES_GPIO_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "Stm32f101x8.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- NUMBER OF PORTS IN THIS PACKAGE */
#define NUMBER_OF_PORTS 	 (4UL)

/*- NUMBER OF PINS PER PORT */
#define NUMBER_OF_PINS_PER_PORT (15U)

/*- GPIO PINS NUMBERS */
#define GPIO_PIN0  (0UL)
#define GPIO_PIN1  (1UL)
#define GPIO_PIN2  (2UL)
#define GPIO_PIN3  (3UL)
#define GPIO_PIN4  (4UL)
#define GPIO_PIN5  (5UL)
#define GPIO_PIN6  (6UL)
#define GPIO_PIN7  (7UL)
#define GPIO_PIN8  (8UL)
#define GPIO_PIN9  (9UL)
#define GPIO_PIN10 (10UL)
#define GPIO_PIN11 (11UL)
#define GPIO_PIN12 (12UL)
#define GPIO_PIN13 (13UL)
#define GPIO_PIN14 (14UL)
#define GPIO_PIN15 (15UL)

/*- GPIO PINS CONFIGURATION */
#define GPIOA0                                                                 \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN0, GPIO_OUTPUT_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ        \
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
    PORTA, PIN9, GPIO_ALTERNATE_PUSHPULL, GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ     \
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

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
/*- GPIO PORTS */
typedef enum {
  PORTA = 0,
  PORTB,
  PORTC,
  PORTD,
} EN_GPIOX_t;

/*- GPIO PINS STATE */
typedef enum {
  GPIO_INPUT_ANALOG,
  GPIO_INPUT_FLOATING,
  GPIO_INPUT_PULLUP,
  GPIO_INPUT_PULLDOWN,
  GPIO_OUTPUT_PUSHPULL,
  GPIO_OUTPUT_OPENDRAIN,
  GPIO_ALTERNATE_PUSHPULL,
  GPIO_ALTERNATE_OPENDRAIN
} EN_GPIO_PIN_STATE_t;

/*- GPIO PINS NUMBERS */
typedef enum {
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
} EN_GPIO_PIN_t;

/*- PIN LEVEL */
typedef enum { LOW = 0, HIGH, TOGGLE } EN_PIN_STATE_t;

/*- GPIO PINS SLEW RATE */
typedef enum {
  GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED,
  GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ,
  GPIO_MAX_OUTPUT_MODE_SPEED_2MHZ,
  GPIO_MAX_OUTPUT_MODE_SPEED_50MHZ
} EN_GPIO_OUT_MODE_SPEED_t;

/*- GPIO LOCK CONFIGURATION */
typedef enum { GPIO_LOCK_Enabled, GPIO_LOCK_ERROR } EN_GPIO_LOCK_STATE_t;

/*- GPIO CONFIGURATION */
typedef struct {
  EN_GPIOX_t portNumber;
  EN_GPIO_PIN_t pinNumber;
  EN_GPIO_PIN_STATE_t pinState;
  EN_GPIO_OUT_MODE_SPEED_t pinMode;
} ST_GPIOConfig_t;

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void);

#endif /* INCLUDES_GPIO_CFG_H_ */

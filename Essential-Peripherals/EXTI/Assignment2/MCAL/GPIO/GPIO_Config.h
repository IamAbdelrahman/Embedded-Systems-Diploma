/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file GPIO_Config.h
 * @brief This module contains interface definitions for the
 *  GPIO configuration related to the ATmega32 MCU.
 *
 * This is the header file for the definition of the
 *  interface for retrieving the descriptive input/output configuration table
 * @author Abdelrahman Kamal
 *
 */
#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#include "ATmega32.h"
/**********************************************************************
 * Preprocessor Constants
 **********************************************************************/
/**
 * Defines the number of pins on each processor port.
 */
#define NUMBER_OF_PINS_PER_PORT 	8U

/**
 * Defines the number of ports on this processor's package.
 */
#define NUMBER_OF_PORTS 		4U

/** PUD bit in SFIOR register **/
#define PUD 				2U

/** Configuration Table Size **/
#define NUMBER_OF_USED_PINS 		32U

#define GPIOA0                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin0, GPIO_INPUT_FLOATING }
#define GPIOA1                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin1, GPIO_INPUT_FLOATING }
#define GPIOA2                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin2, GPIO_INPUT_FLOATING }
#define GPIOA3                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin3, GPIO_INPUT_FLOATING }
#define GPIOA4                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin4, GPIO_INPUT_FLOATING }
#define GPIOA5                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin5, GPIO_INPUT_FLOATING }
#define GPIOA6                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin6, GPIO_INPUT_FLOATING }
#define GPIOA7                                                                 \
  (ST_GPIOConfig_t) { PORTA, Pin7, GPIO_INPUT_FLOATING }
#define GPIOB0                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin0, GPIO_INPUT_FLOATING }
#define GPIOB1                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin1, GPIO_INPUT_FLOATING }
#define GPIOB2                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin2, GPIO_INPUT_FLOATING }
#define GPIOB3                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin3, GPIO_INPUT_FLOATING }
#define GPIOB4                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin4, GPIO_INPUT_FLOATING }
#define GPIOB5                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin5, GPIO_INPUT_FLOATING }
#define GPIOB6                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin6, GPIO_INPUT_FLOATING }
#define GPIOB7                                                                 \
  (ST_GPIOConfig_t) { PORTB, Pin7, GPIO_INPUT_FLOATING }
#define GPIOC0                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin0, GPIO_INPUT_FLOATING }
#define GPIOC1                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin1, GPIO_INPUT_FLOATING }
#define GPIOC2                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin2, GPIO_INPUT_FLOATING }
#define GPIOC3                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin3, GPIO_INPUT_FLOATING }
#define GPIOC4                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin4, GPIO_INPUT_FLOATING }
#define GPIOC5                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin5, GPIO_INPUT_FLOATING }
#define GPIOC6                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin6, GPIO_INPUT_FLOATING }
#define GPIOC7                                                                 \
  (ST_GPIOConfig_t) { PORTC, Pin7, GPIO_INPUT_FLOATING }
#define GPIOD0                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin0, GPIO_INPUT_FLOATING }
#define GPIOD1                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin1, GPIO_INPUT_FLOATING }
#define GPIOD2                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin2, GPIO_INPUT_FLOATING }
#define GPIOD3                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin3, GPIO_INPUT_FLOATING }
#define GPIOD4                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin4, GPIO_INPUT_FLOATING }
#define GPIOD5                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin5, GPIO_INPUT_FLOATING }
#define GPIOD6                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin6, GPIO_INPUT_FLOATING }
#define GPIOD7                                                                 \
  (ST_GPIOConfig_t) { PORTD, Pin7, GPIO_INPUT_FLOATING }

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
 * Defines the possible states for a digital I/O pin.
 */
typedef enum {
  GPIO_INPUT_FLOATING,
  GPIO_INPUT_PULLUP,
  GPIO_OUTPUT
} EN_GPIOPinState_t;

/**
 * Defines an enumerated list of all the channels (pins) on the MCU
 * device.
 */
typedef enum {
  /** GPIO Pins */
  Pin0 = 0,
  Pin1,
  Pin2,
  Pin3,
  Pin4,
  Pin5,
  Pin6,
  Pin7 = 7
} EN_GPIOPin_t;

/**
 * Defines GPIO configuration table?s elements that are
 used by GPIO_Init() to configure the GPIO peripheral.
 */
typedef struct {
  EN_GPIOX_t Port;
  EN_GPIOPin_t Pin;
  EN_GPIOPinState_t State;
} ST_GPIOConfig_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GPIOConfig_t *const GPIO_ConfigGet(void);

#endif /* GPIO_CONFIG_H */

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
#include "Stm32f101x8.h"
/**********************************************************************
 * Preprocessor Constants
 **********************************************************************/
/**
 * Defines the number of pins on each processor port.
 */
#define NUMBER_OF_PINS_PER_PORT (15U)
/**
 * Defines the number of ports on this processor's package.
 */
#define NUMBER_OF_PORTS (2U)
/**********************************************************************
 * Typedefs
 **********************************************************************/
/**
 * Defines an enumerated list of all the ports on the MCU
 * device.
 */
typedef enum { PORTA = 0, PORTB } EN_GpioX_t;

/**
 * Defines the possible states for a digital I/O pin.
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
} EN_GpioPinState_t;

/**
 * Defines an enumerated list of all the channels (pins) on the MCU
 * device.
 */
typedef enum {
  /** GPIOA Pins */
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
} EN_GpioPin_t;

/**
 * Defines the possible GPIO pin multiplexing values.
 */
typedef enum {
  GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED,
  GPIO_MAX_OUTPUT_MODE_SPEED_10MHZ,
  GPIO_MAX_OUTPUT_MODE_SPEED_2MHZ,
  GPIO_MAX_OUTPUT_MODE_SPEED_50MHZ
} EN_GpioOutModeSpeed_t;

/**
 * Defines the slew rate settings available
 */
typedef enum { SLOW, MEDIUM, FAST } EN_GpioSlew_t;

/**
 * Defines GPIO configuration table’s elements that are
 used by Gpio_Init to configure the GPIO peripheral.
 */
typedef struct {
  EN_GpioX_t Port;
  EN_GpioPin_t Pin;
  EN_GpioPinState_t State;
  EN_GpioOutModeSpeed_t Mode;
} ST_GpioConfig_t;

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GpioConfig_t *const Gpio_ConfigGet(void);

#endif /** GPIO_Cfg__H_ **/
/***End of File****************************************************/

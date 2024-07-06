/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI_Config.h
 * @brief This module contains interface definitions for the
 *  EXTI configuration related to the LQFP48 package.
 *
 * This is the header file for the definition of the
 * interface for retrieving the external interrupt peripheral configuration
 * table
 * @author Abdelrahman Kamal
 *
 */
#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/**********************************************************************
 * Includes
 **********************************************************************/
#include "GPIO_Config.h"
#include "NVIC.h"
#include "Stm32f101x8.h"

/**********************************************************************
 * Typedefs
 **********************************************************************/
typedef enum { RISING, FALLING, RISING_FALLING } EN_EXTI_Trigger_t;

typedef enum { IRQ_DISABLE, IRQ_ENABLE } EN_EXTI_IRQ_State_t;

typedef struct {
  EN_GPIOX_t EXTI_Port;
  EN_GPIOPin_t EXTI_Pin;
  vuint8_t EXTI_Input_Line_Number;
  EN_IRQ_t IRQ_Number;
  void (*CallbackFunction)(void);
} ST_EXTI_Mapping_t;

typedef struct {
  ST_EXTI_Mapping_t EXTI_PIN;
  EN_EXTI_Trigger_t EXTI_Trigger;
  EN_EXTI_IRQ_State_t EXTI_IRQ;
} ST_EXTI_PINConfig_t;

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
// @ref EXTI_Pins Numbers
#define EXTI0 0U
#define EXTI1 1U
#define EXTI2 2U
#define EXTI3 3U
#define EXTI4 4U
#define EXTI5 5U
#define EXTI6 6U
#define EXTI7 7U
#define EXTI8 8U
#define EXTI9 9U
#define EXTI10 10U
#define EXTI11 11U
#define EXTI12 12U
#define EXTI13 13U
#define EXTI14 14U
#define EXTI15 15U

// @ref EXTI_Pins Configuration
#define EXTIPA0_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA1_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA2_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN2, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA3_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN3, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA4_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA5_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA6_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN6, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA7_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA8_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN8, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA9_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN9, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPA10_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN10, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPA11_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN11, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPA12_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN12, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPA13_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN13, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPA14_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN14, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPA15_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTA, PIN15, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }

#define EXTIPB0_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB1_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB2_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN2, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB3_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN3, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB4_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN4, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB5_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN5, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB6_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN6, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB7_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN7, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB8_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN8, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB9_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN9, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPB10_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN10, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPB11_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN11, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPB12_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN12, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPB13_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN13, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPB14_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN14, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPB15_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTB, PIN15, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }

#define EXTIPC13_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTC, PIN13, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPC14_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTC, PIN14, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }
#define EXTIPC15_CFG                                                           \
  (ST_GPIOConfig_t) {                                                          \
    PORTC, PIN15, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED     \
  }

#define EXTIPD0_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTD, PIN0, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }
#define EXTIPD1_CFG                                                            \
  (ST_GPIOConfig_t) {                                                          \
    PORTD, PIN1, GPIO_INPUT_FLOATING, GPIO_MAX_OUTPUT_MODE_SPEED_DISABLED      \
  }

// @ref EXTI_PIN
// EXTI0
#define EXTI0PA0                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN0, EXTI0, EXTI0_IRQ }
#define EXTI0PB0                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN0, EXTI0, EXTI0_IRQ }
#define EXTI0PD0                                                               \
  (ST_EXTI_Mapping_t) { PORTD, PIN0, EXTI0, EXTI0_IRQ }

// EXTI1
#define EXTI0PA1                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN1, EXTI1, EXTI1_IRQ }
#define EXTI0PB1                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN1, EXTI1, EXTI1_IRQ }
#define EXTI0PD1                                                               \
  (ST_EXTI_Mapping_t) { PORTD, PIN1, EXTI1, EXTI1_IRQ }

// EXTI2
#define EXTI0PA2                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN2, EXTI2, EXTI2_IRQ }
#define EXTI0PB2                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN2, EXTI2, EXTI2_IRQ }

// EXTI3
#define EXTI0PA3                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN3, EXTI3, EXTI3_IRQ }
#define EXTI0PB3                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN3, EXTI3, EXTI3_IRQ }

// EXTI4
#define EXTI0PA4                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN4, EXTI4, EXTI4_IRQ }
#define EXTI0PB4                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN4, EXTI4, EXTI4_IRQ }

// EXTI5
#define EXTI0PA5                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN5, EXTI5, EXTI5_IRQ }
#define EXTI0PB5                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN5, EXTI5, EXTI5_IRQ }

// EXTI6
#define EXTI0PA6                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN6, EXTI6, EXTI6_IRQ }
#define EXTI0PB6                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN6, EXTI6, EXTI6_IRQ }

// EXTI7
#define EXTI0PA7                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN7, EXTI7, EXTI7_IRQ }
#define EXTI0PB7                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN7, EXTI7, EXTI7_IRQ }

// EXTI8
#define EXTI0PA8                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN8, EXTI8, EXTI8_IRQ }
#define EXTI0PB8                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN8, EXTI8, EXTI8_IRQ }

// EXTI9
#define EXTI0PA9                                                               \
  (ST_EXTI_Mapping_t) { PORTA, PIN9, EXTI9, EXTI9_IRQ }
#define EXTI0PB9                                                               \
  (ST_EXTI_Mapping_t) { PORTB, PIN9, EXTI9, EXTI9_IRQ }

// EXTI10
#define EXTI0PA10                                                              \
  (ST_EXTI_Mapping_t) { PORTA, PIN10, EXTI10, EXTI10_IRQ }
#define EXTI0PB10                                                              \
  (ST_EXTI_Mapping_t) { PORTB, PIN10, EXTI10, EXTI10_IRQ }

// EXTI11
#define EXTI0PA11                                                              \
  (ST_EXTI_Mapping_t) { PORTA, PIN11, EXTI11, EXTI11_IRQ }
#define EXTI0PB11                                                              \
  (ST_EXTI_Mapping_t) { PORTB, PIN11, EXTI11, EXTI11_IRQ }

// EXTI12
#define EXTI0PA12                                                              \
  (ST_EXTI_Mapping_t) { PORTA, PIN12, EXTI12, EXTI12_IRQ }
#define EXTI0PB12                                                              \
  (ST_EXTI_Mapping_t) { PORTB, PIN12, EXTI12, EXTI12_IRQ }

// EXTI13
#define EXTI0PA13                                                              \
  (ST_EXTI_Mapping_t) { PORTA, PIN13, EXTI13, EXTI13_IRQ }
#define EXTI0PB13                                                              \
  (ST_EXTI_Mapping_t) { PORTB, PIN13, EXTI13, EXTI13_IRQ }
#define EXTI0PC13                                                              \
  (ST_EXTI_Mapping_t) { PORTC, PIN13, EXTI13, EXTI13_IRQ }

// EXTI14
#define EXTI0PA14                                                              \
  (ST_EXTI_Mapping_t) { PORTA, PIN14, EXTI14, EXTI14_IRQ }
#define EXTI0PB14                                                              \
  (ST_EXTI_Mapping_t) { PORTB, PIN14, EXTI14, EXTI14_IRQ }
#define EXTI0PC14                                                              \
  (ST_EXTI_Mapping_t) { PORTC, PIN14, EXTI14, EXTI14_IRQ }

// EXTI15
#define EXTI0PA15                                                              \
  (ST_EXTI_Mapping_t) { PORTA, PIN15, EXTI15, EXTI15_IRQ }
#define EXTI0PB15                                                              \
  (ST_EXTI_Mapping_t) { PORTB, PIN15, EXTI15, EXTI15_IRQ }
#define EXTI0PC15                                                              \
  (ST_EXTI_Mapping_t) { PORTC, PIN15, EXTI15, EXTI15_IRQ }

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
const ST_GPIOConfig_t *const EXTI_ConfigGet(void);

#endif /* EXTI_CONFIG_H_ */

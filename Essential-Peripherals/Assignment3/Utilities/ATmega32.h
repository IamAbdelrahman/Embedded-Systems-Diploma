/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file ATmega32.h
 * @brief This header file Header specifies the MCU device header
 *
 * The file defines generic macros and base addresses for memories, peripheral
 * registers and bus peripheral
 * @author Abdelrahman Kamal
 *
 */

#ifndef ATMEGA32_H
#define ATMEGA32_H

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Macros.h"
#include "Platform_Types.h"
#include <util/delay.h>

/**********************************************************************
 * Typedefs
 **********************************************************************/
typedef enum { LOW = 0, HIGH, TOGGLE } PinState_t;

/**********************************************************************
 * Peripheral base addresses
 **********************************************************************/
#define GPIOA_BASE 	0x39
#define GPIOB_BASE 	0x36
#define GPIOC_BASE 	0x33
#define GPIOD_BASE 	0x30
#define EXTI_BASE 	0x54
#define GIC_BASE 	0x5A
#define SFIOR 		(*((vuint8_t *)0x50))
#define SREG 		(*(vuint8_t *)0x5F)
/**********************************************************************/
/** Peripheral register: GPIO **/
typedef struct {
  vuint8_t PIN;
  vuint8_t DDR;
  vuint8_t PORT;
} ST_GPIO_t;

/** Peripheral register: GIC **/
typedef struct {
  vuint8_t GIFR;
  vuint8_t GICR;
} ST_GIC_t;

/** Peripheral register: EXTI **/
typedef struct {
  vuint8_t MCUCSR;
  vuint8_t MCUCR;
} ST_EXTI_t;
/***************************************************/

/***************************************************/
/** Peripheral instances **/
#define GPIOA 	(ST_GPIO_t *)(GPIOA_BASE)
#define GPIOB 	(ST_GPIO_t *)(GPIOB_BASE)
#define GPIOC 	(ST_GPIO_t *)(GPIOC_BASE)
#define GPIOD 	(ST_GPIO_t *)(GPIOD_BASE)
#define EXTI 	(ST_EXTI_t *)(EXTI_BASE)
#define GIC 	(ST_GIC_t *)(GIC_BASE)
/**************************************/
#endif /* ATMEGA32_H */

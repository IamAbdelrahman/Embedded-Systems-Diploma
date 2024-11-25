/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file STM32f101x8.h
 * @brief This header file Header specifies the MCU device header
 *
 * The file defines base addresses for memories, peripheral registers
 * and bus peripheral
 * @author Abdelrahman Kamal
 *
 */

#ifndef STM32F101X8_H_
#define STM32F101X8_H_
#include "Macros.h"
#include "Platform_Types.h"

/***************************************************/
/** Memory and Peripheral base addresses **/
#define FLASH_MEMORY_BASE 		0x08000000UL
#define SRAM_MEMORY_BASE 		0x20000000UL
#define SYSTEM_MEMORY_BASE 		0x1FFFF000UL
#define PERIPHERAL_BASE 		0x40000000UL
#define CORE_INTERNAL_PERIPHERAL_BASE 0xE0000000UL

/***************************************************/
/** Section: Base addresses for Cortex-M3 Peripherals **/
#define NVIC_BASE 			0xE000E100UL
#define SCB_BASE 			0xE000ED00UL
#define STK_BASE 			0xE000E010UL
/***************************************************/

/** AHB system bus peripheral base addresses **/
#define RCC_BASE 			0x40021000UL
/***************************************************/

/***************************************************/
/** APB2 system bus peripheral base addresses **/
#define GPIOA_BASE 			0x40010800
#define GPIOB_BASE 			0x40010C00
#define GPIOC_BASE 			0x40011000
#define GPIOD_BASE 			0x40011400
#define AFIO_BASE 			0x40010000
#define EXTI_BASE 			0x40010400
/***************************************************/
/***************************************************/
/** Core Peripheral register: NVIC **/
typedef struct {
  vuint32_t ISER[3];
  uint32_t RESERVED0[29];
  vuint32_t ICER[3];
  uint32_t RESERVED1[29];
  vuint32_t ISPR[3];
  uint32_t RESERVED2[29];
  vuint32_t ICPR[3];
  uint32_t RESERVED3[29];
  vuint32_t IABR[3];
  uint32_t RESERVED4[61];
  vuint8_t IP[80];
  uint32_t RESERVED5[684];
  vuint32_t STIR;
} ST_NVIC_t;

/***************************************************/

/** Peripheral register: GPIO **/
typedef struct {
  vuint32_t CRL;
  vuint32_t CRH;
  vuint32_t IDR;
  vuint32_t ODR;
  vuint32_t BSRR;
  vuint32_t BRR;
  vuint32_t LCKR;
} ST_GPIO_t;
/***************************************************/

/***************************************************/
/** Peripheral register: AFIO **/
typedef struct {
  vuint32_t EVCR;
  vuint32_t MAPR;
  vuint32_t EXTICR[4];
  vuint32_t RESERVED;
  vuint32_t MAPR2;
} ST_AFIO_t;
/***************************************************/

/***************************************************/
/** Peripheral register: EXTI **/
typedef struct {
  vuint32_t IMR;
  vuint32_t EMR;
  vuint32_t RTSR;
  vuint32_t FTSR;
  vuint32_t SWIER;
  vuint32_t PR;
} ST_EXTI_t;
/***************************************************/
/** Peripheral register: RCC **/
typedef struct {
  vuint32_t CR;
  vuint32_t CFGR;
  vuint32_t CIR;
  vuint32_t APB2RSTR;
  vuint32_t APB1RSTR;
  vuint32_t AHBENR;
  vuint32_t APB2ENR;
  vuint32_t APB1ENR;
  vuint32_t BDCR;
  vuint32_t CSR;
} ST_RCC_t;

/***************************************************/
/** Peripheral instances **/
#define GPIOA 	(ST_GPIO_t *)(GPIOA_BASE)
#define GPIOB 	(ST_GPIO_t *)(GPIOB_BASE)
#define GPIOC 	(ST_GPIO_t *)(GPIOC_BASE)
#define GPIOD 	(ST_GPIO_t *)(GPIOD_BASE)
#define RCC 	(ST_RCC_t *)(RCC_BASE)
#define EXTI 	(ST_EXTI_t *)(EXTI_BASE)
#define AFIO 	(ST_AFIO_t *)(AFIO_BASE)
#define NVIC 	(ST_NVIC_t *)(NVIC_BASE)

/***************************************************/

typedef enum { LOW = 0, HIGH, TOGGLE } PinState_t;

/***************************************************/

#endif /* STM32F101X8_H_ */

/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file STM32f101x8.h
 * @brief This header file Header specifies the MCU/SOC device header
 *
 * The file defines generic macros and base addresses for memories, peripheral registers
 * and bus peripheral
 * @author Abdelrahman Kamal
 *
 */

#ifndef STM32F101X8_H_
#define STM32F101X8_H_
#include "Platform_Types.h"

/***************************************************/
/** Memory and Peripheral base addresses **/
#define FLASH_MEMORY_BASE				0x08000000UL
#define SRAM_MEMORY_BASE				0x20000000UL
#define SYSTEM_MEMORY_BASE				0x1FFFF000UL
#define PERIPHERAL_BASE					0x40000000UL
#define CORE_INTERNAL_PERIPHERAL_BASE	0xE0000000UL
/***************************************************/

/***************************************************/
/** AHB system bus peripheral base addresses **/
#define RCC_BASE						0x40021000UL
/***************************************************/

/***************************************************/
/** APB2 system bus peripheral base addresses **/
#define GPIOA_BASE						0x40010800
#define GPIOB_BASE						0x40010C00
/***************************************************/

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
} GPIO_t;
/***************************************************/

/** Peripheral register: RCC **/
typedef struct
{
	vuint32_t CR ;
	vuint32_t CFGR ;
	vuint32_t CIR;
	vuint32_t APB2RSTR;
	vuint32_t APB1RSTR;
	vuint32_t AHBENR;
	vuint32_t APB2ENR;
	vuint32_t APB1ENR;
	vuint32_t BDCR;
	vuint32_t CSR;
}RCC_t;

/***************************************************/
/** Peripheral instances **/
#define GPIOA								(GPIO_t*)(GPIOA_BASE)
#define GPIOB								(GPIO_t*)(GPIOB_BASE)
#define RCC      							(RCC_t*)RCC_BASE
/***************************************************/
/***************************************************/
/** Generic Macros **/
#define SET_BIT(REGISTER, BIT_NO)      		(REGISTER |= (1 << BIT_NO))
#define CLR_BIT(REGISTER, BIT_NO)      		(REGISTER &= ~(1 << BIT_NO))
#define TOGGLE_BIT(REGISTER, BIT_NO)   		(REGISTER ^= (1 << BIT_NO))
#define READ_BIT(REGISTER, BIT_NO)     		((REGISTER & (1 << BIT_NO)) >> BIT_NO)

typedef enum
{
	LOW, HIGH
}PinState_t;

/***************************************************/

#endif /* STM32F101X8_H_ */

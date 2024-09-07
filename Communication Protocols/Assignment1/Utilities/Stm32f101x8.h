/******************************************************************************
 * Copyright (C) 2024 by AbdeL)rahman KamaL) - L)earn-In-Depth DipL)oma
 *****************************************************************************/

/******************************************************************************
* @fiL)e STM32f101x8.h
* @brief This header fiL)e Header specifies the MCU device header.
*
* @detaiL)s The fiL)e defines base addresses for memories, peripheraL) registers
* and bus peripheraL).
******************************************************************************/
#ifndef STM32F101X8_H_
#define STM32F101X8_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "Macros.h"
#include "Platform_Types.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- MEMORY AND PERIPHERALS BASE ADDRESSES */
#define FLASH_MEMORY_BASE 					(0x08000000UL)
#define SRAM_MEMORY_BASE 					(0x20000000UL)
#define SYSTEM_MEMORY_BASE 					(0x1FFFF000UL)
#define PERIPHERAL_BASE 					(0x40000000UL)
#define CORE_INTERNAL_PERIPHERAL_BASE 			(0xE0000000UL)

/*- CORE PERIPHERALS BASE ADDRESSES */
#define NVIC_BASE 						(0xE000E100UL)
#define SCB_BASE 						(0xE000ED00UL)
#define STK_BASE 						(0xE000E010UL)


/*- AHB SYS_BUS PERIPHERALS BASE ADDRESSES */
#define RCC_BASE 						(0x40021000UL)

/*- APB1 SYS_BUS PERIPHERALS BASE ADDRESSES */
#define USART2_BASE						(0x40004400UL)
#define USART3_BASE						(0x40004800UL)

/*- APB2 SYS_BUS PERIPHERALS BASE ADDRESSES */
#define GPIOA_BASE 						(0x40010800UL)
#define GPIOB_BASE 						(0x40010C00UL)
#define GPIOC_BASE 						(0x40011000UL)
#define GPIOD_BASE 						(0x40011400UL)
#define AFIO_BASE 						(0x40010000UL)
#define EXTI_BASE 						(0x40010400UL)
#define USART1_BASE						(0x40013800UL)

/*- PERIPHERALS INSTANCES */
#define NVIC							(ST_NVIC_t *)(NVIC_BASE)
#define RCC 							(ST_RCC_t *)(RCC_BASE)

#define GPIOA 							(ST_GPIO_t *)(GPIOA_BASE)
#define GPIOB 							(ST_GPIO_t *)(GPIOB_BASE)
#define GPIOC 							(ST_GPIO_t *)(GPIOC_BASE)
#define GPIOD 							(ST_GPIO_t *)(GPIOD_BASE)
#define AFIO 							(ST_AFIO_t *)(AFIO_BASE)

#define EXTI 							(ST_EXTI_t *)(EXTI_BASE)

#define USART1							(ST_USART_t*)(USART1_BASE)
#define USART2							(ST_USART_t*)(USART2_BASE)
#define USART3							(ST_USART_t*)(USART3_BASE)

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
/*- NVIC REGISTERS */
typedef struct {
  vuint32_t ISER[3];
  uint32_t  RESERVED0[29];
  vuint32_t ICER[3];
  uint32_t  RESERVED1[29];
  vuint32_t ISPR[3];
  uint32_t  RESERVED2[29];
  vuint32_t ICPR[3];
  uint32_t  RESERVED3[29];
  vuint32_t IABR[3];
  uint32_t  RESERVED4[61];
  vuint8_t  IP[80];
  uint32_t  RESERVED5[684];
  vuint32_t STIR;
} ST_NVIC_t;

/*- RCC REGISTERS */
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
  vuint32_t AHBRSTR;
  vuint32_t CFGR2;
} ST_RCC_t;

/*- GPIO REGISTERS */
typedef struct {
  vuint32_t CRL;
  vuint32_t CRH;
  vuint32_t IDR;
  vuint32_t ODR;
  vuint32_t BSRR;
  vuint32_t BRR;
  vuint32_t LCKR;
} ST_GPIO_t;

/*- AFIO REGISTERS */
typedef struct {
  vuint32_t EVCR;
  vuint32_t MAPR;
  vuint32_t EXTICR[4];
  vuint32_t RESERVED;
  vuint32_t MAPR2;
} ST_AFIO_t;

/*- EXTI REGISTERS */
typedef struct {
  vuint32_t IMR;
  vuint32_t EMR;
  vuint32_t RTSR;
  vuint32_t FTSR;
  vuint32_t SWIER;
  vuint32_t PR;
} ST_EXTI_t;

/*- USART REGISTERS */
typedef struct {
  vuint32_t SR;
  vuint32_t DR;
  vuint32_t BRR;
  vuint32_t CR1;
  vuint32_t CR2;
  vuint32_t CR3;
  vuint32_t GTPR;
} ST_USART_t;


#endif /* STM32F101X8_H_ */

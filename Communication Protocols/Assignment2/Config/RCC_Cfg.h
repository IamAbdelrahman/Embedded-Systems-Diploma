/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: RCC_Cfg.h
 *	@brief This module contains interface definitions for the
 *	RCC configuration related to the LQFP48 package.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the RCC peripheral configuration stable.
 *****************************************************************************/

#ifndef INC_RCC_CFG_H_
#define INC_RCC_CFG_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../inc/GPIO_Cfg.h"
#include "../inc/NVIC.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- DEFINE CLOCKS IN HZ */
#define HSI_RC_CLK 	  (8000000UL)
#define HSE_CLK 	  (8000000UL)

/*- DEFINE NUMBER OF USED PERIPHERAL */
#define USED_PERIPHERALS (6U)

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
/*- DEFINE CLOCK TYPES */
typedef enum {
  RCC_SELECT_HSI = 0,
  RCC_SELECT_HSE,
  RCC_SELECT_PLL
} EN_CLOCK_SELECT_t;

/*- DEFINE RESET CONFIGURATION */
typedef enum { SW_RESET_DISABLE = 0, SW_RESET_ENABLE } EN_SW_RESET_t;

/*- DEFINE CLOCK GATES */
typedef enum {
  RCC_GPIOA,
  RCC_GPIOB,
  RCC_GPIOC,
  RCC_GPIOD,
  RCC_AFIO,
  RCC_USART1,
  RCC_USART2,
  RCC_USART3,
  RCC_SPI1,
  RCC_SPI2,
  RCC_I2C1,
  RCC_I2C2,
  RCC_DAC,
} EN_RCC_CLOCK_GATE_t;

/*- DEFINE PLL PREDIV1 PRE-DIVISION FACTOR */
typedef enum {
  PREDIV1_NULL	= -1,
  PREDIV1_1  	= 0x0,
  PREDIV1_2  	= 0x1,
  PREDIV1_3  	= 0x2,
  PREDIV1_4  	= 0x3,
  PREDIV1_5  	= 0x4,
  PREDIV1_6  	= 0x5,
  PREDIV1_7  	= 0x6,
  PREDIV1_8  	= 0x7,
  PREDIV1_9  	= 0x8,
  PREDIV1_10 	= 0x9,
  PREDIV1_11 	= 0xA,
  PREDIV1_12 	= 0xB,
  PREDIV1_13 	= 0xC,
  PREDIV1_14 	= 0xD,
  PREDIV1_15 	= 0xE,
  PREDIV1_16 	= 0xF,
} EN_PREDIV1_t;

/*- DEFINE PLLMUL FACTORS */
typedef enum {
  PLL_X4 = 0x2,
  PLL_X5 = 0x3,
  PLL_X6 = 0x4,
  PLL_X7 = 0x5,
  PLL_X8 = 0x6,
  PLL_X9 = 0x7,
  PLL_X6_5 = 0xD
} EN_PLLMUL_t;

/*- DEFINE APB1-2 DIVISION FACTORS */
typedef enum {
  HCLK_1 = 0x0,
  HCLK_2 = 0x4,
  HCLK_4 = 0x5,
  HCLK_8 = 0x6,
  HCLK_16 = 0x7,
} EN_APBPRESCALER_t;

/*- DEFINE AHB DIVISION FACTOR */
typedef enum {
  SYSCLK_1   = 0x0,
  SYSCLK_2   = 0x8,
  SYSCLK_4   = 0x9,
  SYSCLK_8   = 0xA,
  SYSCLK_16  = 0xB,
  SYSCLK_64  = 0xC,
  SYSCLK_128 = 0xD,
  SYSCLK_256 = 0xE,
  SYSCLK_512 = 0xF,
} EN_AHBPRESCALER_t;

/* DEFINE PLL ENTRY CLOCK SOURCE */
typedef enum { HSI_CLK_BY2 = 0, PREDIV1 } EN_PLL_ENTRY_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/
typedef struct {
  EN_CLOCK_SELECT_t clkSource;
  vuint8_t clkGate[USED_PERIPHERALS];
} ST_RCC_Config_t;

/*- CONFIGURE THE PLL CLOCK */
typedef struct {
  EN_PLL_ENTRY_t pllSource;
  EN_PREDIV1_t pllPrediv1;
  EN_PLLMUL_t pllMul;
} ST_PLL_Config_t;

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
const ST_RCC_Config_t *const RCC_ConfigGet(void);
#endif /* INC_RCC_CFG_H_ */

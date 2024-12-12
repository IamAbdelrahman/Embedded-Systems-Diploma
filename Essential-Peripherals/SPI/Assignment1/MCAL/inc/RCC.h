/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: RCC.h
 *	@brief The interface definition for the RCC
 *
 *	@details: This is the header file for the definition of the interface
 *for a RCC peripheral on a standard microcontroller.
 *****************************************************************************/

#ifndef INCLUDES_RCC_H_
#define INCLUDES_RCC_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "STM32f101x8.h"
#include "../Config/inc/RCC_Cfg.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- ENABLE THE CLOCK FOR THE PERIPHERALS */
#define RCC_GPIOA_CLK_EN() 			(SET_BIT(pRCC->APB2ENR, 2))
#define RCC_GPIOB_CLK_EN() 			(SET_BIT(pRCC->APB2ENR, 3))
#define RCC_GPIOC_CLK_EN() 			(SET_BIT(pRCC->APB2ENR, 4))
#define RCC_GPIOD_CLK_EN() 			(SET_BIT(pRCC->APB2ENR, 5))
#define RCC_USART1_CLK_EN() 		(SET_BIT(pRCC->APB2ENR, 14))
#define RCC_USART2_CLK_EN() 		(SET_BIT(pRCC->APB1ENR, 17))
#define RCC_USART3_CLK_EN() 		(SET_BIT(pRCC->APB1ENR, 18))
#define RCC_AFIO_CLK_EN() 			(SET_BIT(pRCC->APB2ENR, 0))
#define RCC_SPI1_CLK_EN() 			(SET_BIT(pRCC->APB2ENR, 12))
#define RCC_SPI2_CLK_EN() 			(SET_BIT(pRCC->APB1ENR, 14))
#define RCC_I2C1_CLK_EN() 			(SET_BIT(pRCC->APB1ENR, 21))
#define RCC_I2C2_CLK_EN() 			(SET_BIT(pRCC->APB1ENR, 22))
#define RCC_DAC_CLK_EN() 			(SET_BIT(pRCC->APB1ENR, 29))

/*- DISABLE THE CLOCK FOR THE PERIPHERALS */
#define RCC_GPIOA_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 2))
#define RCC_GPIOB_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 3))
#define RCC_GPIOC_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 4))
#define RCC_GPIOD_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 5))
#define RCC_AFIO_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 0))
#define RCC_USART1_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 14))
#define RCC_USART2_CLK_RESET() 		(SET_BIT(pRCC->APB1RSTR, 17))
#define RCC_USART3_CLK_RESET() 		(SET_BIT(pRCC->APB1RSTR, 18))
#define RCC_SPI1_CLK_RESET() 		(SET_BIT(pRCC->APB2RSTR, 12))
#define RCC_SPI2_CLK_RESET() 		(SET_BIT(pRCC->APB1RSTR, 14))
#define RCC_I2C1_CLK_RESET() 		(SET_BIT(pRCC->APB1RSTR, 21))
#define RCC_I2C2_CLK_RESET() 		(SET_BIT(pRCC->APB1RSTR, 22))
#define RCC_DAC_CLK_RESET() 		(SET_BIT(pRCC->APB1RSTR, 29))

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: RCC_Init
 * Syntax: void RCC_Init(ST_RCC_Config_t* configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Enable the selected clk source, wait until it's ready
 * select it clk source, wait until the clk source is ready,
 * and disable other clk sources
 * @param (in): configPtr a pointer to the RCC_Config structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void RCC_Init(const ST_RCC_Config_t *const configPtr);

/************************************************************************
 * Service Name: RCC_Reset
 * Syntax: void RCC_Reset(ST_RCC_Config_t* configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset the clock for all used peripherals
 * @param (in): configPtr a pointer to the RCC_Config structure
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void RCC_Reset(ST_RCC_Config_t *configPtr);

/************************************************************************
 * Service Name: RCC_ModuleReset
 * Syntax: void RCC_ModuleReset(EN_RCC_CLOCK_GATE_t module)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset the clock for a peripheral
 * @param (in): module an enum represents the selected peripheral/module
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void RCC_ModuleReset(EN_RCC_CLOCK_GATE_t module);

/************************************************************************
 * Service Name: RCC_GetSysClk
 * Syntax: vuint32_t RCC_GetSysClk(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the system clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
vuint32_t RCC_GetSysClk(void);

/************************************************************************
 * Service Name: RCC_GetHClk
 * Syntax: vuint32_t RCC_GetHClk(void);
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the AHB bus clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: frequency of the AHB bus clk
 *************************************************************************/
vuint32_t RCC_GetHClk(void);

/************************************************************************
 * Service Name: RCC_GetPClk1
 * Syntax: vuint32_t RCC_GetPClk1(void);
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the APB1 bus clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: frequency of the APB1 bus clk
 *************************************************************************/
vuint32_t RCC_GetPClk1(void);

/************************************************************************
 * Service Name: RCC_GetPClk2
 * Syntax: vuint32_t RCC_GetPClk2(void);
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Get the frequency of the APB2 bus clk in HZ
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: frequency of the APB2 bus clk
 *************************************************************************/
vuint32_t RCC_GetPClk2(void);

#endif /* INCLUDES_RCC_H_ */

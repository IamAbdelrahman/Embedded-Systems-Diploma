/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: NVIC.h
 *	@brief The interface definition for the NVIC core peripheral.
 *
 *	@details This is the header file for the definition of the interface for
 *      the NVIC core peripheral on a standard microcontroller..
 *****************************************************************************/
#ifndef INCLUDES_NVIC_H_
#define INCLUDES_NVIC_H_
/*- INCLUDES
-----------------------------------------------------------------------*/
#include "STM32f101x8.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
/*- INTERRUPT STATUS */
#define NVIC_INTERRUPT_ACTIVE   (1UL)
#define NVIC_INTERRUPT_INACTIVE (0UL)

/*- PRIORITY GROUPS */
#define NVIC_PRIO_16GRP_0SUBGRP (0x300UL)
#define NVIC_PRIO_8GRP_2SUBGRP  (0x400UL)
#define NVIC_PRIO_4GRP_4SUBGRP  (0x500UL)
#define NVIC_PRIO_2GRP_8SUBGRP  (0x600UL)
#define NVIC_PRIO_0GRP_8SUBGRP  (0x700UL)

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
/*- ALL IRQn SUPPORTED BY NVIC */
typedef enum {
  WWDG,
  PVD,
  TAMPER,
  RTC,
  FLASH,
  RCC_IRQ,
  EXTI0_IRQ,
  EXTI1_IRQ,
  EXTI2_IRQ,
  EXTI3_IRQ,
  EXTI4_IRQ,
  DMA1_Channel1,
  DMA1_Channel2,
  DMA1_Channel3,
  DMA1_Channel4,
  DMA1_Channel5,
  DMA1_Channel6,
  DMA1_Channel7,
  ADC1_2,
  USB_HP_CAN_TX,
  USB_HP_CAN_RX,
  CAN_RX1,
  CAN_SCE,
  EXTI5_IRQ,
  EXTI6_IRQ = 23,
  EXTI7_IRQ = 23,
  EXTI8_IRQ = 23,
  EXTI9_IRQ = 23,
  TIM1_BRK,
  TIM1_UP,
  TIM1_TRG_COM,
  TIM1_CC,
  TIM2,
  TIM3,
  TIM4,
  I2C1_EV,
  I2C1_ER,
  I2C2_EV,
  I2C2_ER,
  SPI1_IRQ,
  SPI2_IRQ,
  USART1_IRQ,
  USART2_IRQ,
  USART3_IRQ,
  EXTI10_IRQ,
  EXTI11_IRQ = 40,
  EXTI12_IRQ = 40,
  EXTI13_IRQ = 40,
  EXTI14_IRQ = 40,
  EXTI15_IRQ = 40,
  RTCAlarm
} EN_IRQ_t;

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: NVIC_EnableIRQ
 * Syntax: inline void NVIC_EnableIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to enable an interrupt signal.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_EnableIRQ(EN_IRQ_t IRQn);

/************************************************************************
 * Service Name: NVIC_DisableIRQ
 * Syntax: inline void NVIC_DisableIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to disable an interrupt signal.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_DisableIRQ(EN_IRQ_t IRQn);

/************************************************************************
 * Service Name: NVIC_GetPendingIRQ
 * Syntax: vuint32_t NVIC_GetPendingIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to return true (IRQ-Number) if IRQn is
 *pending.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint32_t NVIC_GetPendingIRQ(EN_IRQ_t IRQn);

/************************************************************************
 * Service Name: NVIC_SetPendingIRQ
 * Syntax: void NVIC_SetPendingIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to set IRQn pending.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_SetPendingIRQ(EN_IRQ_t IRQn);

/************************************************************************
 * Service Name: NVIC_ClearPendingIRQ
 * Syntax: void NVIC_ClearPendingIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to clear IRQn pending status.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_ClearPendingIRQ(EN_IRQ_t IRQn);

/************************************************************************
 * Service Name: NVIC_GetActive
 * Syntax: vuint32_t NVIC_GetActive(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to return the IRQ number of the active
 *interrupt.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint32_t NVIC_GetActive(EN_IRQ_t IRQn);

/************************************************************************
 * Service Name: NVIC_SetPriority
 * Syntax: void NVIC_SetPriority(EN_IRQ_t IRQn, vuint32_t priority)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to set priority for IRQn.
 * @param (in): IRQn
 * @param (in): priority
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_SetPriority(EN_IRQ_t IRQn, vuint32_t priority);

/************************************************************************
 * Service Name: NVIC_GetPriority
 * Syntax: vuint32_t NVIC_GetPriority(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to read priority for IRQn.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint32_t NVIC_GetPriority(EN_IRQ_t IRQn);

#endif /* INCLUDES_NVIC_H_ */

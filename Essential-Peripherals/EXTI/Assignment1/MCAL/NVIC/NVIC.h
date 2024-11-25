/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file NVIC.h
 * @brief The interface definition for the NVIC core peripheral
 *
 * This is the header file for the definition of the interface for the NVIC core
 * peripheral on a standard microcontroller.
 * @author Abdelrahman Kamal
 *
 */

#ifndef NVIC_H_
#define NVIC_H_

/**********************************************************************
 * Includes
 **********************************************************************/
#include "Stm32f101x8.h"
/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
// @ref interrupt_status_define
#define NVIC_INTERRUPT_ACTIVE 	1UL
#define NVIC_INTERRUPT_INACTIVE 	0UL

// @ref priority_groups_define
#define NVIC_PRIO_16GRP_0SUBGRP 	0x300U
#define NVIC_PRIO_8GRP_2SUBGRP 	0x400U
#define NVIC_PRIO_4GRP_4SUBGRP 	0x500U
#define NVIC_PRIO_2GRP_8SUBGRP 	0x600U
#define NVIC_PRIO_0GRP_8SUBGRP 	0x700U

/**********************************************************************
 * Typedefs
 **********************************************************************/
/**
 * Defines an enumerated list of all the IRQn on the NVIC
 * peripheral in STM32 MCU.
 */
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
  SPI1,
  SPI2,
  USART1,
  USART2,
  USART3,
  EXTI10_IRQ,
  EXTI11_IRQ = 40,
  EXTI12_IRQ = 40,
  EXTI13_IRQ = 40,
  EXTI14_IRQ = 40,
  EXTI15_IRQ = 40,
  RTCAlarm

} EN_IRQ_t;
/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void NVIC_enableIRQ(EN_IRQ_t IRQn);
void NVIC_disableIRQ(EN_IRQ_t IRQn);
vuint32_t NVIC_getPendingIRQ(EN_IRQ_t IRQn);
void NVIC_setPendingIRQ(EN_IRQ_t IRQn);
void NVIC_clearPendingIRQ(EN_IRQ_t IRQn);
vuint32_t NVIC_getActive(EN_IRQ_t IRQn);
void NVIC_setPriority(EN_IRQ_t IRQn, vuint32_t priority);
vuint32_t NVIC_getPriority(EN_IRQ_t IRQn);

#endif /* NVIC_H_ */

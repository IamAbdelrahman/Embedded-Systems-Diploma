/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI_Cfg.h
 *	@brief This module contains interface definitions for the
 *	EXTI configuration related to the LQFP48 package.
 *
 *	@details: This is the header file for the definition of the
 *	interface for retrieving the external interrupt peripheral configuration
 *****************************************************************************/
#ifndef INCLUDES_EXTI_CFG_H_
#define INCLUDES_EXTI_CFG_H_

/*- INCLUDES
 -----------------------------------------------------------------------*/
#include "GPIO_Cfg.h"
#include "../MCAL/inc/NVIC.h"

/*- GLOBAL MACROS
 -----------------------------------------------------------------------*/
/*- EXTI PINS NUMBERS */
#define EXTI0 	0U
#define EXTI1 	1U
#define EXTI2 	2U
#define EXTI3 	3U
#define EXTI4 	4U
#define EXTI5 	5U
#define EXTI6 	6U
#define EXTI7 	7U
#define EXTI8 	8U
#define EXTI9 	9U
#define EXTI10 10U
#define EXTI11 11U
#define EXTI12 12U
#define EXTI13 13U
#define EXTI14 14U
#define EXTI15 15U

/*- CONFIGURE EXTI PINS */
#define EXTIPA0_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA0, FALLING, EXTI0, EXTI0_IRQ, IRQ_ENABLE }

#define EXTIPA1_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA1, FALLING, EXTI1, EXTI1_IRQ, IRQ_ENABLE }

#define EXTIPA2_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA2, FALLING, EXTI2, EXTI2_IRQ, IRQ_ENABLE }

#define EXTIPA3_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA3, FALLING, EXTI3, EXTI3_IRQ, IRQ_ENABLE }

#define EXTIPA4_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA4, FALLING, EXTI4, EXTI4_IRQ, IRQ_ENABLE }

#define EXTIPA5_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA5, FALLING, EXTI5, EXTI5_IRQ, IRQ_ENABLE }

#define EXTIPA6_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA6, FALLING, EXTI6, EXTI6_IRQ, IRQ_ENABLE }

#define EXTIPA7_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA7, FALLING, EXTI7, EXTI7_IRQ, IRQ_ENABLE }

#define EXTIPA8_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA8, FALLING, EXTI8, EXTI8_IRQ, IRQ_ENABLE }

#define EXTIPA9_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA9, FALLING, EXTI9, EXTI9_IRQ, IRQ_ENABLE }

#define EXTIPA10_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA10, FALLING, EXTI10, EXTI10_IRQ, IRQ_ENABLE }

#define EXTIPA11_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA11, FALLING, EXTI11, EXTI11_IRQ, IRQ_ENABLE }

#define EXTIPA12_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA12, FALLING, EXTI12, EXTI12_IRQ, IRQ_ENABLE }

#define EXTIPA13_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA13, FALLING, EXTI13, EXTI13_IRQ, IRQ_ENABLE }

#define EXTIPA14_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA14, FALLING, EXTI14, EXTI14_IRQ, IRQ_ENABLE }

#define EXTIPA15_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOA15, FALLING, EXTI15, EXTI15_IRQ, IRQ_ENABLE }

#define EXTIPB0_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB0, FALLING, EXTI0, EXTI0_IRQ, IRQ_ENABLE }

#define EXTIPB1_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB1, FALLING, EXTI1, EXTI1_IRQ, IRQ_ENABLE }

#define EXTIPB2_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB2, FALLING, EXTI2, EXTI2_IRQ, IRQ_ENABLE }

#define EXTIPB3_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB3, FALLING, EXTI3, EXTI3_IRQ, IRQ_ENABLE }

#define EXTIPB4_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB4, FALLING, EXTI4, EXTI4_IRQ, IRQ_ENABLE }

#define EXTIPB5_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB5, FALLING, EXTI5, EXTI5_IRQ, IRQ_ENABLE }

#define EXTIPB6_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB6, FALLING, EXTI6, EXTI6_IRQ, IRQ_ENABLE }

#define EXTIPB7_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB7, FALLING, EXTI7, EXTI7_IRQ, IRQ_ENABLE }

#define EXTIPB8_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB8, FALLING, EXTI8, EXTI8_IRQ, IRQ_ENABLE }

#define EXTIPB9_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB9, FALLING, EXTI9, EXTI9_IRQ, IRQ_ENABLE }

#define EXTIPB10_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB10, FALLING, EXTI10, EXTI10_IRQ, IRQ_ENABLE }

#define EXTIPB11_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB11, FALLING, EXTI11, EXTI11_IRQ, IRQ_ENABLE }

#define EXTIPB12_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB12, FALLING, EXTI12, EXTI12_IRQ, IRQ_ENABLE }

#define EXTIPB13_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB13, FALLING, EXTI13, EXTI13_IRQ, IRQ_ENABLE }

#define EXTIPB14_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB14, FALLING, EXTI14, EXTI14_IRQ, IRQ_ENABLE }

#define EXTIPB15_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOB15, FALLING, EXTI15, EXTI15_IRQ, IRQ_ENABLE }

#define EXTIPC13_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOC13, FALLING, EXTI13, EXTI13_IRQ, IRQ_ENABLE }

#define EXTIPC14_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOC14, FALLING, EXTI14, EXTI14_IRQ, IRQ_ENABLE }

#define EXTIPC15_CFG                                                           \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOC15, FALLING, EXTI15, EXTI15_IRQ, IRQ_ENABLE }

#define EXTIPD0_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOD0, FALLING, EXTI0, EXTI0_IRQ, IRQ_ENABLE }

#define EXTIPD1_CFG                                                            \
  (ST_EXTIConfig_t) {                                                          \
    &GPIOD1, FALLING, EXTI1, EXTI1_IRQ, IRQ_ENABLE }

/*- GLOBAL TYPEDEFS
 -----------------------------------------------------------------------*/
/*- DEFINE TRIGGER STATE */
typedef enum {
	RISING, FALLING, RISING_FALLING
} EN_EXTI_Trigger_t;

/*- DEFINE IRQ STATE */
typedef enum {
	IRQ_DISABLE, IRQ_ENABLE
} EN_EXTI_IRQ_State_t;

/*- DEFINE EXTI Configuration */
typedef struct {
	ST_GPIOConfig_t *const 	pSetExtiPin;
	EN_EXTI_Trigger_t 	   	Trigger;
	vuint8_t 			    lineNumber;
	EN_IRQ_t 				irqNumber;
	EN_EXTI_IRQ_State_t 	irqState;
	void (*CallbackFunction)(void);
} ST_EXTIConfig_t;

/*- GLOBAL VARIABLES
 -----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
 -----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: EXTI_ConfigGet
 * Synatax: const ST_EXTIConfig_t* const EXTI_ConfigGet(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: A helper function to initialize the EXTI based on a config
 * table.
 * PRE-CONDITION: Config table needs to populated (configEXTI > 0)
 * PRE-CONDITION: NUMBER_OF_PORTS > 0 && NUMBER_OF_PINS_PER_PORT > 0
 * PRE-CONDITION: The MCU clock must be configured and enabled
 * POST-CONDITION: A const pointer to the first member of the config table is
 * returned
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: const ST_EXTIConfig_t* const
 *************************************************************************/
ST_EXTIConfig_t* const EXTI_ConfigGet(void);

#endif /* EXTI_CONFIG_H_ */

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: EXTI.h
 * 	@brief The interface definition for the EXTI.
 *
 *	@details: This is the header file for the definition of the interface
 *      for a EXTI peripheral on a standard microcontroller.
 *****************************************************************************/
#ifndef EXTI_H_
#define EXTI_H_

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../Config/inc/EXTI_Cfg.h"
#include "GPIO.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define AFIO_EXTI_MAPPING(PORTX)                                               \
  ((PORTX == PORTA)                                                            \
       ? 0X0                                                                   \
       : (PORTX == PORTB)                                                      \
             ? 0X1                                                             \
             : (PORTX == PORTC) ? 0X2 : (PORTX == PORTD) ? 0X3 : 0)

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: EXTI_Init
 * Syntax: void EXTI_Init(ST_EXTIConfig_t *configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Initialize the EXTI
 * @param (in): configPtr a pointer to EXTIConfig_t struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void EXTI_Init(ST_EXTIConfig_t *configPtr);

/************************************************************************
 * Service Name: EXTI_Update
 * Syntax: void EXTI_Update(ST_EXTIConfig_t *configPtr)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Update the state of EXTI
 * @param (in): configPtr a pointer to EXTIConfig_t struct
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void EXTI_Update(ST_EXTIConfig_t *configPtr);

/************************************************************************
 * Service Name: EXTI_Reset
 * Syntax: void EXTI_Reset(void)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: Reset the state of EXTI
 * @param (in): None
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void EXTI_Reset(void);

#endif /* EXTI_H_ */

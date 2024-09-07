/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/*****************************************************************************
 * FILE DESCRIPTION
 * ----------------------------------------------------------------------------
 *	@file: NVIC.c
 *	@brief The implementation for the NVIC core peripheral.
 *
 *****************************************************************************/

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "inc/NVIC.h"

/*- LOCAL Datatypes
-----------------------------------------------------------------------*/
ST_NVIC_t *pNVIC = NVIC;

/*- LOCAL FUNCTIONS PROTOTYPES
-----------------------------------------------------------------------*/

/*- GLOBAL STATIC VARIABLES
-----------------------------------------------------------------------*/

/*- GLOBAL EXTERN VARIABLES
-----------------------------------------------------------------------*/

/*- LOCAL FUNCTIONS IMPLEMENTATION
-----------------------------------------------------------------------*/

/*- APIs IMPLEMENTATION
-----------------------------------------------------------------------*/
/************************************************************************
 * Service Name: NVIC_EnableIRQ
 * Synatax: inline void NVIC_EnableIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to enable an interrupt signal.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
inline void NVIC_EnableIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ISER[register_Index], IRQn_Index);
}

/************************************************************************
 * Service Name: NVIC_DisableIRQ
 * Synatax: inline void NVIC_DisableIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to disable an interrupt signal.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
inline void NVIC_DisableIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  CLR_BIT(pNVIC->ICER[register_Index], IRQn_Index);
}

/************************************************************************
 * Service Name: NVIC_GetPendingIRQ
 * Synatax: vuint32_t NVIC_GetPendingIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to return true (IRQ-Number) if IRQn is
 *pending.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint32_t NVIC_GetPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  return (READ_BIT(pNVIC->ISPR[register_Index], IRQn_Index));
}

/************************************************************************
 * Service Name: NVIC_SetPendingIRQ
 * Synatax: void NVIC_SetPendingIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to set IRQn pending.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_SetPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ISPR[register_Index], IRQn_Index);
}

/************************************************************************
 * Service Name: NVIC_ClearPendingIRQ
 * Synatax: void NVIC_ClearPendingIRQ(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to clear IRQn pending status.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_ClearPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ICPR[register_Index], IRQn_Index);
}

/************************************************************************
 * Service Name: NVIC_GetActive
 * Synatax: vuint32_t NVIC_GetActive(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to return the IRQ number of the active
 *interrupt.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint32_t NVIC_GetActive(EN_IRQ_t IRQn) {
  vuint32_t return_value;
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  if (READ_BIT(pNVIC->IABR[register_Index], IRQn_Index)) {
    return_value = NVIC_INTERRUPT_ACTIVE;
  } else
    return_value = NVIC_INTERRUPT_INACTIVE;
  return return_value;
}

/************************************************************************
 * Service Name: NVIC_SetPriority
 * Synatax: void NVIC_SetPriority(EN_IRQ_t IRQn, vuint32_t priority)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to set priority for IRQn.
 * @param (in): IRQn
 * @param (in): priority
 * @param (inout): None
 * @param (out): None
 * @return: None
 *************************************************************************/
void NVIC_SetPriority(EN_IRQ_t IRQn, vuint32_t priority) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  pNVIC->IP[(4 * register_Index + IRQn_Index)] = priority;
}

/************************************************************************
 * Service Name: NVIC_GetPriority
 * Synatax: vuint32_t NVIC_GetPriority(EN_IRQ_t IRQn)
 * Sync/Async: Synchronous
 * Reentrancy: Non reentrant
 * @description: This function is used to read priority for IRQn.
 * @param (in): IRQn
 * @param (inout): None
 * @param (out): None
 * @return: volatile unsigned int
 *************************************************************************/
vuint32_t NVIC_GetPriority(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  return (pNVIC->IP[(4 * register_Index + IRQn_Index)]);
}

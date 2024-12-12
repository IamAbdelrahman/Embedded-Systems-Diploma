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
#include "../inc/NVIC.h"

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
inline void NVIC_EnableIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ISER[register_Index], IRQn_Index);
}

inline void NVIC_DisableIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  CLR_BIT(pNVIC->ICER[register_Index], IRQn_Index);
}

vuint32_t NVIC_GetPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  return (READ_BIT(pNVIC->ISPR[register_Index], IRQn_Index));
}

void NVIC_SetPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ISPR[register_Index], IRQn_Index);
}

void NVIC_ClearPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ICPR[register_Index], IRQn_Index);
}

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

void NVIC_SetPriority(EN_IRQ_t IRQn, vuint32_t priority) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  pNVIC->IP[(4 * register_Index + IRQn_Index)] = priority;
}

vuint32_t NVIC_GetPriority(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  return (pNVIC->IP[(4 * register_Index + IRQn_Index)]);
}

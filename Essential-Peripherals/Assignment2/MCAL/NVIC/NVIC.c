/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file NVIC.c
 * @brief The implementation for the NVIC core peripheral.
 *
 * @author Abdelrahman Kamal
 *
 */

/**********************************************************************
 * Includes
 **********************************************************************/
#include "NVIC.h"

/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/

/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Module Variables
 **********************************************************************/
ST_NVIC_t *pNVIC = NVIC;
/**********************************************************************
 * Function Definitions
 **********************************************************************/
/**********************************************************************
 * Function :NVIC_enableIRQ()
 *
 * Description:
 *
 * This function is used to enable an interrupt signal
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return void
 **********************************************************************/
inline void NVIC_enableIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ISER[register_Index], IRQn_Index);
}

/**********************************************************************
 * Function :NVIC_disableIRQ()
 *
 * Description:
 *
 * This function is used to disable an interrupt signal
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return void
 **********************************************************************/
inline void NVIC_disableIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  CLR_BIT(pNVIC->ICER[register_Index], IRQn_Index);
}

/**********************************************************************
 * Function :NVIC_getPendingIRQ()
 *
 * Description:
 *
 * This function is used to return true (IRQ-Number) if IRQn is pending
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return vuint32_t
 **********************************************************************/
vuint32_t NVIC_getPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  return (READ_BIT(pNVIC->ISPR[register_Index], IRQn_Index));
}

/**********************************************************************
 * Function :NVIC_setPendingIRQ()
 *
 * Description:
 *
 * This function is used to set IRQn pending
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return void
 **********************************************************************/
void NVIC_setPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ISPR[register_Index], IRQn_Index);
}

/**********************************************************************
 * Function :NVIC_clearPendingIRQ()
 *
 * Description:
 *
 * This function is used to clear IRQn pending status
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return void
 **********************************************************************/
void NVIC_clearPendingIRQ(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  SET_BIT(pNVIC->ICPR[register_Index], IRQn_Index);
}

/**********************************************************************
 * Function :NVIC_getActive()
 *
 * Description:
 *
 * This function is used to return the IRQ number of the active interrupt
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return vuint32_t
 **********************************************************************/
vuint32_t NVIC_getActive(EN_IRQ_t IRQn) {
  vuint32_t return_value;
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  if (READ_BIT(pNVIC->IABR[register_Index], IRQn_Index)) {
    return_value = NVIC_INTERRUPT_ACTIVE;
  } else
    return_value = NVIC_INTERRUPT_INACTIVE;
  return return_value;
}

/**********************************************************************
 * Function :NVIC_setPriority()
 *
 * Description:
 *
 * This function is used to set priority for IRQn
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return void
 **********************************************************************/
void NVIC_setPriority(EN_IRQ_t IRQn, vuint32_t priority) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  pNVIC->IP[(4 * register_Index + IRQn_Index)] = priority;
}

/**********************************************************************
 * Function :NVIC_getPriority()
 *
 * Description:
 *
 * This function is used to read priority for IRQn
 *
 * @param IRQn: an enumarated variable that configures the IRQn for each
 *interrupt signal.
 *
 * @return vuint32_t
 **********************************************************************/
vuint32_t NVIC_getPriority(EN_IRQ_t IRQn) {
  vuint8_t register_Index = IRQn / 32;
  vuint8_t IRQn_Index = IRQn % 32;
  return (pNVIC->IP[(4 * register_Index + IRQn_Index)]);
}

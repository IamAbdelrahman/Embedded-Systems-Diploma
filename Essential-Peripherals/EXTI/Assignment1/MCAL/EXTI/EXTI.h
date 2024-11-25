/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file EXTI.h
 * @brief The interface definition for the EXTI
 *
 * This is the header file for the definition of the interface for a EXTI
 * peripheral on a standard microcontroller.
 * @author Abdelrahman Kamal
 *
 */

#ifndef EXTI_H_
#define EXTI_H_
/**********************************************************************
 * Includes
 **********************************************************************/
#include "EXTI_Config.h"
#include "GPIO.h"
/**********************************************************************
 * Preprocessor Macros
 **********************************************************************/
#define AFIO_EXTI_MAPPING(PORTX)                                               \
  ((PORTX == PORTA)                                                            \
       ? 0X0                                                                   \
       : (PORTX == PORTB)                                                      \
             ? 0X1                                                             \
             : (PORTX == PORTC) ? 0X2 : (PORTX == PORTD) ? 0X3 : 0)
/**********************************************************************
 * Typedefs
 **********************************************************************/

/**********************************************************************
 * Function Prototypes
 **********************************************************************/
void EXTI_Init(ST_EXTI_PINConfig_t *EXTI_Config);
void EXTI_Update(ST_EXTI_PINConfig_t *EXTI_Config);
void EXTI_Reset(void);

#endif /* EXTI_H_ */

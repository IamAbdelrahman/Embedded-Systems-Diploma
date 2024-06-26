/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file ATmega32.h
 * @brief This header file Header specifies the MCU device header
 *
 * The file defines generic macros and base addresses for memories, peripheral
 * registers and bus peripheral
 * @author Abdelrahman Kamal
 *
 */

#ifndef ATMEGA32_H
#define ATMEGA32_H

#define F_CPU 1000000UL
#include "Platform_Types.h"
#include <util/delay.h>
/**********************************************************************
 * Generic Macros
 **********************************************************************/
#define SET_BIT(REGISTER, BIT_NO) (REGISTER |= (1 << BIT_NO))
#define CLR_BIT(REGISTER, BIT_NO) (REGISTER &= ~(1 << BIT_NO))
#define TOGGLE_BIT(REGISTER, BIT_NO) (REGISTER ^= (1 << BIT_NO))
#define READ_BIT(REGISTER, BIT_NO) ((REGISTER & (1 << BIT_NO)) >> BIT_NO)
#define CHECK_BIT(REGISTER, BIT_NO) ((REGISTER & (1 << BIT_NO)))
#define SWAP_NIBBLES(REGISTER)                                                 \
  ((REGISTER & 0X0F) << 4) | ((REGISTER & 0XF0) >> 4)
#define SWAP_TWO_BYTES(REGISTER)                                               \
  ((REGISTER & 0X00F) << 8) | ((REGISTER & 0XFF00) >> 8)
#define SWAP_ENDIANS(REGISTER)                                                 \
  ((REGISTER & 0X000000FF) << 24) | ((REGISTER & 0X0000FF00) << 8) |           \
      ((REGISTER & 0X00FF0000) >> 8) | ((REGISTER & 0xFF000000) >> 24)
#define MIN(X, Y) ((X) > (Y) ? (Y) : (X))
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define EQUAL ==

/**********************************************************************
 * Typedefs
 **********************************************************************/
typedef enum { LOW = 0, HIGH } EN_State_t;

/**********************************************************************
 * Peripheral base addresses
 **********************************************************************/
#define DIOA_BASE 0x39
#define DIOB_BASE 0x36
#define DIOC_BASE 0x33
#define DIOD_BASE 0x30
#define SFIOR (*((vuint8_t *)0x50))
/**********************************************************************/

typedef struct {
  uint8_t PIN;
  uint8_t DDR;
  uint8_t PORT;
} ST_DIO_t;
/***************************************************/

/***************************************************/
/** Peripheral instances **/
#define DIOA (ST_DIO_t *)(DIOA_BASE)
#define DIOB (ST_DIO_t *)(DIOB_BASE)
#define DIOC (ST_DIO_t *)(DIOC_BASE)
#define DIOD (ST_DIO_t *)(DIOD_BASE)

/**************************************/
#endif /* ATMEGA32_H */

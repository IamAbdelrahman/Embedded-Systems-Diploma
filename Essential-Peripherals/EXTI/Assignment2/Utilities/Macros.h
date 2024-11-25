/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Macros.h
 * @brief This header file Header specifies the generic macros
 *
 * The file defines generic macros that can be used with the MCU applications
 * @author Abdelrahman Kamal
 *
 */

#ifndef MACROS_H_
#define MACROS_H_

/** Generic Macros **/
#define SET_BIT(REGISTER, BIT_NO) 		(REGISTER |= (1U << BIT_NO))
#define CLR_BIT(REGISTER, BIT_NO) 		(REGISTER &= ~(1U << BIT_NO))
#define TOGGLE_BIT(REGISTER, BIT_NO) 		(REGISTER ^= (1U << BIT_NO))
#define READ_BIT(REGISTER, BIT_NO) 		((REGISTER & (1U << BIT_NO)) >> BIT_NO)
#define SET_NIBBLE(REGISTER, POSITION)	(REGISTER |= (0XF << POSITION))
#define SET_NIBBLE_VALUE(REGISTER, VALUE, POSITION)                            \
  						(REGISTER = (REGISTER & ~(0xF << POSITION)) | ((VALUE & 0xF) << POSITION))
#define CLR_NIBBLE(REGISTER, POSITION) 	(REGISTER &= ~(0XF << POSITION))
#define SWAP_NIBBLES(REGISTER)                                                 \
  						((REGISTER & 0X0F) << 4U) | ((REGISTER & 0XF0) >> 4U)
#define SWAP_TWO_BYTES(REGISTER)                                               \
  						((REGISTER & 0X00F) << 8U) | ((REGISTER & 0XFF00) >> 8U)
#define SWAP_ENDIANS(REGISTER)                                                 \
  						((REGISTER & 0X000000FF) << 24U) | ((REGISTER & 0X0000FF00) << 8U) |         \
      						((REGISTER & 0X00FF0000) >> 8U) | ((REGISTER & 0xFF000000) >> 24U)
#define MIN(X, Y) 				((X) > (Y) ? (Y) : (X))
#define MAX(X, Y) 				((X) > (Y) ? (X) : (Y))
#define EQUAL 					==

#endif /* MACROS_H_ */

/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Macros.h
 * @brief Header file containing some commonly used macros.
 *
 * This header file defines several frequently used macros that enhance code readability
 * and simplify common tasks in embedded systems programming. It includes macros for bit
 * manipulation, comparison, and pin configuration.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */

#ifndef MACROS_H
#define	MACROS_H
#include "Platform_Types.h"

#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLEAR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))
#define READ_BIT(X, BIT_NO)     ((X & (1 << BIT_NO)) >> BIT_NO)
#define CHECK_BIT(X, BIT_NO)    ((X & (1 << BIT_NO)))
#define EQ(X, Y)    ((X) == (Y))
#define LT(X, Y)    ((X) < (Y))
#define LE(X, Y)    ((X) <= (Y))
#define GT(X, Y)    ((X) > (Y))
#define GE(X, Y)    ((X) >= (Y))

#define HIGH 1
#define LOW 0


#endif	/* MACROS_H */


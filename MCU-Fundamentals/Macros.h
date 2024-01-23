/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Macro.h
 * 
 * This header file defines various utility macros for bit manipulation, comparison
 * and input/output operations.
 * 
 * @author Abdelrahman Kamal
 * @date 26/4/2023
 *
 */
#ifndef MACROS_H
#define	MACROS_H

#define F_CPU  8000000UL
#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))
#define READ_BIT(X, BIT_NO)     ((X & (1 << BIT_NO)) >> BIT_NO)
#define CHECK_BIT(X, BIT_NO)    ((X & (1 << BIT_NO)))
#define MIN(X, Y)		 ((X) > (Y) ? (Y): (X))
#define MAX(X, Y)		 ((X) > (Y) ? (X): (Y))

#define EQUAL ==
#define IN 0
#define OUT 1

#define HIGH 1
#define LOW 0


#endif	/* MACROS_H */


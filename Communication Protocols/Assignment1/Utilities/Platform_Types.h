/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/

/******************************************************************************
* @file Platform_Types.h
* @brief Header file containing platform-specific macros and type definitions.
*
* @details This file defines various platform-specific macros and standard data types
* to ensure consistent coding conventions and cross-platform compatibility.
******************************************************************************/

#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifdef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FALSE (boolean) false
#endif

#ifndef TRUE
#define TRUE (boolean) true
#endif

/*- INCLUDES
-----------------------------------------------------------------------*/
#include <stdbool.h>
#include <stdint.h>

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define CPU_TYPE 			CPU_TYPE_64
#define CPU_BIT_ORDER 		LSB_FIRST
#define CPU_BYTE_ORDER 		LOW_BYTE_FIRST

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef _Bool 				boolean;
typedef unsigned char 		uint8_t;
typedef signed char 		int8_t;
typedef signed long 		int32_t;
typedef unsigned long 		uint32_t;
typedef long long 			int64_t;
typedef unsigned long long 	uint64_t;

typedef volatile int8_t 	vint8_t;
typedef volatile uint8_t 	vuint8_t;

typedef volatile int16_t 	vint16_t;
typedef volatile uint16_t 	vuint16_t;

typedef volatile int32_t 	vint32_t;
typedef volatile uint32_t 	vuint32_t;

typedef volatile int64_t 	vint64_t;
typedef volatile uint64_t 	vuint64_t;

#endif /* PLATFORM_TYPES_H_ */

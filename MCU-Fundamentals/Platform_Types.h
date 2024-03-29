/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Platform_Types.h
 * 
 * This header file defines fundamental data types and constants 
 * for various platforms.
 * 
 * @author Abdelrahman Kamal
 * @date 12/12/2022
 *
 */

#ifndef PLATFORMS_TYPES_H_
#define PLATFORMS_TYPES_H_

#include <stdbool.h>
#include <stdint.h>

#ifdef _Bool
#define _Bool unsigned char
#endif

#ifndef FALSE
#define FALSE	(boolean)false
#endif

#ifndef TRUE
#define TRUE	(boolean)true
#endif

#define CPU_TYPE        CPU_TYPE_64
#define CPU_BIT_ORDER	MSB_FIRST
#define CPU_BYTE_ORDER	HIGH_BYTE_FIRST

typedef _Bool               boolean;
typedef volatile int8_t     vint8_t;
typedef volatile uint8_t	vuint8_t;

typedef volatile int16_t	vint16_t;
typedef volatile uint16_t	vuint16_t;

typedef volatile int32_t	vint32_t;
typedef volatile uint32_t	vuint32_t;

typedef volatile int64_t	vint64_t;
typedef volatile uint64_t	vuint64_t;

#endif /* PLATFORMS_TYPES_H_ */

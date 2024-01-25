/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Lab4.c
 * 
 * This source file explores the structure, union, and pointers method directly to access
 * all registers in MCU
 * 
 * @author Abdelrahman Kamal
 * @date 22/1/2024
 *
 */

#include <stdio.h>
#include "Macros.h"
#include "Platform_Types.h"
// just for testing in c
uint32_t volatile G_GPIO_ODR_variable[4] = {0};
#define GPIO_B_ADR	&G_GPIO_ODR_variable[0]

#define _IO volatile
typedef struct sgpio{
	_IO uint32_t MODER;	// Mode Register
	_IO uint32_t ODR;	// Output Data Register
	_IO uint32_t ASCR;	// Analog Switch Control Register
	_IO uint32_t IDR;	// Input Data Register
}SGPIO_t;

#define GPIOB ((SGPIO_t*) GPIO_B_ADR)

int main(void)
{
	GPIOB->ODR |= 1 << 16;
	printf("0x%x\n", G_GPIO_ODR_variable);
	return 0;
}


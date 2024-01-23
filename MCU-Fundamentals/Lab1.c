/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Lab1.c
 * 
 * This source file explores the numeric method address directly to access
 * a bit on a register in MCU
 * 
 * @author Abdelrahman Kamal
 * @date 22/1/2024
 *
 */

#include <stdio.h>
#include "Macros.h"
#include "Platform_Types.h"
// just for testing in c
uint32_t volatile G_GPIO_ODR_variable = 0;
#define GPIO_ODR &G_GPIO_ODR_variable
 
 /**
  * On target stm32 mcu
  * #define GPIO_Base 0x48000400
  * #define GPIO_ODR (*(volatile uint8_t*)(GPIO_Base + 0x4))
 */

int main(void)
{
	*(volatile uint32_t*) GPIO_ODR |= 1 << 16;
	printf("0x%x\n", G_GPIO_ODR_variable);
	return 0;
}

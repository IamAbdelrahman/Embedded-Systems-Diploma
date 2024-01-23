/******************************************************************************
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Lab3.c
 * 
 * This source file explores the structure, union, and pointers method directly to access
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
#define GPIO_ODR_ADR	&G_GPIO_ODR_variable
 
 /**
  * On target stm32 mcu
  * #define GPIO_Base 0x48000400
  * #define GPIO_ODR (*(volatile uint8_t*)(GPIO_Base + 0x4))
 */

typedef struct sgpio{
	uint8_t pin0 :1;
	uint8_t pin1 :1;
	uint8_t pin2 :1;
	uint8_t pin3 :1;
	uint8_t pin4 :1;
	uint8_t pin5 :1;
	uint8_t pin6 :1;
	uint8_t pin7 :1;
	uint8_t pin8 :1;
	uint8_t pin9 :1;
	uint8_t pin10 :1;
	uint8_t pin11 :1;
	uint8_t pin12 :1;
	uint8_t pin13 :1;
	uint8_t pin14 :1;
	uint8_t pin15 :1;
	uint8_t pin16 :1;
	uint8_t pin17 :1;
	uint8_t pin18 :1;
	uint8_t pin19 :1;
	uint8_t pin20 :1;

}SGPIO_ODR_t;

typedef union ugpio{
	SGPIO_ODR_t S_ODR;
	volatile uint32_t all;
}UGPIO_ODR_t;

volatile UGPIO_ODR_t* pGPIO_ODR = (UGPIO_ODR_t*) GPIO_ODR_ADR;

int main(void)
{
	pGPIO_ODR->S_ODR.pin16 = 1;
	printf("0x%x\n", G_GPIO_ODR_variable);
	return 0;
}


/*
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Lab5.c
 * 
 * This source file explores the effect of enabling and disabling the clock source
 * So we check this effect on pin 13.
 * 
 * @author Abdelrahman Kamal
 * @date 18/2/2024
 *
 */

#include "Platform_types.h"
#include "Macros.h"

#define RCC_BASE	0x40021000
#define RCC_APB2ENR	(*(volatile uint32_t*)(RCC_BASE + 0x18))

#define GPIOA_BASE	0x40010800
#define GPIOA_CRH	(*(volatile uint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR	(*(volatile uint32_t*)(GPIOA_BASE + 0x0C)) 

typedef union {
	vuint32_t all_fields;
	struct{
		vuint32_t reserved:13 ;
		vuint32_t pin13:1 ;
	}Pin;

}R_ODR_t;

void enableClk();
void ledON();
void ledOFF();
void delay();

volatile R_ODR_t* R_ODR = (volatile uint32_t*)(GPIOA_BASE + 0x0C);

int main(void)
{
	enableClk();
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;

	while (1)
	{
		ledON();
		delay();
		
		ledOFF();
		delay();

	}

	return 0;
}

void enableClk()
{
	SET_BIT(RCC_APB2ENR, 2);	
}

void ledON() 
{
	R_ODR->Pin.pin13 = HIGH;
}

void ledOFF() 
{
	R_ODR->Pin.pin13 = LOW;
}

void delay() 
{
	for (int i = 0; i < 5000; i++);
}

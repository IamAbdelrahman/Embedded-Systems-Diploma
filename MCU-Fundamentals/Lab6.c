/*
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Lab6.c
 * 
 * This source file explores the configuration of STM32-Board to run with the
 	following rates:
	APB1 Bus frequency 4MHZ
	APB2 Bus frequency 2MHZ
	AHB frequency 8 MHZ
	SysClk 8 MHZ
	Use only internal HSI_RC.
 * 
 * @author Abdelrahman Kamal
 * @date 18/2/2024
 *
 */

#include "Platform_Types.h"
#include "Macros.h"

#define RCC_BASE	0x40021000
#define RCC_APB2ENR	(*(volatile uint32_t*)(RCC_BASE + 0x18))
#define RCC_CFGR	(*(volatile uint32_t*)(RCC_BASE + 0x04))

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

volatile R_ODR_t* R_ODR = (volatile uint32_t*)(GPIOA_BASE + 0x0C);

void enableClk();
void ledON();
void ledOFF();
void delay();
void APB2prescalerBy4();
void APB1prescalerBy2();

int main(void)
{
	enableClk();
	APB2prescalerBy4();
	APB1prescalerBy2();
	
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

void APB2prescalerBy4()
{
	SET_BIT(RCC_CFGR, 11);
	CLR_BIT(RCC_CFGR, 12);
	SET_BIT(RCC_CFGR, 13);
	// RCC_CFGR |= (0b101) << 11;
}

void APB1prescalerBy2()
{
	CLR_BIT(RCC_CFGR, 8);
	CLR_BIT(RCC_CFGR, 9);
	SET_BIT(RCC_CFGR, 10);
	// RCC_CFGR |= (0b100) << 8;
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

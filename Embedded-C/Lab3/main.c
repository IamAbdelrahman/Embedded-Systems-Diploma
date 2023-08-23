/*
 * toggleled.c
 *
 *  Created on: Dec 12, 2022
 *      Author: ak
 */
#include "main.h"

volatile R_ODR_t* R_ODR = (volatile uint32_t*)(GPIOA_BASE + 0x0C);
volatile char g_var[3] = {1, 2, 3};
volatile const char const_var[3] = {1, 2, 3};
volatile unsigned char bss_var[1];

int main(void)
{
	SET_BIT(RCC_APB2ENR, 2);
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_ODR |= 0x00200000;

	while (1)
	{
		ledON();
		delay();
		
		ledOFF();
		delay();

	}

	return 0;
}

void ledON() {
	R_ODR->Pin.pin13 = 1;
}

void ledOFF() {
	R_ODR->Pin.pin13 = 0;
}

void delay() {
	for (int i = 0; i < 5000; i++);
}
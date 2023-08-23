/*
 * toggleled.c
 *
 *  Created on: Dec 12, 2022
 *      Author: ak
 */

#include <stdint.h>

typedef volatile unsigned int	vuint32_t;

// registers base address
#define RCC_BASE	0x40021000
#define GPIOA_BASE	0x40010800

/*
 RCC must be used to enable the clock of
 GPIO, because it's disabled by default there
 */

#define RCC_APB2ENR	*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH	*(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(volatile uint32_t*)(GPIOA_BASE + 0x0C) // output data register

typedef union {
	vuint32_t all_fields;
	struct{
		vint32_t reserved:13 ;
		vint32_t pin13:1 ;
	}pin;

}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile uint32_t*)(GPIOA_BASE + 0x0C);
int main()
{
	RCC_APB2ENR |= (1 << 2);
	// to remain the other bits in the register but to make the bits (20:23) = 0
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_ODR |= 0x00200000;

	while (1)
	{
		R_ODR ->pin.pin13 = 1;
		for (int i = 0; i < 5000; i++);

		R_ODR ->pin.pin13 = 0;
		for (int i = 0; i < 5000; i++);

	}

	return 0;
}


/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman M.Kamal
 * @brief          : Enabling External Interrupt "EXT0" in Stm32.
 ******************************************************************************
*/

#include <stdint.h>

typedef volatile unsigned int	vuint32_t;
#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define FALLING 0
#define RISING  1
#define HIGH	1
#define LOW		0

#define RCC_BASE		0x40021000
#define RCC_APB2ENR		(*(vuint32_t*)(RCC_BASE + 0x18))

#define AFIO_BASE		0x40010000
#define AFIO_EXTICR1	(*(vuint32_t*)(AFIO_BASE + 0x08))

#define NVIC_ISER0	(*(vuint32_t*)0xE000E100)
#define EXTI_BASE	0x40010400
#define EXTI_IMR	(*(vuint32_t*)(EXTI_BASE + 0x00))
#define EXTI_FTSR	(*(vuint32_t*)(EXTI_BASE + 0x0C))
#define EXTI_PR		(*(vuint32_t*)(EXTI_BASE + 0x14))

#define GPIOA_BASE	0x40010800
#define GPIOA_CRH	(*(vuint32_t*)(GPIOA_BASE + 0x04))
#define GPIOA_ODR	(*(vuint32_t*)(GPIOA_BASE + 0x0C))
#define GPIOA_CRL   (*(vuint32_t *)(GPIOA_BASE + 0x00))



typedef union {
	vuint32_t all_fields;
	struct{
		vuint32_t reserved:13 ;
		vuint32_t pin13:1 ;
	}Pin;

}R_ODR_t;

void clockInit();
void setglobalInterrupt();
void EXTI0_IRQHandler();
void enableEXTI0 (uint8_t EXIT_STATE);
void clearInterrupt();
void GPIOA_PIN13_Output();
void GPIOA_PIN0_Input();
void ledON();
void ledOFF();
void delay();

volatile R_ODR_t* R_ODR = (R_ODR_t*)(vuint32_t*)(GPIOA_BASE + 0x0C);
volatile unsigned int i = 0;

int main(void)
{
	clockInit();
	AFIO_EXTICR1 = 0x0;	// Select PA0
	GPIOA_PIN0_Input();
	GPIOA_PIN13_Output();
	setglobalInterrupt();
	enableEXTI0(FALLING);

	while (1);
	return 0;
}

void clockInit()
{
	SET_BIT(RCC_APB2ENR, 2);
	SET_BIT(RCC_APB2ENR, 0);
}

void setglobalInterrupt()
{
	// Enable IRQ6 >> EXTI0_IRQHandler
	SET_BIT(NVIC_ISER0, 6);
}

void enableEXTI0 (uint8_t EXIT_STATE)
{
	SET_BIT(EXTI_IMR, 0);
	if (EXIT_STATE == FALLING)
	{
		SET_BIT(EXTI_FTSR, 0);
	}
}

void EXTI0_IRQHandler()
{
	ledON();
	delay();
	ledOFF();
	delay();
	clearInterrupt();
}

void clearInterrupt()
{
	SET_BIT(EXTI_PR, 0);
}

void GPIOA_PIN13_Output()
{
	GPIOA_CRH &= 0xff0fffff;
	GPIOA_CRH |= 0x00200000;
}

void GPIOA_PIN0_Input()
{
	// PinA0: floating input (reset state)
	SET_BIT(GPIOA_CRL, 2);
}

void ledON() {
	R_ODR->Pin.pin13 = LOW;
}

void ledOFF() {
	R_ODR->Pin.pin13 = HIGH;
}

void delay() {
	for (i = 0; i < 5000; i++);
}

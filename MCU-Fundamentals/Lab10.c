/*
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Enable_INI0.c
 * 
 * This source file explores how to enable INT0, INT1, and INT2 in ATmega32, to control
 * 3 leds connected to it.
 * 
 * @author Abdelrahman Kamal
 * @date 16/2/2024
 *
 */

#include <stdint.h>
#include <util/delay.h>

#define F_CPU 1000000UL
typedef volatile unsigned char vuint8_t;
#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))
#define HIGH 1
#define LOW 0
#define FALLING 0
#define RISING 1
#define ANYLOGIC 2

/* PORT D Registers */
#define PORTD   (*((vuint8_t*)0x32))	
#define DDRD    (*((vuint8_t*)0x31))	
#define PIND    (*((vuint8_t*)0x30))

/* PORT B Registers */
#define PORTB   (*((vuint8_t*)0x38))
#define DDRB    (*((vuint8_t*)0x37))
#define PINB    (*((vuint8_t*)0x36))

/* Interrupt Registers */
#define SREG    (*(vuint8_t*)0x5F)
#define GICR    (*(vuint8_t*)0x5B)
#define MCUCR   (*(vuint8_t*)0x55)
#define MCUCSR  (*(vuint8_t*)0x54)

/* External Interrupt Request 0 */
#define EXT_INT_0 __vector_1
/* External Interrupt Request 1 */
#define EXT_INT_1 __vector_2
/* External Interrupt Request 2 */
#define EXT_INT_2 __vector_3

/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#define INT0 	6
#define INT1 	7
#define INT2 	5

/* MCUCR bits */
#define INTF0 6
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3

/* MCUCSR INT2 bit */
#define ISC2 6

/* SREG enable interrupt bit */
#define enable 7


void setglobalInterrupt();
void Enable_INT0(uint8_t INT_STATE);
void Enable_INT1(uint8_t INT_STATE);
void Enable_INT2(uint8_t INT_STATE);
void GPIO_Init();
void ledOn();
void delay();

int main(void) {
	Enable_INT0(ANYLOGIC);
	Enable_INT1(RISING);
	Enable_INT2(FALLING);
	setglobalInterrupt();
	GPIO_Init(); 
	while(1)
	{
		CLR_BIT(PORTD, 5);
		CLR_BIT(PORTD, 6);
		CLR_BIT(PORTD, 7);
	}
    return 0;
}

void GPIO_Init()
{
	/* PD2, PD3, PB2 input-floating */
	CLR_BIT(DDRD, 2);
	CLR_BIT(PORTD, 2);
	
	CLR_BIT(DDRD, 3);
	CLR_BIT(PORTD, 3);
	
	CLR_BIT(DDRB, 2);
	CLR_BIT(PORTB, 2); 
	/* PD5, PD6, PD7 output */
	SET_BIT(DDRD, 5);
	SET_BIT(DDRD, 6);
	SET_BIT(DDRD, 7);
}

void setglobalInterrupt() {
    SET_BIT(SREG, enable);
}

void Enable_INT0(uint8_t INT_STATE) {
	SET_BIT(GICR, INT0);
	if (INT_STATE == FALLING) {
		SET_BIT(MCUCR, ISC01);
		CLR_BIT(MCUCR, ISC00);
		} else if (INT_STATE == RISING) {
		SET_BIT(MCUCR, ISC00);
		SET_BIT(MCUCR, ISC01);
	}
	else{
		SET_BIT(MCUCR, ISC00);
		CLR_BIT(MCUCR, ISC01);
	}
}

void Enable_INT1(uint8_t INT_STATE) {
	SET_BIT(GICR, INT1);
	if (INT_STATE == FALLING) {
		CLR_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
		} else if (INT_STATE == RISING) {
		SET_BIT(MCUCR, ISC10);
		SET_BIT(MCUCR, ISC11);
	}
}

void Enable_INT2(uint8_t INT_STATE) {
	SET_BIT(GICR, INT2);
	if (INT_STATE == FALLING) {
		CLR_BIT(MCUCSR, ISC2);
		} else if (INT_STATE == RISING) {
		SET_BIT(MCUCSR, ISC2);
	}
}

ISR(EXT_INT_0) {
    SET_BIT(PORTD, 5);
	_delay_ms(1000);
}

ISR(EXT_INT_1) {
	SET_BIT(PORTD, 6);
	_delay_ms(1000);
}

ISR(EXT_INT_2) {
	SET_BIT(PORTD, 7);
	_delay_ms(1000);
}


/*
 * Copyright (C) 2024 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Enable_INI0.c
 * 
 * This source file explores how to enable INT0 in ATmega32, to toggle
 * a led connected to it.
 * 
 * @author Abdelrahman Kamal
 * @date 16/2/2024
 *
 */

#include <stdint.h>
#define F_CPU 8000000UL
typedef volatile unsigned char vuint8_t;
#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))

#define HIGH 1
#define LOW 0
#define FALLING 0
#define RISING 1

// PORT D Registers 
#define PORTD   (*((vuint8_t*)0x32))	
#define DDRD    (*((vuint8_t*)0x31))	
#define PIND    (*((vuint8_t*)0x30))

// Interrupt Registers
#define SREG    (*(vuint8_t*)0x5F)
#define GICR    (*(vuint8_t*)0x5B)
#define MCUCR   (*(vuint8_t*)0x55)
#define EXT_INT_0	__vector_1

/* Set Global Interrupt, Set the I-bit in status register to 1 */
#define sei() __asm__ __volatile__ ("sei" ::: "memory")

/* Clear Global Interrupt, Set the I-bit in status register to 0 */
#define cli() __asm__ __volatile__ ("cli" ::: "memory")

/* ISR definition */
#define ISR(INT_VECT)void INT_VECT(void) __attribute__((signal,used));\
void INT_VECT(void)

#define INT0    6
#define ISC00 0
#define ISC01 1


void setglobalInterrupt();
void Enable_INT0(uint8_t INT_STATE);
void GPIOD_PIN7_Output();
void GPIOD_PIN2_Input();
void ledToggle();
void delay();

int main(void) {
	GPIOD_PIN7_Output();
	GPIOD_PIN2_Input();	
	Enable_INT0(FALLING);
	setglobalInterrupt();
	while(1)
	{
		;
	}
    return 0;
}

void setglobalInterrupt() {
    SET_BIT(SREG, 7);
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
}
void GPIOD_PIN7_Output() {
    SET_BIT(DDRD, 7);
}

void GPIOD_PIN2_Input() {
    CLR_BIT(DDRD, 2);
    SET_BIT(PORTD, 2);
    // PD2 Input-High PUR
}

void ledToggle()
{
   TOGGLE_BIT(PORTD, 7); 
}

ISR(EXT_INT_0) {
    ledToggle();
}

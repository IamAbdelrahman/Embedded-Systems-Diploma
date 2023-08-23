#include <stdint.h>
typedef volatile unsigned int	vuint32_t;

// registers base address
#define RCC_BASE	0x40021000
#define GPIOA_BASE	0x40010800
#define RCC_APB2ENR	*(volatile uint32_t*)(RCC_BASE + 0x18)
#define GPIOA_CRH	*(volatile uint32_t*)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(volatile uint32_t*)(GPIOA_BASE + 0x0C) 
#define SET_BIT(X, BIT_NO)	(X|= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)	(X&= ~(1 << BIT_NO))

typedef union {
	vuint32_t all_fields;
	struct{
		vuint32_t reserved:13 ;
		vuint32_t pin13:1 ;
	}Pin;

}R_ODR_t;

extern void NMI_Handler (void) {}
extern void Bus_Fault (void) {}

void ledON();
void ledOFF();
void delay();
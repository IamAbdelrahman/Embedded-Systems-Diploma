#include "Platform_Types.h"
#define SYSCTL_RCGC2_R	    (*(uint64_t*)0x400FE108)
#define GPIO_PORTF_DIR_R	(*(uint64_t*)0x40025400)	
#define GPIO_PORTF_DEN_R	(*(uint64_t*)0x4002551C)	
#define GPIO_PORTF_DATA_R	(*(uint64_t*)0x400253FC)	

#define SET_BIT(X, BIT_NO)      (X |= (1 << BIT_NO))
#define CLR_BIT(X, BIT_NO)      (X &= ~(1 << BIT_NO))
#define TOGGLE_BIT(X, BIT_NO)   (X ^= (1 << BIT_NO))
#define READ_BIT(X, BIT_NO)     ((X & (1 << BIT_NO)) >> BIT_NO)
#define CHECK_BIT(X, BIT_NO)    ((X & (1 << BIT_NO)))

#define IN 0
#define OUT 1

#define HIGH 1
#define LOW 0

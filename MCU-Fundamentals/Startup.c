/*
Startup.c by Abdelrahman Kamal >> Learn-in-Depth
*/

#include <stdint.h>
#define STACK_Start_SP	0x20001000

void Reset_Handler(void);
extern int main(void);

void Default_Handler(void) {
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));
extern unsigned int _stack_top;

uint32_t vectors[] __attribute__ ((section(".vectors"))) = {
(uint32_t) &_stack_top,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &Bus_Fault,

};

extern unsigned int _E_TEXT;
extern unsigned int _S_DATA;
extern unsigned int _E_DATA;
extern unsigned int _S_BSS;
extern unsigned int _E_BSS;

void Reset_Handler (void) {

	/* Copy .data segment from flash to ram */
	unsigned int DATA_SIZE = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA;
	unsigned char* P_src = (unsigned char*)&_E_TEXT;
	unsigned char* P_dst = (unsigned char*)&_S_DATA;
	for (int i = 0; i < DATA_SIZE; i++) {
		*((unsigned char*)P_dst) = *((unsigned char*)P_src++);
	}

	/* Initialize the .bss segment by zeros*/
	unsigned int BSS_SIZE = (unsigned char*)&_S_BSS - (unsigned char*)&_E_BSS;
	P_dst = (unsigned char*)&_S_BSS;
	for (int i = 0; i < BSS_SIZE; i++) {
		*((unsigned char*)P_dst++) = (unsigned char)0;
	}

	main();
}

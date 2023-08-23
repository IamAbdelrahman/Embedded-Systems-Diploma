#include "UART.h"
unsigned char string_buffer [100] = "learn-in-depth <Abdelrahman> ";
unsigned char const string_buffer2 [100] = "create a .rodata section";

void main(void) {
	UART_send_string(string_buffer);
}

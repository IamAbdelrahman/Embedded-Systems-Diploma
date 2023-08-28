/*
 * toggleLed on Tivac MCU
 *      Author: ak
 */

#include "main.h"
int main()
{
	volatile uint32_t delay_count = 0;
	SYSCTL_RCGC2_R = 0x20;
	// Add delay to make sure GPIO is up and running
	for (delay_count = 0; delay_count < 200; delay_count++);

	SET_BIT(GPIO_PORTF_DIR_R, 3);
	SET_BIT(GPIO_PORTF_DEN_R, 3);

	while (1) {
		TOGGLE_BIT(GPIO_PORTF_DATA_R, 3);
		for (delay_count = 0; delay_count < 5000; delay_count++);
	}

	return 0;
}


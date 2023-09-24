/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file P_Sensor.c
 *
 * Source file containing pressure sensor functions' implementations.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "P_Sensor.h"

void Delay(vuint32_t Period)
{
	vuint32_t Timer = 0;
	for (; Timer <= Period; Timer++)
		;
}

PS_STATE_t psInit(void)
{
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	return PRESSURE_SENSOR_STATE_INIT;
}

PS_STATE_t getPressureVal(vuint8_t *PPValue)
{
	*PPValue = GPIOA_IDR & 0xFF;

	if (*PPValue)
	{
		return PRESSURE_SENSOR_STATE_READING;
	}

	Delay(PRESSURE_POLL_TIME);

	return PRESSURE_SENSOR_STATE_WAITING;
}

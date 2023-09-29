/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file main.c
 *
 * This source file contains the main entry point for the Pressure Control System application.
 * It initializes the application and continuously starts the monitoring process.
 * The system keeps monitoring the pressure conditions and activates the alarm when needed.
 *
 * @author Abdelrahman Kamal
 * @date 21/9/2023
 *
 */
#include "APP/APP.h"

int main()
{
	// Initialize the application
	appInit();

	// Continuous monitoring loop
	while (1)
	{
		appStart();
	}

	// The program should never reach this point
	return 0;
}

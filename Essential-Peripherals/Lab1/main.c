/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdelrahman Kamal
 * @brief          : Main program body
 ******************************************************************************
*/

#include "APP.h"

int main(void)
{
	APP_Init();
	while (1) {
		APP_Start();
	}
	return 0;
}


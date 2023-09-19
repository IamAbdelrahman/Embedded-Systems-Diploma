#include "US.h"
int US_distance = 0;

void (*US_state)();

void US_init()
{
	// init_US_Driver
	printf("US_init\n");
}
State_define(US_Busy)
{
	US_STATE state_id = US_BUSY;
	printf("US_Busy State: distance = %d \n", US_distance);
	US_distance = generate_random_distance(45, 55, 1);
	US_get_distance(US_distance);
	US_state = State(US_Busy);
}

int generate_random_distance(int l, int r, int count)
{
	// Generates a random number in range l and r
	int i = 0;
	for (i = 0; i < count; i++)
	{
		int rand_num = l + rand() % (r - l) + 1;
		return rand_num;
	}
	return 0;
}

#include "CA.h"

int CA_speed = 0, CA_distance = 0, CA_threshold = 50;

void (*CA_state)();

void US_get_distance(int d)
{
	CA_distance = d;
	(CA_distance > CA_threshold) ? (CA_state = State(CA_Moving)) : (CA_state = State(CA_Waiting));
	printf("US--------distance = %d-------> CA \n", CA_distance);
}

State_define(CA_Waiting)
{
	CA_STATE state_id = CA_WAITING;
	printf("Waiting State : distance = %d speed = %d\n", CA_distance, CA_speed);
	CA_speed = 0;
	DC_set_speed(CA_speed);
}

State_define(CA_Moving)
{
	CA_STATE state_id = CA_MOVING;
	printf("Moving State : distance = %d speed = %d\n", CA_distance, CA_speed);
	CA_speed = 50;
	DC_set_speed(CA_speed);
}

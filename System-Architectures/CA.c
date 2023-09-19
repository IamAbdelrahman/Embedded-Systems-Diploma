#include "CA.h"

// Variables

int CA_speed = 0, CA_distance = 0, CA_threshold = 50;

// State pointers to functions

void (*CA_state) ();

State_define (CA_Waiting) 
{
	// State action
	CA_STATE  state_id = CA_WAITING;
	CA_speed = 0;
	CA_distance = generate_random_distance(45, 55, 1);

	// Check event
	(CA_distance <= CA_threshold) ? (CA_state = State(CA_Waiting)) : (CA_state = State(CA_Moving));
	printf("Waiting State : distance = %d speed = %d\n", CA_distance, CA_speed);
}

State_define (CA_Moving)
{
	// State action
	CA_STATE state_id = CA_MOVING;
	CA_speed = 50;
	CA_distance = generate_random_distance(45, 55, 1);

	// Check event
	(CA_distance > CA_threshold) ? (CA_state = State(CA_Moving)) : (CA_state = State(CA_Waiting));
	printf("Moving State : distance = %d speed = %d\n", CA_distance, CA_speed);
}

int generate_random_distance (int l, int r, int count) {
	// Generates a random number in range l and r
	int i = 0;
	for (i = 0; i < count; i++) {
		int rand_num = l + rand() % (r - l) + 1;
		return rand_num;
	}
	return 0;
}
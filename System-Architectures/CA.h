#include "State.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
// Define States
typedef enum state {
	CA_WAITING,
	CA_MOVING
}CA_STATE;

// Decalre state functions CA
State_define(CA_Waiting);
State_define(CA_Moving);

// Global pointer to function
extern void (*CA_state) ();

int generate_random_distance(int, int, int);

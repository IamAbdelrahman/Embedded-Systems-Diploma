#ifndef CA_H_
#define CA_H_
#include "State.h"

typedef enum CA_state
{
	CA_WAITING,
	CA_MOVING
} CA_STATE;

State_define(CA_Waiting);
State_define(CA_Moving);

extern void (*CA_state)();

#endif // !CA_H_
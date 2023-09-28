#ifndef DC_H_
#define DC_H_
#include "State.h"

typedef enum DC_state
{
	DC_IDLE,
	DC_BUSY
} DC_STATE;

State_define(DC_Idle);
State_define(DC_Busy);

extern void (*DC_state)();
void DC_init();

#endif // !DC_H_

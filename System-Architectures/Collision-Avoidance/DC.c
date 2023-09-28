#include "DC.h"

int DC_speed = 0;

void (*DC_state)();

void DC_init()
{
    // DC_init Driver
    printf("DC_init\n");
}

void DC_set_speed(int s)
{
    DC_speed = s;
    printf("speed = %d\n", DC_speed);
    DC_state = State(DC_Busy);
}
State_define(DC_Idle)
{
    DC_STATE state_id = DC_IDLE;
    printf("Idle State : speed = %d\n", DC_speed);
}

State_define(DC_Busy)
{
    DC_STATE state_id = DC_BUSY;
    DC_state = State(DC_Idle);
    printf("Busy State : speed = %d\n", DC_speed);
}

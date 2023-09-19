#ifndef _STATE_H_
#define _STATE_H_
#include "State.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
// Automate state function generated
#define State_define(_stateFun_) void ST_##_stateFun_()
#define State(_stateFun_) ST_##_stateFun_ // Address of the function
int generate_random_distance(int, int, int);

/* States Connections > Interfaces */
void US_get_distance(int d);
void DC_set_speed(int s);

#endif /*_STATE_H_*/
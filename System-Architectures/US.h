#ifndef US_H_
#define US_H_
#include "State.h"

typedef enum US_state
{
    US_BUSY
} US_STATE;

State_define(US_Busy);

extern void (*US_state)();
void US_init();

#endif // !US_H_

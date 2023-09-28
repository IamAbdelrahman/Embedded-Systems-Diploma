#include "CA.h"
#include "US.h"
#include "DC.h"
void setup()
{
    DC_init();
    US_init();
    CA_state = State(CA_Waiting);
    US_state = State(US_Busy);
    DC_state = State(DC_Idle);
}
int main(void)
{
    volatile int d;
    setup();
    // To change numbers every one second in rand() function
    srand(time(NULL));
    while (1)
    {
        CA_state();
        US_state();
        DC_state();
        for (d = 0; d <= 1000; d++)
            ;
    }

    return 0;
}
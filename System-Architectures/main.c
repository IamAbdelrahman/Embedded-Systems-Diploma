#include "CA.h"
void setup () {
    // motor_init();
    // init_Soc_modules
    CA_state = State(CA_Waiting);
}
int main(void) {
    volatile int d;
    setup();
    // To change numbers every one second in rand() function
    srand(time(NULL));
    while (1) {
        // Calling functions using CA_state() pointer to function.
        CA_state();
        for (d = 0; d <= 1000; d++);
    }
    
    return 0;
}
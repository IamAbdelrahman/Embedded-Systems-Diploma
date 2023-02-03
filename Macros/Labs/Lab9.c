/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs: Using Debugging messages
*/

#include <stdio.h>
#define debug 
// #define debug (Nodebug)
#define Dprintf(debug_level, ...) if (debug_level > 1) {\
                            printf("__func__ is %s at line %d in file %s", __func__, __LINE__, __FILE__);\
                            printf(">>\t");\
                            printf(__VA_ARGS__);}
void CAN_init()
{
    #ifdef debug
    Dprintf(3, "\n");
    #endif
}
        
int main(void)
{   
    Dprintf(2, "enter main\n");
    CAN_init();
    Dprintf(4, "exit main\n");
    return 0;
}
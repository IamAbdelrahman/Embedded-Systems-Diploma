/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs using #undef
*/

#include <stdio.h>
#define height 100
int main(void)
{   
    printf("The height is %d\n", height);
    #undef height
    #define height 500
    printf("The height is %d\n", height);
    
    return 0;
}

/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs using __VA_ARGS
*/

#include <stdio.h>
#define value 3
#define AK(...) printf(__VA_ARGS__)
#define learnInDepth(a, ...) printf(__VA_ARGS__, a)

int main(void)
{   
    printf("value = %d\n", value);
    AK("Value = %d\n", value);
    learnInDepth(value, "Value = %d\n");

    return 0;
}
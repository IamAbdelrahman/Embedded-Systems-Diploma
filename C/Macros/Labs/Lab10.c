/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs: Pragma Example
*/

#include <stdio.h>
void usa();
void india();

// Method one
#pragma startup india 105
#pragma startup usa 
#pragma exit usa 
#pragma exit india 105


// Method two

void __attribute__ ((constructor)) usa(); // == startup
void __attribute__ ((constructor)) india();
void __attribute__ ((destructor)) usa(); // == exit
void __attribute__ ((destructor)) india(); // == exit


int main(void)
{
    printf("I'm in main\n");
    return 0;
}

void usa ()
{
    printf("I'm in usa\n"); 
}

void india ()
{
    printf("I'm in india\n");
}

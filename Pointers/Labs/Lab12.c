/*
    Author: Abdelrahman Kamal
    Program: Pointer to functions
*/

#include <stdio.h>

void (*gPtr_func) ();
void print_online_diploma ()
{
    printf("LearnInDepth-Diploma\n");
}

int main(void)
{   
    gPtr_func = print_online_diploma;
    gPtr_func();
    return 0;
}
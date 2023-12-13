/*
    Author: Abdelrahman Kamal
    Program: Pointer Labs - Unknown Pointer
*/

#include <stdio.h>
int main(void)
{   
    int x = 10;
    char y = 20;
    void *Ptr;
    // R/W issue on x variable
    Ptr = &x;
    printf("The old value of x is %d\n", x);
    printf("The old value of y is %d\n", y);

    *(int*)Ptr = 11;
    printf("The new value of x is %d\n", x);
    
    Ptr = &y;
    *(char*)Ptr = 21;
    printf("The new value of y is %d\n", y);

    return 0;
}
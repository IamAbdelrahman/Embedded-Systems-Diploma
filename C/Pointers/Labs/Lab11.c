/*
    Author: Abdelrahman Kamal
    Program: Pointer to Pointer example
*/

#include <stdio.h>
int main(void)
{   
    int x = 7, y = 9;
    int *Px = &x;
    int* *PPx = &Px;
    printf("x = %d and y = %d\n", x, y);
    printf("Address of x = %x and y = %x\n", &x, &y);
    *Px = 12;
    printf("New value of x is %d\n", *Px);
    **PPx = 13;
    printf("New value of x is %d\n", **PPx);

    *PPx = &y;
    *Px = 11;
    printf("Value of x = %d and value of y = %d\n", x, y);
    return 0;
}
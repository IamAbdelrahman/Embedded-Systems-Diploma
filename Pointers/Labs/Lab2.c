/*
    Author: Abdelrahman Kamal
    Program: Pointer Variables
*/
#include <stdio.h>
int main(void)
{   
    int x = 5;
    int y = 7;
    int *ptr = &x;
    printf("The address of x is %x, y is %x, and ptr is %x\n",&x, &y, &ptr);
    printf("The value of x is %d, value that's pointed by ptr is %d\n", x, *ptr);
    *ptr = 14;
    printf("The value of x is %d, value that's pointed by ptr is %d\n", x, *ptr);
    ptr = &y;
    printf("The value of x is %d, value that's pointed by ptr is %d\n", x, *ptr);
    *ptr = 20;
    printf("The value of y is %d, value that's pointed by ptr is %d\n", y, *ptr);
    ptr = 0;
    // *ptr = 15; it will give us a fatal-error because we try to access a forbidden area of the memory
    return 0;
}
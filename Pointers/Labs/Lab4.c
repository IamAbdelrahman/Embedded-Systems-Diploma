/*
    Author: Abdelrahman Kamal
    Program : Pointer to Arrays
*/

#include <stdio.h>
int main(void)
{   
    int x [5] = {1, 2, 3, 4, 5};
    int *p = x; // == &x[0]
    printf("%d\n", *p);
    p++;
    printf("%d\n", *p);
    p++;
    printf("%d\n", *p);
    p = x + 3;
    printf("%d\n", *p);
    p--;
    printf("%d\n", *p);
    // Here the array has the same data type of the pointer.
    return 0;
}
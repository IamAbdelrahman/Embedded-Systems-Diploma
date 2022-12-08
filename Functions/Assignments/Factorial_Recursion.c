/*
Author: Abdelrahman Kamal
Program: Calculate a factorial of a number
using a recursion
*/

#include <stdio.h>

int fact (int);
void main(void)
{
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Factorial of %d = %d\n",num, fact(num));
}

int fact (int x)
{
    if (x == 0 || x == 1)
        return 1;

    else
        return (x * fact(x - 1));
}

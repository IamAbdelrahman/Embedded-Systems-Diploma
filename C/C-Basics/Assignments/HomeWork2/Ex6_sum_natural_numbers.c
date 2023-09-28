/*
Author: Abdelrahman Kamal
Summation of natural numbers */

#include <stdio.h>
int main (void)
{
    int n, i = 0, sum = 0;
    printf("Enter an integer: ");
    scanf("%d", &n);

    for (i; i <= n; i++)
        sum += i;

    printf("Sum = %d\n", sum);
}

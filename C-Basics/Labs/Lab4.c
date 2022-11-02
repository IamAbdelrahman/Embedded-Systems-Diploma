/*
Author: Abdelrahman Kamal
Lab: Calculate the summation of values between 1:99 */

#include <stdio.h>
int main(void)
{
    int sum = 0;
    int i = 1;

    for (i; i < 100; ++i)
    {
        sum += i;
    }

    printf("The summation of values between 1:99 is = %d\n", sum);
}

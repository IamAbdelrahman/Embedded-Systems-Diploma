/*
Author: Abdelrahman Kamal
Swap two numbers */

#include <stdio.h>
int main(void)
{
    float num1, num2, z;
    printf("Enter value of a: ");
    scanf("%f", &num1);

    printf("Enter value of b: ");
    scanf("%f", &num2);

    // swap algorithm without using temp variable
    z = num1 + num2;
    printf("After swapping, value of a = %.2f\n", z - num1);
    printf("After swapping, value of b = %.2f\n", z - num2);


}

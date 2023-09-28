/*
Author: Abdelrahman Kamal
Multiply two floating points numbers */

#include <stdio.h>
int main(void)
{
    float num1, num2;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);

    printf("Product: %f\n", num1 * num2);
    return 0;
}

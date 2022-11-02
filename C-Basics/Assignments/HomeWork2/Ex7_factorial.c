/*
Author: Abdelrahman Kamal
Find the factorial of positive numbers */

#include <stdio.h>
int main(void)
{
    int number, i = 0, product = 1;

    printf("Enter an integer: ");
    scanf("%d", &number);
    int loop = number;

    if ( number < 0)
        printf("Error !!! Factorial of non-positive numbers does not exist.\n");

    else if (number == 0 || number == 1)
        printf("Factorial = 1\n");

    else
    {
        for (i; i < loop; i++)
        {
            product *= number;
            number--;
        }

        printf("Factorial = %d\n", product);
    }
}

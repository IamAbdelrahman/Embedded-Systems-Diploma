/*
    Author: Abdelrahman Kamal
    Program: Write a C function to take an integer number
    and calculate it's square root
*/
#include <stdio.h>
#include <math.h>

double squareRoot(double);
int main(void)
{
    double number;
    int testCases = 2, i = 0;

    for (i; i < testCases; i++)
    {

    printf("Enter your number: ");
    scanf("%lf", &number);
    printf("%lf\n", squareRoot(number));

    }

    return 0;
}

double squareRoot (double n)
{
    return pow (n, 0.5);
}

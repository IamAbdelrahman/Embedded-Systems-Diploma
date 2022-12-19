/*
    Author: Abdelrahman Kamal
    Program: Write a C function to take a number and sum all digits
*/

#include <stdio.h>

int sum_digits (int);
void main(void)
{
    int number, testCases = 2, i = 0;
    for (i; i < testCases; i++)
    {

    printf("Enter your number: ");
    scanf("%d", &number);

    printf("The sum of the digits is %d\n", sum_digits(number));
    }
}

int sum_digits(int n)
{
    int sum = 0, reminder = 0;
    if (n != 0)
    {
        reminder = n % 10;
        sum += reminder;
        return sum + sum_digits( n / 10);
    }

    else
        return 0;
}

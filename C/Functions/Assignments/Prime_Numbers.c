/*
Author: Abdelrahman Kamal
Program: Find prime numbers between two
intervals
*/

#include <stdio.h>

void findPrime (int, int);

void main (void)
{
    int num1, num2;

    printf("Enter two numbers (intervals): ");
    scanf("%d %d", &num1, &num2);

    findPrime (num1, num2);
    puts("");
}

void findPrime (int n1, int n2)
{
    // To check prime numbers
    int isPrime (int);

    // Go out if negative intervals (numbers)
    if (n1 < 0 || n2 < 0)
    {
        printf("Invalid inputs!\n");
        return;
    }

    else if ( n1 < n2)
    {
        int i = 0, index = 0;
        printf("Prime numbers between %d and %d are: ", n1, n2);

        for (i = n1; i <= n2; ++i)
        {
            if( isPrime(i) )
                printf("%d ", i);

            else
                continue;
        }
    }

    else
    {
        int i = 0, index = 0;
        printf("Prime numbers between %d and %d are: ", n2, n1);

        for (i = n2; i <= n1; ++i)
        {
            if( isPrime(i) )
                printf("%d ", i);

            else
                continue;
        }
    }
}

int isPrime (int x)
{
    int ret = 0; // return value

    if ( x == 2)
        ret = 1;

    else
    {
        int j = 0;
        for (j = 2; j < x; ++j)
        {
            if ( x % j != 0)
                ret = 1;

            else
                return 0; // ret = 0 problem
        }

    }

    return ret;
}

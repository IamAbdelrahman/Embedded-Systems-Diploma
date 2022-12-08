/*
Author: Abdelrahman Kamal
Program: Calculate the Factorial
*/

#include <stdio.h>

int fact (int); // function declaration
void main(void)
{
    int num = 0;

    for (num = 0; num <= 10; num++)
        printf("Factorial of %d = %d\n", num, fact(num));
}

int fact (int x)
{
    int product = 1;

    if (x == 0 || x == 1)
        return product;

    else
    {
       for (; x > 0; x--)
            product *= x;

        return product;
    }


}

/*
    Author: Abdelrahman Kamal
    Program: Write a C function to sum numbers from 1 to 100
    (without loop)
*/

#include <stdio.h>
int sum (int);

void main(void)
{
    int number = 1;
    printf("The sum between 1:100 is %d\n", sum(number));


}

int sum (int n)
{
    if (n > 100)
        return 0;

    else
        return n + sum (n + 1);
}

/*
Author: Abdelrahman Kamal
Check positive or negative or zero */

#include <stdio.h>
int main(void)
{
    float number;
    printf("Enter a number: ");
    scanf("%f", &number);

    if (number > 0)
        printf("%f is positive\n", number);

    else if (number < 0)
        printf("%f is negative\n", number);

    else
        printf("You entered zero\n");
}



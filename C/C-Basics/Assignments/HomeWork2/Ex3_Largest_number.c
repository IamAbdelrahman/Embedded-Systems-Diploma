/*
Author: Abdelrahman Kamal
Check vowle or consonant */

#include <stdio.h>
int main(void)
{
    float num1, num2, num3;
    printf("Please, enter your 3 numbers:");
    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    if (num1 >= num2 && num2 > num3)
        printf("The greatest number is %f\n", num1);

    else if (num2 >= num1 && num2 > num3)
        printf("The greatest number is %f\n", num2);

    else printf("The greatest number is %f\n", num3);
}

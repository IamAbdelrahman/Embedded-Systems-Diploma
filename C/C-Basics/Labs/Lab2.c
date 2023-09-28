/*
Author: Abdelrahman Kamal
Lab: Comparing 3 numbers */

#include <stdio.h>
int main(void)
{
    int num1, num2, num3;
    printf("Please, enter your 3 numbers:");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 >= num2 && num2 > num3)
        printf("The greatest number is %d\n", num1);

    else if (num2 >= num1 && num2 > num3)
        printf("The greatest number is %d\n", num2);

    else printf("The greatest number is %d\n", num3);
}

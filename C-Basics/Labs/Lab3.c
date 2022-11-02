/*
Author: Abdelrahman Kamal
Lab: Calculate the min of 2 numbers */

#include <stdio.h>
int main(void)
{
    int num1, num2, min = 0;
    printf("Please, enter your 2 numbers: ");
    scanf("%d %d", &num1, &num2);

    min = (num1 > num2)? num2:num1;
    printf("The minimum number is %d\n", min);


}

/*
Author: Abdelrahman Kamal
Lab: Calculate the Average
Students Degrees */

#include <stdio.h>
int main(void)
{
    int n, i = 0;
    float degree = 0.0, sum = 0.0;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (i; i < n; i++)
    {
        printf("Enter student (%d) degree: ", i + 1);
        scanf("%f", &degree);
        sum += degree;
    }

    printf("The average of degrees is %f\n", sum / n);
}




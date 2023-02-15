/*
    Author: Abdelrahman Kamal
    Program: Assignment (1) : Write a C-Program to calculate
    the area of the circle using macros
*/

#include <stdio.h>
#define PI  3.14
#define AREA_CIRCLE(R)  ((R) * (R) * PI)

int main(void)
{   
    float radius;
    printf("Enter the radius: ");
    scanf("%f", &radius);
    printf("Area = %.2f\n", AREA_CIRCLE(radius));

    return 0;
}
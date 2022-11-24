/*
Author: Abdelrahman Kamal
Program: Calculate Polynomial
Value for a Set of Inputs
*/

#include <stdio.h>
int main(void)
{
    int poly [5], i = 0;
    float y;

    for (i = 0; i < 5; i++)
        scanf("%d", &poly[i]);

    for (i = 0; i < 5; i++)
    {
        y = 5 * poly[i] * poly[i] + 3 * poly[i] + 2;
        printf("y(%d) = %f\n", poly[i], y);
    }

}

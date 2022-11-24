/*
Author: Abdelrahman Kamal
Program: Find the sum of 2 matrices [2] [2]
*/

#include <stdio.h>
void main(void)
{
    float mat_1 [2][2], mat_2 [2][2] ;
    float mat_sum [2][2] ;

    int row = 0 , col = 0;

    printf("Enter the elements of 1st matrix\n");

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("Enter a %d%d: ", row + 1, col + 1);
            scanf("%f", &mat_1[row] [col]);
        }
    }

    printf("Enter the elements of 2nd matrix\n");

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("Enter a %d%d: ", row + 1, col + 1);
            scanf("%f", &mat_2[row] [col]);
        }
    }

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            mat_sum [row] [col] = mat_1 [row] [col] + mat_2 [row] [col];
        }
    }

    printf("Sum of matrix\n");

    for (row = 0; row < 2; row++)
    {
        for (col = 0; col < 2; col++)
        {
            printf("%.2f ", mat_sum [row] [col]);
        }

        puts("");
    }



}

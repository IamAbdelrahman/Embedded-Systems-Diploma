/*
Author: Abdelrahman Kamal
Program: Calculate and Print the Transpose
of 3x3 Matrix
*/

#include <stdio.h>
int main(void)
{
    float matrix [3][3], transpose [3][3];
    int row = 0, col = 0;

    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
            {
                printf("Enter the item [%d][%d]: ", row, col);
                scanf("%f", &matrix[row][col]);
            }
    }

    // display the matrix
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
            {
                printf("%.2f ", matrix[row][col]);
            }
            puts("");
    }

    // calculate the transpose

    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
            {
                transpose [row] [col] = matrix [col] [row];
            }

    }
    printf("-----------Seperator---------\n");

     // display the transpose
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
            {
                printf("%.2f ", transpose [row][col]);
            }
            puts("");
    }

}

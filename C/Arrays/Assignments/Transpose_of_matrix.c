/*
Author: Abdelrahman Kamal
Program: Find a transpose of a matrix
*/

#include <stdio.h>
void main(void)
{
    int row_matrix = 0 , col_matrix = 0, row_trans = 0, col_trans = 0;
    int i = 0, j = 0; // control loops

    printf("Enter rows and columns of a matrix: ");
    scanf("%d %d", &row_matrix, &col_matrix);

    row_trans = col_matrix;
    col_trans = row_matrix;

    float matrix [row_matrix][col_matrix], transpose [col_trans][row_trans];
    // enter the value of elements related to matrix
    printf("Enter elements of matrix\n");

    for (i = 0; i < row_matrix; i++)
    {
        for (j = 0; j < col_matrix; j++)
        {
            printf("Enter element a %d %d: ", i + 1, j + 1);
            scanf("%f", &matrix[i][j]);
        }
    }

    // display the matrix
    printf("Entered matrix\n");
    for (i = 0; i < row_matrix; i++)
    {
        for (j = 0; j < col_matrix; j++)
        {
            printf("%.2f ", matrix [i][j]);
        }

        puts(""); // new line added after every row
    }

    // calculate the transpose
    for (i = 0; i < row_matrix; i++)
    {
        for (j = 0; j < col_matrix; j++)
        {
            transpose [j][i] = matrix [i][j];
        }
    }

    // display the transpose
    printf("Entered matrix\n");
    for (i = 0; i < row_trans; i++)
    {
        for (j = 0; j < col_trans; j++)
        {
            printf("%.2f ", transpose[i][j]);
        }

        puts(""); // new line added after every row
    }
}

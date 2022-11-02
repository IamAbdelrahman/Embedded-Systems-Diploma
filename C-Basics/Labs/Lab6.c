/*
Author: Abdelrahman Kamal
Lab: Printing a pattern */

#include <stdio.h>
int main(void)
{
    int i = 0, j = 0, column = 10, row = 10, n = 0;

    for (i; i < row; i++)
    {
        for (j = n; j < column; j++)
        {
            printf("%d ", j);
        }

        puts("");
        n++;
    }
}

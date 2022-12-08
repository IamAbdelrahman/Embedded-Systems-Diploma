/*
Author: Abdelrahman Kamal
Program: Print a pattern of numbers
*/

#include <stdio.h>

void pattern (int);
void main(void)
{
    int row;
    printf("Enter no rows: ");
    scanf("%d", &row);
    pattern (row);
}

void pattern (int r)
{
    int i = 0, j = 0, a = 0;
    for (i = 0; i <= r; i++)
    {
        for (j = a; j <= r; j++)
        {
            printf("%d ", j);
        }
        a++;
        puts("");
    }
}

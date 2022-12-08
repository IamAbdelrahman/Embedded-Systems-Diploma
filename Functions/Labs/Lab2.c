/*
Author: Abdelrahman Kamal
Program: Calculate the min value of
any given array
*/

#include <stdio.h>

int calcMin (int [], int);

void main(void)
{
    int array [10], i = 0;

    // input array values
    for (i = 0; i < 10; i++)
    {
        printf("Value [%d] is : ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("The min value of the array is %d\n", calcMin(array, 10));

}

int calcMin(int a[], int size)
{
    int j = 0;
    char min = 'm';

    for (j = 0; j < size; j++)
    {
        if (min == 'm')
        {
           min = (int) min;
           min = a[j];
        }

        else if (min > a[j])
        {
            min = a[j];
        }

        else
            continue;
    }

    return min;
}

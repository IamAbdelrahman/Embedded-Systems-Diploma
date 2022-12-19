/*
    Author: Abdelrahman Kamal
    Program: Write a C function to return unique number in array
    with one loop
*/

#include <stdio.h>
int uniqueNumber (int [], int);

void main(void)
{
    int array_1 [7] = {4, 2, 5, 2, 5, 7, 4};
    int array_2 [3] = {4, 2, 4};

    printf("unique number in array_1 is %d\n", uniqueNumber(array_1, 7));
    printf("unique number in array_2 is %d\n", uniqueNumber(array_2, 3));

}

int uniqueNumber (int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (i == j)
                continue;

            if (a[i] == a[j])
                break;

            if (a[i] != a[j] && j == size - 1)
                return a[i];
        }
    }
}

/*
    Author: Abdelrahman Kamal
    Program: Write a C function to take an array and revers its elements
*/

#include <stdio.h>
void reverse (int []);

void main(void)
{
    int arr[5] = {1, 2, 3, 4, 5}, i = 0;

    // display the reversed array
    reverse (arr);
    for (i; i < 5; i++)
        printf("%d ", arr[i]);
}

void reverse (int a[])
{
    int left = 0, right = 4; // size - 1
    void swap (int*, int*);

    for (int j = 0; j < 5; j++)
    {
        if (left < right)
            swap(&a[left++], &a[right--]);

        else
            break;
    }
}

void swap (int* x, int* y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

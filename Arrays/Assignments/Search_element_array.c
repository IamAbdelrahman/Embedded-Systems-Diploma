/*
Author: Abdelrahman Kamal
Program: Search an element in an array
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

int linearSearch(int a[], int, int);
void main(void)
{
    int x [SIZE], i = 0, size = 0, element = 0;
    int out_linearSearch;

    printf("Enter no elements:");
    scanf("%d", &size);

    for (i = 0; i < size; ++i)
    {
        scanf("%d", &x[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &element);

    out_linearSearch = linearSearch(x, size, element);

    if (out_linearSearch)
        printf("Number is found at the location %d\n", out_linearSearch + 1);

    else
        printf("Sorry we didn't find your number\n");



}

int linearSearch(int a[], int numbers, int key )
{
    int found = 0, pos = 1; // for position

   for (int j = 0; j < numbers; ++j)
   {
        if ( a[j] == key)
        {
            found = 1;
            pos = j;
            break;

        }
   }

    if (found)
        return pos;

    else
        return 0;

}

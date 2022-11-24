/*
Author: Abdelrahman Kamal
Program: Search for a number that the previous
and the next values satisfy are less than it
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int linearSearch(int [], int); // linear search algorithm function

void main(void)
{
    int x [1000], i = 0, count = 0;
    srand(time(NULL)); // to change the random numbers every one second.

    // fill the array with elements from 1:1000
    for (i = 0; i < 1000; ++i)
        x[i] = 1 + (rand() % 1000);

    count = linearSearch(x, 1000);

    printf("Number of elements that meet the condition is %d\n", count);
}

int linearSearch (int a [], int size)
{
    int c = 0;

/* To meet the condition, the 1st element and the last element
of the array shouldn't be included, because there's no previous to the first and
there's no next to the last
*/
    for (int j = 1; j < size - 1; ++j)
    {
        if ( a [j] > a [j - 1] && a [j] > a [j + 1])
            c ++;
    }

    return c;
}

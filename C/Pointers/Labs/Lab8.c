/*
    Author: Abdelrahman Kamal
    Program: Passing Arrays and Pointers to Functions
*/

#include <stdio.h>
void Bubble_Sort (int value [] /* == int *value */, int size)
{
    int i = 0, j = 0;
    for (i = 0; i < size - 1; i++)
    {
        for (j = i; j < size; j++)
        {
            if (value[i] > value [j])
            {
                int temp = value[i];
                value[i] = value[j];
                value[j] = temp;
            }
        }
    }
}
int main (void)
{   
    int i = 0;
    int numbers [5] = {88, 77, 66, 1, 55};
    for (i = 0; i < 5; i++)
        printf("%d ", numbers[i]);

    puts("----");
    Bubble_Sort (numbers, 5);

    for (i = 0; i < 5; i++)
        printf("%d ", numbers[i]);

    return 0;
}
/*
    Author: Abdelrahman Kamal
    Program: Write a program in C to print the elements of an array in reverse
order.
*/
#include <stdio.h>
#define SIZE    15
int main(void)
{   
    int i = 0, count = 0;
    int testData[SIZE];
    printf("%s", "Input the number of elements to store in the array (max 15):");
    scanf("%d", &count);
    printf("Input %d numbers of elements in the array :\n", count);
    int *ptestData = testData;

    for (i = 0; i < count; i++)
    {
        printf("element - %d: ", i + 1);
        scanf("%d", (ptestData + i));
    }
    printf("\nThe elements of array in reverse order are :\n\n");
    for (i = count - 1; i >= 0; i--)
    {
        printf("element - %d: %d\n",i + 1, *(ptestData + i));
    }
}
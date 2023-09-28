/*
Author: Abdelrahman Kamal
Program: Insert an element in array
*/

#include <stdio.h>
#define SIZE 100
void main(void)
{
    int array [SIZE] = {0}, i = 0;
    int n = 0; // number of elements
    int element = 0, index = 0, size = 0;

    printf("Enter no elements: ");
    scanf("%d", &n);

    size = n;
	
    // Enter the elements of the array
    for (i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Enter the element to be inserted: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &element);

    printf("Enter the location: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &index);
	
    /* 
    Swap between elements, but starting from the last one
    till we reach the location that the user wants to use
    */
    
    for (i = index - 1; i < size ; i++)
    {
        array[n] = array [n - 1];
        n--;
    }
	
    // Assign the element into the empty location we made
    array[index - 1] = element;
    size += 1;

    for (i = 0; i < size ; i++)
    {
        printf("%d ", array[i]);
    }

}

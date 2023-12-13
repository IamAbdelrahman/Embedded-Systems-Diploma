/*
    Author: Abdelrahman Kamal
    Program: It is required to calculate the summation weight of 5
boxes. The user should enter the boxes
*/
#include <stdio.h>
int main(void)
{   
    int box[5];
    int sum = 0;
    int *ptr = box;
    int count = sizeof (box) / sizeof(int);
    for (int i = 0; i < count; i++)
        scanf("%d", ptr + i); // == x + i

    for (int i = 0; i < count; i++)
        sum += *(ptr + i);

    printf("The average is %f\n", sum / 5.0);
    return 0;
}
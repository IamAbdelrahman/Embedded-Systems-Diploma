/*
Author: Abdelrahman Kamal
Program: Find the string length
without using strlen() function
*/

#include <stdio.h>
#define SIZE 100

void main(void)
{
    char str [SIZE];
    int i = 0, length = 0;

    printf("Enter a string: ");
    scanf("%s", &str);

    for (i = 0; i < SIZE; ++i)
    {
        if (str[i] != '\0')
            length++;
        else
            break;
    }

    printf("Length of string is %d\n", length);
}

/*
    Author: Abdelrahman Kamal
    Program: Write a program in C to print a string in reverse using a pointer
*/
#include <stdio.h>
#include <string.h>
#define SIZE    100
int main(void)
{   
    int size = 0;
    char testData [SIZE] ;
    printf("Input a string: ");
    scanf("%s", testData);
    size = strlen(testData);
    char* ptr = testData;

    for (int i = size; i >= 0; i--)
    {   
        printf("%c", *(ptr + i));
    }
    puts("\n");

    return 0;
}
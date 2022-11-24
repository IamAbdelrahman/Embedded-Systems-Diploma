/*
Author: Abdelrahman Kamal
Program: Find the frequency of a character
in a string
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

void main(void)
{
    char str [SIZE];
    char ch;
    int count = 0, i = 0;
    printf("Enter a string: ");
    gets(str);
    //gets(); // to absorb the last \n comes from the gets.

    printf("Enter a character to find frequency: ");
    scanf("%c", &ch);

    for (i = 0; i < strlen(str); ++i)
    {
        if ((int) ch == (int) str[i])
            count++;
    }

    printf("Frequency of %c : %d\n", ch, count);


}

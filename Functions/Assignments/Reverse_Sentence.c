/*
    Author: Abdelrahman Kamal
    Program: Write a program to reverse
    a sentence using recursion
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

void reverse_sentence (char);
char sentence [SIZE]; // global array
int i = 1; // index

void main(void)
{
   printf("Enter a sentence: ");
   gets(sentence);

   reverse_sentence(sentence[0]);
}

void reverse_sentence(char c)
{
    if (c == '\0')
        return;

    else
    {
        reverse_sentence(sentence[i++]);
        printf("%c", c);
    }
}

/*
    Author: Abdelrahman Kamal
    Program: Write a C function to reverse words in string
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100
void reverseWords (char []);

void main(void)
{
    char words [SIZE];
    fgets (words, SIZE, stdin);
    reverseWords(words);
}

void reverseWords (char w[])
{
    size_t size = strlen(w);
    char w2 [SIZE];
    char w1 [SIZE];
    int s ; // space-index

    for (int i = 0; i < size - 1; i++)
    {
        if (w [i] == ' ')
        {
            s = i;
            break;
        }
        else
            w1 [i] = w [i]; // store the 1st word
    }


    for (int i = s + 1; i < size - 1; i++)
        w2 [i - (s + 1)] = w[i]; // store the 2nd word

    strcat(w2," "); // add a space to the 2nd word

    printf("%s", strcat(w2, w1));
}



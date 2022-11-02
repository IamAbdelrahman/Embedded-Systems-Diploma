/*
Author: Abdelrahman Kamal
Check Alphabet or not */

#include <stdio.h>
int main (void)
{
    char c;
    int ascii;

    printf("Enter a character: ");
    scanf("%c", &c);

    ascii = (int) c;

    if (ascii >= 65 && ascii <= 90 || ascii >= 97 && ascii <= 122)
        printf("%c is an alphabet\n", c);

    else
        printf("%c is not an alphabet\n", c);

    return 0;
}

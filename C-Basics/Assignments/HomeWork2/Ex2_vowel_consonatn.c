/*
Author: Abdelrahman Kamal
Check vowle or consonant */

#include <stdio.h>
int main(void)
{
    char c;
    printf("Enter an alaphabet: ");
    scanf("%c", &c);

    switch (c)
        {
            case 'a':
            printf("%c is a vowel\n", c);
            break;

            case 'e':
            printf("%c is a vowel\n", c);
            break;

            case 'i':
            printf("%c is a vowel\n", c);
            break;

            case 'o':
            printf("%c is a vowel\n", c);
            break;

            case 'u':
            printf("%c is a vowel\n", c);
            break;

            default:
            printf("%c is a consonant\n", c);
        }

}

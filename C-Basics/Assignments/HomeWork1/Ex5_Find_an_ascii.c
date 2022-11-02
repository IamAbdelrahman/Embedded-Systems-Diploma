/*
Author: Abdelrahman Kamal
Find an ascii for a character */

#include <stdio.h>
int main(void)
{
    char c;
    printf("Enter a character: ");
    scanf("%c", &c);

    printf("ASCII value of %c = %d\n", c, c);
    return 0;
}

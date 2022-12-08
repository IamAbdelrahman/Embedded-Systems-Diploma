/*
Author: Abdelrahman Kamal
Program: Find a name in a set
of names
*/

#include <stdio.h>
#include <string.h>

int findName (char[][14], char [], int row_N);

void main(void)
{
    char names [5][14] = {"Alaa", "Ali", "Ahmed", "Amgad", "Amr"};
    char name [14];
    int ret;

    printf("Enter the name you want to search for: ");
    scanf("%s", name);

    ret = findName(names, name, 5);

    if ( ret == -1)
        printf("Sorry! Your name doesn't exist\n");

    else
        printf("Your name is exist at position %d\n", ret + 1);
}

int findName (char N [][14], char n [], int row_N)
{
    int i = 0;
    for (i = 0; i < row_N; i++)
    {
        if (strcmp(n, N[i]) == 0)
            return i;

            else
                continue;

    }
    return -1;
}

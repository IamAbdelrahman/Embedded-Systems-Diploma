/*
Author: Abdelrahman Kamal
Program: Change String Case
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strlwr (char *);
char * strupr (char *);

int main(void)
{
    char str_1 [] = "Amr";
    char str_2 [] = "Hisham";

    strlwr(str_1);
    strupr(str_2);

    printf("%s\t%s\n", str_1, str_2);

    return 0;

}

char *strlwr(char *str)
{
    unsigned long size = strlen(str);
    int i = 0;

    for (i = 0; i < size ; i++)
    {
        if ( (int) str[i] >= 97 && (int) str[i] <= 122) // lower letter
            continue;

        else
           str[i] = (char) ( (int) str[i] + 32 );

    }

    return (str);
}

char *strupr (char *str)
{
    unsigned long size = strlen(str);
    int i = 0;

    for (i = 0; i < size ; i++)
    {
        if ( (int) str[i] >= 65 && (int) str[i] <= 90) // lower letter
            continue;

        else
           str[i] = (char) ( (int) str[i] - 32 );

    }

    return (str);
}

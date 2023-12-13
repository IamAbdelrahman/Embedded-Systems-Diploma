/*
    Author: Abdelrahman Kamal
    Program: Pointer to functions. Example 2
*/

#include <stdio.h>
#include <string.h>
void check (char *a, char *b, int (*) (const char *c1, const char *c2));

int main(void)
{   
    char s1 [100], s2[100];
    int (*P) (const char*, const char*);
    P = strcmp; // Store the address of strcmp built-in function to use it
    printf("Enter string 1: ");
    scanf("%s", s1);
    printf("Enter string 2: ");
    scanf("%s", s2);
    check (s1, s2, P);

    return 0; 
}

void check (char *a, char *b, int (*cmp)(const char *c1, const char *c2))
{
    printf("Testing Equality\n");

    if (!cmp(a, b))
        printf("Equality\n");

    else    
        printf("Not equal\n");    
}
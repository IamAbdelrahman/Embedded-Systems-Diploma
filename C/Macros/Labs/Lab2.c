/*
    Author: Abdelrahman Kamal
    Program: Define a macro
*/

#include <stdio.h>
#define AK 5
#define print printf

int main(void)
{
    print("Hello World\n");
    print("%d\n", AK);
    print("The End\n");

    return 0;
}

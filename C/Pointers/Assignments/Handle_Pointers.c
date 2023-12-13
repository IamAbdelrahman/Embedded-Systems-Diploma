/*
    Author: Abdelrahman Kamal
    Program: Write a program in C to demonstrate how to handle the pointers
    in the program.
*/
#include <stdio.h>
int main(void)
{   
    int m = 29;
    printf("Address of m : %x\n", &m);
    printf("Value of m : %d\n", m);
    int* ab = &m;

    puts("\n");

    printf("Now ab is assigned with the address of m.\n");
    printf("Address of pointer ab : %x\n", ab);
    printf("Content of pointer ab : %d\n", *ab);

    puts("\n");

    *ab = 34;
    printf("The value of m assigned to %d now\n", m);
    printf("Address of pointer ab : %x\n", ab);
    printf("Content of pointer ab : %d\n", *ab);
    puts("\n");

    *ab = 7;
    printf("The pointer variable ab is assigned with the %d value now.\n", m);
    printf("Address of m  : %x\n", &m);
    printf("Value of m : %d\n", m);
    return 0;
}
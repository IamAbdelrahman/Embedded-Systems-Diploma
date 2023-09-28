/*
    Author: Abdelrahman Kamal
    Program: Complex Pointers (Pointer to function)
*/

#include <stdio.h>
int add (int, int);
int diff (int, int);
int mul (int, int);
int div (int, int);

int main(void)
{   
    int num1, num2, op; 
    int (*aPF[4]) (int, int) = {add, diff, mul, div};
    printf("Enter the two numbers: ");
    scanf("%d%d", &num1, &num2);
    for (int i = 0; i < 4; i++)
    {
        printf("Result of this process is %d\n", aPF[i] (num1, num2));
    }


    return 0;
}

int add (int a, int b) { return (a + b) ;}
int diff (int a, int b) { return (a - b) ;}
int mul (int a, int b) { return (a * b) ;}
int div (int a, int b) { return (a / b) ;}
/*
    Author: Abdelrahman Kamal
    Program: Assignment (3) : Write a C-program
    to add two complex numbers using structures.
*/

#include <stdio.h>
struct complex {
    float real;
    float imaginary;
};
struct complex num1, num2, result;
void Add (struct complex, struct complex);

int main(void)
{   
    printf("For 1st complex number\n");
    printf("Enter real and imaginary numbers respectively: ");
    scanf("%f %f", &num1.real, &num1.imaginary);

    printf("For 2nd complex number\n");
    printf("Enter real and imaginary numbers respectively: ");
    scanf("%f %f", &num2.real, &num2.imaginary);

    Add(num1, num2);
    return 0;
}

void Add (struct complex n1, struct complex n2)
{
    result.real = n1.real + n2.real;
    result.imaginary = n1.imaginary + n2.imaginary;
    printf("Sum = %.2f + i%.2f\n", result.real, result.imaginary);
}
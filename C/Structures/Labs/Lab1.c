/*
    Author: Abdelrahman Kamal
    Program: Write a program that adds two complex numbers
    using structs and functions
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

struct SComplex
{
    double m_r; // real part of the complex number.
    double m_i; // imaginary part of the complex number.
};

/*
Function Description: This function will read the values related to
the complex number.
Input: It takes only one parameter a string to be displayed in a message.
Return: It returns a struct SComplex but it will store the values related to the complex number.
*/
struct SComplex readComplex (char name[]);
// -------------------------------------------------- //

/*
Function Description: It will do the process of adding by add the real parts
in each complex number together and the same will happen to the imaginary parts
Input: It takes two parameters (two structs SComplex).
Return: It returns a new struct SComplex contains the new real part and the new imaginary part.
*/
struct SComplex addComplex (struct SComplex A, struct SComplex B);
// -------------------------------------------------- //

/*
Function Description: It displays the value of the complex number stored in the struct SComplex.
Input: It takes two parameters, a string to be displayed in a message and a result a struct SComplex
to display the value stored in it.
Return: Nothing.
*/
// -------------------------------------------------- //
void printComplex (char name[], struct SComplex C);

int main(void)
{
    struct SComplex A, B, C;

    A = readComplex("The real and imaginary parts of the 1st number");
    B = readComplex("The real and imaginary parts of the 2nd number");
    C = addComplex(A, B);
    printComplex("The result is", C);

    return 0;
}

struct SComplex readComplex(char name[])
{
    struct SComplex A;
    printf("Please enter %s in a sequence way (real then imaginary): ", name);
    scanf("%lf %lf", &A.m_i, &A.m_r);

    return A;
}

struct SComplex addComplex(struct SComplex A, struct SComplex B)
{
    struct SComplex C;
    C.m_i = A.m_i + B.m_i;
    C.m_r = A.m_r + B.m_r;

    return C;
}

void printComplex(char name[], struct SComplex C)
{
    printf("%s :\n", name);
    printf("%.2lf + i%.2lf\n", C.m_i, C.m_r);
}

/*
    Author: Abdelrahman Kamal
    Program: Write a C function to count number of ones in binary number
*/

#include <stdio.h>
#define SIZE 8 // 1 Byte
void convertToBinary (int b[], int n);

void main(void)
{
    int number, binaryConverted [SIZE] = {0}, testcases = 2, k = 0, j = 0, count;

    for (k = 0; k < testcases; k++)
    {
    count = 0;
    printf("Enter your number: ");
    scanf("%d", &number);

    convertToBinary(binaryConverted, number);

    for (j = 0; j < SIZE; j++)
    {
        if ( 1 == binaryConverted[j])
            count++;
    }

    printf("Number of ones in the number (%d) is %d\n", number, count);

    }
}

void convertToBinary (int b[], int n)
{
    // Start from the last element to be compatible with the MSB & LSB.
    int i = SIZE;

    while (i != 0)
    {
        b[--i] = n % 2;
        n /= 2;

        if (n == 0) {

            b[--i] = 0;
            break;
        }
    }
}

/*
    Author: Abdelrahman Kamal
    Program: Write a C function to count the max number of ones
    between two zeros
*/

#include <stdio.h>
#define SIZE 8
void setBits(int, int[]);
int maxOnes (int []);

void main(void)
{
    // Define an array to assign the bits in
    int binaryConverted [SIZE];

    // Calling the functions with the two test cases
    setBits(14, binaryConverted);
    printf("%d\n", maxOnes(binaryConverted));

    setBits(110, binaryConverted);
    printf("%d\n", maxOnes(binaryConverted));

}

int maxOnes(int b[])
{
    // Define an array to store the indexes of zero in the main array
    int zerosIndex [SIZE], j = 0; // index
    // Define an array to store the max no.ones in each cycle
    int onesAppear [SIZE], k = 0;  // index
    int counts = 0; // Counts the ones

    for (int i = 0; i < SIZE; i++)
    {
        if (b[i] == 0)
            zerosIndex[j++] = i;
    }
    // Calculate the length of zeroIndex array
    int size = sizeof(zerosIndex) / sizeof(zerosIndex[0]);

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = zerosIndex[i]; j < zerosIndex[i + 1]; j++)
        {
            if (b[j] == 1)
                counts++;
        }
        // Store how many times one appears in each period
        onesAppear[k++] = counts;
        counts = 0;
    }

    int max = -1;
    // Find the max number in the maxones array
    for (int w = 0; w < SIZE; w++)
    {
        if (max < onesAppear[w])
            max = onesAppear[w];
    }

    return max;
}

void setBits (int n, int a[])
{
    // Convert the decimal number to the binary form
    for (int i = SIZE - 1; i >= 0; i--)
    {
        a[i] = n % 2;
        n /= 2;
    }
}

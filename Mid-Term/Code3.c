/*
    Author: Abdelrahman Kamal
    Program: Write a C function to revers digits in number
*/

#include <stdio.h>
#define SIZE 10

/*
    This function is created to count the number of the digits
    of the given number
*/
int noDigits (int);

/*
    This function will take the number and an array to assign
    the digits into this array
*/
void setDigits (int, int[]);

void main(void)
{
   int arr [SIZE] = {0};
   int total = 0, number, size, testcases = 2, i = 0;

    // Create a loop for testcases
   for (i; i < testcases; i++)
   {
        printf("Please Enter your number:") ;
        scanf("%d", &number);

        size = noDigits(number) ;
        setDigits (number, arr) ;

       for (int i = 0; i < size; i++)
       {
            total *= 10;
            total += arr[i];
       }

        // Display the number reversed
       printf("%d\n", total);

       total = 0; // reinitialize the total for the 2nd test case.
    }

}

void setDigits (int n, int a[])
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        a[i] = n % 10;
        n /= 10;
    }
}

int noDigits (int x)
{
    int count = 0;

    while (x != 0)
    {
        x /= 10;
        count++;
    }

    return count;
}

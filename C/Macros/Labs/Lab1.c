/*
    Author: Abdelrahman Kamal
    Program: Write a program to calculate the excution time
    of a compiled program
*/

#include <stdio.h>
#include <time.h>

int main(void)
{
    /* clock() this function is used to get the current system time.
    CLOCKS_PER_SEC: Number of clock ticks per second
    */
    clock_t t;
    t = clock();
    int num1, num2, sum;
    printf("Enter your number 1: \n");

    /*
    We hide the scanf not to let the user intefere with the total
    execution time of the program
    scanf("%d", &num1);
    */
    printf("Enter your number 2: \n");
    // scanf("%d", &num2);

    num1 = 1;
    num2 = 2;
    sum = num1 + num2;
    printf("Sum is %d\n", sum);

    // Final time - Initial time
    t = clock() - t;
    double taken_time = ((double) t) / CLOCKS_PER_SEC;
    printf("Time the program takes is %.5lf\n", taken_time); // Microseconds
}

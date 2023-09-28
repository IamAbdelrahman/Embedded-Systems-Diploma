/* Author: Abdelrahman Kamal
Program: Calculate the average using arrays
*/

#include <stdio.h>
void main(void)
{
    // number of elements of the array
    int n, i = 0;
    float avg = 0.0, sum = 0;

    printf("Enter the number of data: ");
    scanf("%d", &n);

    float data [n];
    // enter the value of elements
    for (i = 0; i < n; i++)
    {
        printf("Enter number: ");
        scanf("%f", &data[i]);
    }

    // calculate the sum of the elements
    for (i = 0; i < n; i++)
    {
        sum += data[i];
    }

    printf("Average = %.2f\n", sum / n);
}


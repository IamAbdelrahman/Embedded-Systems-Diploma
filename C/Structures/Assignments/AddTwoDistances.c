/*
    Author: Abdelrahman Kamal
    Program: Assignment (2) : Write a C-program
    to add two distances (in inch-feet) using structures
*/

#include <stdio.h>
struct distance {
    int feet;
    float inch;
};

int main (void)
{   
    struct distance d1;
    struct distance d2;

    printf("Enter information for the 1st distance: \n");
    printf("Enter feet: ");
    scanf("%d", &d1.feet);
    printf("Enter inch: ");
    scanf("%f", &d1.inch);

    printf("Enter information for the 2nd distance: \n");
    printf("Enter feet: ");
    scanf("%d", &d2.feet);
    printf("Enter inch: ");
    scanf("%f", &d2.inch);

    struct distance result;
    result.feet = d1.feet + d2.feet;
    result.inch = d1.inch + d2.inch;

    // Convert from inch to feet
    while (result.inch >= 12)
    {
        result.inch -= 12;
        result.feet++;
    }
    
    printf("Sum of distances = %d' - %.1f\n", result.feet, result.inch);
    return 0;
}


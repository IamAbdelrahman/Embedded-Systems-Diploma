/*
Author: Abdelrahman Kamal
Program: Store and Print 10 Students Degrees
*/

#include <stdio.h>
#define SIZE 10
int main(void)
{
    float students_degrees [SIZE];
    int i = 0;

    for (i = 0; i < SIZE; i++)
    {
        printf("Enter Student %d degree: ", i + 1);
        scanf("%f", &students_degrees[i]);
    }

    for (i = 0; i < SIZE; i++)
        printf("Student %d degree is: %f\n",i + 1, students_degrees[i] );
}

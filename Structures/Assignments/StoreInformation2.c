/*
    Author: Abdelrahman Kamal
    Program: Assignment (4) : Write a C-Program
    to store a student information using array of structure
*/

#include <stdio.h>
typedef struct data_member {
    char name [20];
    int roll;
    float marks;
} student;
void enter_info (student [], int);
void display_info (student [], int);

int main(void)
{   
    student data[10];
    printf("Enter information of students\n");
    enter_info(data, 10);
    printf("Display information of students\n");
    display_info(data, 10);

    return 0;
}

void enter_info (student d[], int size)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {   
        printf("Enter name: ");
        scanf("%s", d[i].name);
        printf("Enter marks: ");
        scanf("%f", &d[i].marks);
        printf("Enter roll: ");
        scanf("%d", &d[i].roll);
        printf("\n");
    }
}

void display_info (student D[], int Size)
{
    int j = 0;
    for (j = 0; j < Size; j++)
    {
        printf("Information for roll number: %d\n", D[j].roll);
        printf("mark: %.2f\n", D[j].marks);
        printf("name: %s\n", D[j].name);
        printf("\n");
    }
}
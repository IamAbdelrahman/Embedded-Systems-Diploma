/*
    Author: Abdelrahman Kamal
    Program: Assignment (1) : Write a C-Program
    to store a student information using structure
*/

#include <stdio.h>
struct data_member {
    char name [20];
    int roll;
    float marks;
};
void display (struct data_member);

int main(void)
{   
    struct data_member d;

    printf("Enter information of students: \n");
    printf("Enter name: ");
    scanf("%s", d.name);
    printf("Enter roll number: ");
    scanf("%d", &d.roll);
    printf("Enter marks: ");
    scanf("%f", &d.marks);

    display(d);
    return 0;
}

void display (struct data_member data)
{
    printf("\nDisplaying information\n");
    printf("name : %s\n", data.name);
    printf("roll : %d\n", data.roll);
    printf("marks : %.2f\n", data.marks);
}
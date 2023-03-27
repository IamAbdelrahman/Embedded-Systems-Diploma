/*
    Author: Abdelrahman Kamal
    Program: Pointer to stuctures - Lab
*/

#include <stdio.h>
struct SPerson {
    unsigned char name [18];
    int Id;
    int Age;
    float salary;
    double weight;
};
int main(void)
{
    struct SPerson manager = {"Hany Adel", 1, 40, 50000, 160.5};
    struct SPerson *Ps;
    Ps = &manager;

    struct SPerson employee [] = {
        {"Abdo Kamal", 2, 30, 3000, 170.5},
        {"Ibrahim Adel", 3, 35, 4000, 160.5},
        {"Ahmed Hossam", 4, 36, 4000, 180.5} };

    printf("Manager: %s - Id: %d - Age: %d - Salary: %f - Weight: %lf\n",
    Ps->name, Ps->Id, Ps->Age, Ps->salary, Ps->weight);
    int i, total_size;
    total_size = sizeof(employee) / sizeof(employee[0]);
    for (i = 0; i < total_size; i++)
    {
        printf("employee number %d data: Name: %s - Id: %d - Age: %d - Salary : %f - Weight: %lf\n", 
        i + 1, employee[i].name, employee[i].Id, employee[i].Age, employee[i].salary, employee[i].weight);
    }
    
    return 0;
}
/*
    Author: Abdelrahman Kamal
    Program: Write a program in C to show a pointer to an array which contents
are pointer to structure.
*/
#include <stdio.h>
#include <string.h>
#define SIZE    100
typedef struct {
    char employeeName [SIZE];
    int employeeID;
} testData;
int main(void)
{   
    testData t1;
    t1.employeeID = 1002;
    strcpy(t1.employeeName, "Alex");
    testData t2;
    t2.employeeID = 1003;
    strcpy(t2.employeeName, "Mona");

    testData *Ps [2];   // Array of 2 pointers to testData structure
    Ps[0] = &t1;    // Assign the address of the structure1 in the 1st element of the array(Pointer1)
    testData* *PPs1 = &Ps[0];   // Assign the address of (Pointer1) into another pointer (PPs1)
    printf("Employee Name : %s\n",(**PPs1).employeeName);
    printf("Employee ID : %d\n", (**PPs1).employeeID);

    Ps[1] = &t2;
    testData* *PPs2 = &Ps[1];
    printf("Employee Name : %s\n",(**PPs2).employeeName);
    printf("Employee ID : %d\n", (**PPs2).employeeID);
    
    return 0;
}
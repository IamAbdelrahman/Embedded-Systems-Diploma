/*
    Author: Abdelrahman Kamal
    Program: Unary increment operation for the pointers
*/
#include <stdio.h>
int main(void)
{   
    char *px = 0x0;
    int *py = 0x0;
    long long *pz = 0x0;
    printf("Address' held is %x, %x, %x\n",px, py, pz);

    /* All the pointers point to the same location (are holding the same address)
    That means the pointer arithmetic is applied in this case
    */

   px++; // px = px + 1 (size of the pointer's data type)
   py++;
   pz++;
   printf("Address' held is %x, %x, %x\n",px, py, pz);

    return 0;
}
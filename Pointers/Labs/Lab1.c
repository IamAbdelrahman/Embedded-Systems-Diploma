/*
    Author: Abdelrahman Kamal
    Program: Pointer Casting
*/

#include <stdio.h>
int main(void)
{   
    int rand_address = 0xFFAABB; // definition for an int data type
    char *ptr = (char*) 0xFFAABB; // a pointer to character 
    /* This pointer's size is 8 bytes (address bus dependent) but when we use it
    for reading/writing on the variable whose address is 0x00FFAABB, it will just
    make use of 1-byte of that process
    */
   printf("Address of rand_address is : %lx\n", &rand_address);
   printf("The value of rand_address is : %d\n", rand_address);
   printf("Address of the ptr itself that's in the stack is %lx\n", &ptr);
   printf("Address's held by the ptr is %lx\n", ptr);
   return 0;
}
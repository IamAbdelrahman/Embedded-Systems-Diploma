/*
    Author: Abdelrahman Kamal
    Program: Pointers to structures
*/
#include <stdio.h>
struct SDataset {
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
};

struct SDataset Dataset;

/*
Description: This function is used to display the values of the structure members
next to each address of each value in a series way.

Input: It takes two arguments 'Pointer to struct' (Ps) and 'integer variable 'size'
Ps is explicitly converted to pointer to character to move in the memory byte by byte
to clarify the padding if exists, then we make a loop depends on the size of the struct
to print the address and the value of each member in the struct

Output: It returns void.
*/
void dump_memory (struct SDataset* Ps, int size)
{   
    char* Ptr = (char*)Ps;
    int i = 0;
    for (i = 0; i < size; i++)
        printf("%p \t %x\n", Ptr,(unsigned char)*(Ptr++) );
    
}
int main(void)
{  
    Dataset.data1 = 0xFF;
    Dataset.data2 = 0xAABBCCDD;
    Dataset.data3 = 0xAC;
    Dataset.data4 = 0xDDFF;
    int total_size = sizeof(Dataset);
    printf("The size of this struct is %d\n", total_size);

    char *ptr = &Dataset;
    printf("ptr + 8(bytes) = %x\n", (unsigned char) *(ptr + 8));
    struct SDataset *Pstruct = &Dataset;
    printf("pstruct + 8(bytes) = %x\n",Pstruct->data3 );

    dump_memory (Pstruct, total_size);
    return 0;
}
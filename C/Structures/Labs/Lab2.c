/*
    Author: Abdelrahman Kamal
    Program: An example on alignment data using struct.
*/

#include <stdio.h>

struct SData {
    unsigned char data1;
    unsigned int data2;
    unsigned char data3;
    unsigned short data4;
    } ;

struct SData gdata;
void dump_memory (struct SData* Ptr, int size);
void main()
{
    gdata.data1 = 0x55;
    gdata.data2 = 0xFFFFFFFF;
    gdata.data3 = 0x55;
    gdata.data4 = 0xA5A5;

    int total_size = sizeof (gdata);
    printf("Size of non-packing struct is %lu\n", sizeof(gdata));
    dump_memory (&gdata, total_size);
}

void dump_memory (struct SData* Ptr, int size)
{
	char *ptr = (char*)Ptr;
    int i = 0;
    for (i = 0; i < size; i++)
    {
        printf("%p \t %X\n", ptr, (unsigned char)*ptr);
        ptr++;
    }
}


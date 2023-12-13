/*
    Author: Abdelrahman Kamal
    Program: Write a program in C to print all the alphabets using a pointer.

The Alphabets are :
Expected Output :
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
*/
#include <stdio.h>
int main(void)
{   
    int i = 0, count = 0;
    char alphabet [27] = {'A', 'B', 'C', 'D', 'E',
    'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q',
    'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char* palphapet = alphabet;
    count = sizeof(alphabet) / sizeof(char);
    for (i = 0; i < count; i++)
    {
        printf("%c ", *(palphapet + i));
    }
    puts("\n");
    return 0;
}

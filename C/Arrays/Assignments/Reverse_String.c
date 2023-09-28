/*
Author: Abdelrahman Kamal
Program: Reverse a string without using
built-in functions
*/

#include <stdio.h>
#include <string.h> // To use only strlen() function
#define SIZE 100
void main(void)
{
   char str [SIZE];
   char reverse_str [SIZE];
   int i = 0;
   printf("Enter the string: ");
   scanf("%s", &str);

   size_t size = strlen(str);
   int index = size;

   for (i = 0; i < size; ++i)
   {
        reverse_str [i] = str[index - 1];
        index--;
   }

   printf("Reverse string is %s\n", reverse_str);


}

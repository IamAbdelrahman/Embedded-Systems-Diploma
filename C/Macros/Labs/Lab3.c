/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs
*/

#include <stdio.h>
#define height 100
#define number 3.14
#define letter 'A'
#define sequence_letter "ABC"
#define backslash_character '?'

int main(void)
{
	printf("Value of height is %d\n", height);
	printf("Value of letter is %c\n", letter);
	printf("Value of number is %.2f\n", number);
	printf("Value of sequence_letter is %s\n", sequence_letter);
	printf("Value of backslash_character is %c\n", backslash_character);
    
	return 0;
}
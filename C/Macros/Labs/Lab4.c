/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs
*/

#include <stdio.h>
#define PR(value,Maxvalue) (value*(Maxvalue/100.0))
int main(void)
{   
    printf("Your degree in Math is %f %%\n", PR(75,90));
    printf("Your degree in English is %f %%\n", PR(50,60));
    printf("Your degree in Science is %f %%\n", PR(90,150));

    return 0;
} 
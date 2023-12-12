/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs : Predefined Macros
*/

#include <stdio.h>
int main(void)
{   
    printf("__STDC__ = %d\n", __STDC__);
    printf("__STDC_VERSION = %ld\n", __STDC_VERSION__);
    printf("__FILE__ is %s\n", __FILE__);
    printf("__DATE__ is %s\n", __DATE__);
    printf("__LINE__ = %d\n", __LINE__);
    printf("__TIME__ is %s\n", __TIME__);
    printf("__func__ is %s\n", __func__); 
    
    return 0;
} 
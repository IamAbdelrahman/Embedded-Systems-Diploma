/*
    Author: Abdelrahman Kamal
    Program: Macros-Labs : Write a macro to be used as a function factory
*/

#include <stdio.h>
#define FUNCTION(name, a) int fun_##name(int x) { return (x * (a)) ;} 
FUNCTION(quadrable, 4)
FUNCTION(double, 2)
#define OUTPUT(a) printf(#a)

int main(void)
{   
    printf("Result of quadrable function is %d\n", fun_quadrable(3));
    printf("Result of double function is %d\n", fun_double(3));
    #undef FUNCTION
    #define FUNCTION 6
    OUTPUT(AK\n);
    printf("Result of Function is %d\n", FUNCTION);
   
    return 0;
}

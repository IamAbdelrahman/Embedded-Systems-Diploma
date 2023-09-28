/*
    Author: Abdelrahman Kamal
    Program: Calculate a power of
    a number using recursion
*/

#include <stdio.h>

int calculate_power (int , int);
void main(void)
{
    int base , power ;

    printf("Enter base number: ");
    scanf("%d", &base);

    printf("Enter power number positive: ");
    scanf("%d", &power);

    printf("%d ^ %d = %d\n", base, power, calculate_power(base, power));

}

int calculate_power (int b, int p)
{
    if (p == 0)
        return 1;

    else if (p == 1)
        return b;

    else
    {
        return b * calculate_power(b, p - 1);
    }
}

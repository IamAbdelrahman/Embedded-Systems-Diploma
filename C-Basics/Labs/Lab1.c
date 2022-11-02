/* Calculate circle area
Author : Abdelrahman Kamal */

#include <stdio.h>
#define PI 3.14


int main(void)
{
    float radius = 0.0;

    printf("Choose a for printing area of the circle");
    printf(" ,or choose c for printing circumference\n");

    printf("Enter your radius:");
    scanf("%f", &radius);
    getc(stdin);

    switch (getc(stdin)){

case 'a':
case 'A':

    printf("area is %f\n", PI * radius * radius);
    break;

case 'c':
case 'C':

    printf("circumference is %f\n", 2 * PI * radius);
    break;

default:

    printf("Wrong Choice\n");
    break;

    return 0;
}
}


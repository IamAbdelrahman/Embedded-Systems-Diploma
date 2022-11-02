/*
Author: Abdelrahman Kamal
A simple calculator */

#include <stdio.h>
int main(void)
{
    char operator;
    float operand1, operand2;

    printf("Enter an operator either '+', '-' , '*' or '/': ");
    scanf("%c", &operator);

    printf("Enter two operands: ");
    scanf("%f %f", &operand1, &operand2);

    switch (operator)
    {
        case '+':
        printf("%f + %f = %.2f\n", operand1, operand2, operand1 + operand2);
        break;

        case '-':
        printf("%f - %f = %.2f\n", operand1, operand2, operand1 - operand2);
        break;

        case '*':
        printf("%f * %f = %.2f\n", operand1, operand2, operand1 * operand2);
        break;

        case '/':
        printf("%f / %f = %.2f\n", operand1, operand2, operand1 / operand2);
        break;

        default:
        printf("Error input\n");
    }

}

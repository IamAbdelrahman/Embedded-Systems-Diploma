/*
Author: Abdelrahman Kamal
Check even or odd */

#include <stdio.h>
int main(void)
{
    int num, i = 0;

    for (i; i < 2; i++)
    {
        printf("Output %d\n", i + 1);
        printf("Enter an integer you want to check: ");
        scanf("%d", &num);

        if (num % 2 == 0)
            printf("%d is even\n", num);

        else
            printf("%d is odd\n", num);

        puts("");

    }

    return 0;
}

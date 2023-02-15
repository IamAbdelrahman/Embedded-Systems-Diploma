/*
    Author: Abdelrahman Kamal
    Program: Personal Data Using Enum
*/

#include <stdio.h>

enum Gender { Female, Male};

struct SPerson{
    char m_Name [100];
    enum Gender m_Gender;
    };

int main(void)
{
    struct SPerson persons [] = { {"Ahmed Mansor", Male} , {"Mona Shrief", Female} };
    for (int i = 0; i < (sizeof(persons) / sizeof(struct SPerson)); i++)
    {
        printf("%s - %s\n", persons[i].m_Name, (persons[i].m_Gender == Male ? "Male": "Female") );
    }

    return 0;
}

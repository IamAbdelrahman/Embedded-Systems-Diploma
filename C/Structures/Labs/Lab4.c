/*
    Author: Abdelrahman Kamal
    Program: Using unions to add numbers.
*/
enum NUMtype {INT, FLOAT, DOUBLE};

union UNUMvalue
{
    int u_intvalue;
    float u_floatvalue;
    double u_doublevalue;
};

/*
Description: This function takes 3 parameters, it takes two unions
and an object instantiated from the class enumeration. By using the switch-case
statement, we check the enum value whether it's int, float or double to decide the type
of the adding process if it will be between two ints or two floats or two doubles. Then we
store the result in a union we define it in the function and return it

Input: 2 unions that are called value1 and value2, besides 1 enum object is called type.

Return: It returns a union data type
*/
union UNUMvalue Add (union UNUMvalue value1, union UNUMvalue value2, enum NUMtype type);

#include <stdio.h>
int main(void)
{
    union UNUMvalue v1, v2, R;

    v1.u_intvalue = 100;
    v2.u_intvalue = 200;
    R = Add(v1, v2, INT);
    printf("%d + %d = %d\n", v1.u_intvalue, v2.u_intvalue, R.u_intvalue);

    v1.u_floatvalue = 100.5;
    v2.u_floatvalue = 200.75;
    R = Add(v1, v2, FLOAT);
    printf("%f + %f = %f\n", v1.u_floatvalue, v2.u_floatvalue, R.u_floatvalue);

    v1.u_doublevalue = 98234.323;
    v2.u_doublevalue = 98234.399;
    R = Add(v1, v2, DOUBLE);
    printf("%lf + %lf = %lf\n", v1.u_doublevalue, v2.u_doublevalue, R.u_doublevalue);

    return 0;
}

union UNUMvalue Add (union UNUMvalue value1, union UNUMvalue value2, enum NUMtype type)
{
    union UNUMvalue result;

    switch (type)
        {

        case INT:
            result.u_intvalue = value1.u_intvalue + value2.u_intvalue;
            break;

        case FLOAT:
            result.u_floatvalue = value1.u_floatvalue + value2.u_floatvalue;
            break;

        case DOUBLE:
            result.u_doublevalue = value1.u_doublevalue + value2.u_doublevalue;
            break;

        default:
            break;

        }

        return result;
}

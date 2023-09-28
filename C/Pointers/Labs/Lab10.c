/*
    Author: Abdelrahman Kamal
    Program: Pointer Labs : Universal Compare Using Void Pointers
*/

#include <stdio.h>
enum Data {
    INT, DOUBLE
};
int compare (void *Ptr1, void *Ptr2, enum Data d)
{   
    int r;
    switch (d)
    {
        case INT:
            if (*(int*)Ptr1 == *(int*)Ptr2)
                r = 0;
            else    r = -1;
            break;
        
        case DOUBLE:
            if (*(double*)Ptr1 == *(double*)Ptr2)
                r = 0;
            else    r = -1;
            break;
        default:
            break;
    }

    return r;
}
int main(void)
{   
    int x1 = 3, x2 = 4, x3 = 3;
    double y1 = 20.0, y2 = 20.0, y3 = 1.5;
    printf("Compare x1 and x2 (-1 for non-equality): %d\n", compare(&x1, &x2, INT));
    printf("Compare x1 and x3 (-1 for non-equality): %d\n", compare(&x1, &x3, INT));
    printf("Compare y1 and y2 (-1 for non-equality): %d\n", compare(&y1, &y2, DOUBLE));
    printf("Compare y1 and y3 (-1 for non-equality): %d\n", compare(&y1, &y3, DOUBLE));
    return 0;
}
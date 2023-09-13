#include "Stack.h"
STACKENTRY buffer1[MAX_STACK];
void Display (STACKENTRY );

int main(void) {
    Stack_t Uart_Lifo = {0};
    STACKENTRY item = 0;
    initializeStack(&Uart_Lifo, buffer1);

    STACKENTRY i = 0;
    for (i = 0; i < 4; i++) {
        if(Push(&Uart_Lifo, i) == STACK_NO_ERROR) {}
    }
    printf("Traverse Stack:-\n");
    TraverseStack(&Uart_Lifo, &Display);
    printf("Size of the stack is %u\n", StackSize(&Uart_Lifo));
    return 0;
}

/**
 * @brief  Displaying an element of the stack
 *  
 *  This function is used to print an element of the stack
 *  using the printf() function with a specifier that's known
 *  to only the user level who decides on the STACKENTRY.

 * @param  e: It takes an element of a data type of STACKENTRY.
 *
 * @return It returns nothing
 */
 void Display (STACKENTRY e) {
    printf("%u\n", e);
}

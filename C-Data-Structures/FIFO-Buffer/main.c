#include "Queue.h"
QUEUEENTRY buffer1[MAXQUEUE];
void Display (QUEUEENTRY);

int main(void) {
    Queue_t Uart_Lifo = {0};
    QUEUEENTRY item = 0;
    
    initializeQueue(&Uart_Lifo, &buffer1[0]);

    QUEUEENTRY i = 0;
    for (i = 0; i < 4; i++) {
        if(Enqueue(&Uart_Lifo, i) == QUEUE_NO_ERROR) {}
    }

    if (Dequeue(&Uart_Lifo, &item) == QUEUE_NO_ERROR) {}
    if(Enqueue(&Uart_Lifo, 5) == QUEUE_NO_ERROR) {}

    printf("Size of queue is %u\n", QueueSize(&Uart_Lifo));

    if (QueueFront(&Uart_Lifo, &item) == QUEUE_NO_ERROR) {
        printf("Front element is %u\n", item);
    }

    printf("Traverse Stack:-\n");
    TraverseQueue(&Uart_Lifo, Display);

    ClearQueue(&Uart_Lifo);

    printf("Traverse Stack:-\n");
    TraverseQueue(&Uart_Lifo, Display);
    return 0;
}

/**
 * @brief  Displaying an element of the stack
 *  
 *  This function is used to print an element of the stack
 *  using the printf() function with a specifier that's known
 *  to only the user level who decides on the QUEUEENTRY.

 * @param  e: It takes an element of a data type of QUEUEENTRY.
 *
 * @return It returns nothing
 */
 void Display (QUEUEENTRY e) {
    printf("%d\n", e);
}

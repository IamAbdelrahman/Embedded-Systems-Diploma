/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Data Structures 
 * Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Queue.c
 * @brief Implementaion of Queue Data Structure
 *
 * @author Abdelrahman Kamal
 * @date 12/9/2023
 *
 */
#include "Queue.h"
#define MAXQUEUE  10

/**
 * @brief  Initializating the queue.
 *  
 *  This function is used to initialize the queue through intializing the
 *  count with zero, the length with MAXQUEUE, and initializing the base, head, and tail
 *  pointers with the first element of the buffer, if the pointer 'Pf' points to NULL that means
 *  there's no creation happens to buffer whether the creation is statically or
 *  dynamically allocated.
 *  Pre-condition: The buffer exists.
 *  Post-condition: The queue exists and is initialized.

 * @param  Pq: It takes a pointer to queue.
 * @param  Pf: It takes a pointer to the buffer.
 *
 * @return It returns an enum state
 */ 
Queue_Status_t initializeQueue(Queue_t *Pq, QUEUEENTRY *Pf) {
    if (Pf == NULL) {
        return QUEUE_NULL;
    }
    else {
        Pq->base = Pf;
        Pq->head = Pf;
        Pq->tail = Pf;
        Pq->count = 0;
        Pq->length = MAXQUEUE;
    }
    return QUEUE_NO_ERROR;
}
/***********************************************************************************/

/**
 * @brief  Check if the queue is full or not
 *  
 *  This function is used to check if the queue is full or not through
 *  checking the equality between the count and the MAX_queue. After checking
 *  the validation of the queue.
 *  Pre-condition: The queue exists and is initialized.
 *  Post-condition: It returns the state of the queue full or not.

 * @param  Pq: It takes a pointer to queue.
 *
 * @return It returns an enum state
 */
Queue_Status_t QueueFull (Queue_t *Pq) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return QUEUE_NULL;
    }
    if (Pq->count == MAXQUEUE) {
        return QUEUE_FULL;
    }
    else {
        return QUEUE_NOT_FULL;
    }
}
/***********************************************************************************/
/**
 * @brief  Check if the queue is empty or not
 *  
 *  This function is used to check if the queue is empty
 *  or not, through checking if the count equals zero or not, after
 *  checking the validation of the queue.
 *  Pre-conditions: The queue exists and is initialized.
 *  Post-conditions: It returns the state of the queue 1 or 0;
 * @param  Pq: It takes a pointer to struct queue. 
 *
 * @return It returns an enum state.
 */
Queue_Status_t QueueEmpty (Queue_t *Pq) {
    if (!Pq->base || !Pq->head) {
        return QUEUE_NULL;
    }
    if (Pq->count == 0) {
        return QUEUE_EMPTY;
    }
    else {
        return QUEUE_NOT_EMPTY;
    }
}
/***********************************************************************************/

/**
 * @brief  Adding a new element into the queue's front.
 *  
 *  This function is used to add an element at the front of the queue
 *  through using the pointer 'Pq' to access the queue struct, to use
 *  the head pointer to put an element in the area that it points to
 *  then check if the head pointer is within the buffer size to be
 *  incremented by one, otherwise it will return to the first address
 *  of the buffer = base address, then we increment the count, after
 *  checking the validation and the capacity of the queue.
 *  Pre-conditions: Ths queue should be initialized and not full.
 *  Post-conditions: The element 'item' is stored at the front of the queue 
    and its value doesn't change there.

 * @param  item: It takes a value of the data type QUEUEENTRY.
 * @param  Pq: It takes a pointer to struct queue. 
 *
 * @return It returns an enum state.
 */
Queue_Status_t Enqueue(Queue_t *Pq, QUEUEENTRY item) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return QUEUE_NULL;
    }
    if (QueueFull(Pq) == QUEUE_FULL) {
        return QUEUE_FULL;
    }
    else {
        *(Pq->head)= item;
        Pq->count++;
        if (Pq->head == (Pq->base + Pq->length * sizeof(QUEUEENTRY))) {
            Pq->head = Pq->base;
        }
        else {
            Pq->head++;
        }
        return QUEUE_NO_ERROR;
    }
}
/***********************************************************************************/

/**
 * @brief  Removing an element from the queue's rear
 *  
 *  This function is used to remove an element at the rear of the queue
 *  through using the pointer 'Pq' to access the queue struct, to use
 *  the tail pointer to remove an element from the area that it points to
 *  then check if the tail pointer is within the buffer size to be
 *  incremented by one, otherwise it will return to the first removeress
 *  of the buffer = base removeress, then we decrement the count, after
 *  checking the validation and the emptiness of the queue.
 *  Pre-conditions: Ths queue should be initialized and not empty.
 *  Post-conditions: The element 'item' is returned.

 * @param  Pe: It takes a pointer to the data type QUEUEENTRY.
 * @param  Pq: It takes a pointer to struct queue. 
 *
 * @return It returns an enum state.
 */
Queue_Status_t Dequeue(Queue_t *Pq, QUEUEENTRY *item) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return QUEUE_NULL;
    }
    if (QueueEmpty(Pq) == QUEUE_EMPTY) {
        return QUEUE_EMPTY;
    }
    else {
        *item = *(Pq->tail);
        Pq->count--;
        if (Pq->tail == (Pq->base + Pq->length * sizeof(QUEUEENTRY))) {
            Pq->tail = Pq->base;
        }  
        else {
            Pq->tail++;
        }
        return QUEUE_NO_ERROR;
    }
}
/***********************************************************************************/

/**
 * @brief  Copy the front element of the queue
 *  
 *  This function is used to copy the front element of 
 *  the queue through assigning the value of it into 
 *  the dereferenced pointer 'Pq', and this value is at the rear or tail of the queue.
 *  Pre-Conditions: The same as dequeue pre-conditions.
 *  Post-Conditions: It returns the value of the first inserted element.

 * @param  Pq: It takes a pointer to struct queue.
 * @param  Pe: It takes a pointer to the data type QUEUEENTRY.
 *
 * @return It returns an enum state
 */
Queue_Status_t QueueFront (Queue_t *Pq, QUEUEENTRY *item) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return QUEUE_NULL;
    }
    if (QueueEmpty(Pq) == QUEUE_EMPTY) {
        return QUEUE_EMPTY;
    }
    else {
        *item = *(Pq->tail);
    }
    return QUEUE_NO_ERROR;
}
/***********************************************************************************/

/**
 * @brief  Get the queue size
 *  
 *  This function is used to get the size of the queue
 *  through accessing the struct queue by the 'Pq' pointer
 *  to get the value of count.
 *  Pre-conditions: The queue is just initialized
 *  Post-conditions: It returns no.elements in the queue.

 * @param  Pq: It takes a pointer to struct queue.
 * @return It returns a value of QUEUEENTRY data type.
 */
QUEUEENTRY QueueSize (Queue_t *Pq) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return 0;
    }
    return Pq->count;
}
/***********************************************************************************/

/**
 * @brief  Clearing the queue
 *  
 *  This function is used to clear the queue through
 *  making the pointers head and tail point to the base address of the
 *  buffer and to assign zere to the count.
 *  Pre-conditions: The queue is just initialized.
 *  Post-conditions: It destroys all elements in the queue
 *  and it's considered to initialize the queue.
 *  Note that: This function is similar to the createqueue() function
 *  in code, but it's different from the concept, beacuse at the user-level
 *  the user doesn't know the details, and it appears that each function has
 *  a different task to do.

 * @param  Pq: It takes a pointer to struct queue.
 * @return It an enum state.
 */
Queue_Status_t ClearQueue (Queue_t *Pq) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return QUEUE_NULL;
    }
    Pq->count = 0;
    Pq->head = Pq->base;
    Pq->tail = Pq->base;
    return QUEUE_CLEARED;
}
/***********************************************************************************/

/**
 * @brief  Traversing the queue
 *  
 *  This function is used to visit each element in the queue
 *  by using a function determinded and provided by the use 
 *  Pre-conditions: The queue is just initialized.
 *  Post-conditions: It returns the purpose the user wants (e.g. display all elements)

 * @param  Pq: It takes a pointer to struct queue.
 * @param  Pf: It takes a pointer to function takes a data type
 * of QUEUEENTRY and returns void
 *
 * @return It returns an enum state.
 */ 
Queue_Status_t TraverseQueue(Queue_t *Pq, void (*Pf) (QUEUEENTRY)) {
    if (!Pq->base || !Pq->head || !Pq->tail) {
        return QUEUE_NULL;
    }
    QUEUEENTRY s = 0, *Pn;
    for (Pn = Pq->tail ; s < Pq->count; s++) {
            (*Pf) (*Pn);
            if (Pn == (Pq->base + Pq->length * sizeof(QUEUEENTRY))) {
                Pn = Pq->base;
            }  
            else {
                Pn++;
            }
        }
    return QUEUE_NO_ERROR;
}
/***********************************************************************************/

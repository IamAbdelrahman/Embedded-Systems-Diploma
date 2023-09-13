/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Introduction to Data Structures
 * By Phd. Walid Youssef - Course introduced by Helwan-University and Recorded
 * on YouTube.
 *****************************************************************************/
/**
 * @file Stack.c
 * @brief Implementaion of Stack Data Structure
 *
 * @author Abdelrahman Kamal
 * @date 5/9/2023
 *
 */
#include "Stack.h"
/**
 * @brief  Initializating the stack
 *  
 *  This function is used to initialize the stack through intializing the
 *  count with zero, the length with MAX_STACK, and initializing the base and head
 *  pointers with the first element of the buffer, if the pointer 'Pf' points to NULL that means
 *  there's no creation happens to stack whether the creation is statically or
 *  dynamically allocated.
 *  Pre-condition: The buffer exists.
 *  Post-condition: The stack exists and is initialized.

 * @param  Ps: It takes a pointer to stack.
 * @param  Pf: It takes a pointer to the buffer.
 *
 * @return It returns an enum state
 */ 
Stack_Status_t initializeStack(Stack_t *Ps, STACKENTRY *Pf) {
    if (Pf == NULL) {
        return STACK_NULL;
    }
    else {
        Ps->base = Pf;
        Ps->head = Pf;
        Ps->count = 0;
        Ps->length = MAX_STACK;
    }
    return STACK_NO_ERROR;
}
/***********************************************************************************/

/**
 * @brief  Check if the stack is full or not
 *  
 *  This function is used to check if the stack is full or not through
 *  checking the equality between the count and the MAX_STACK. After checking
 *  the validation of the stack.
 *  Pre-condition: The stack exists and is initialized.
 *  Post-condition: It returns the state of the stack full or not.

 * @param  Ps: It takes a pointer to stack.
 *
 * @return It returns an enum state
 */
Stack_Status_t StackFull (Stack_t *Ps) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    if (Ps->count == MAX_STACK) {
        return STACK_FULL;
    }
    else {
        return STACK_NOT_FULL;
    }
}
/***********************************************************************************/
/**
 * @brief  Check if the stack is empty or not
 *  
 *  This function is used to check if the stack is empty
 *  or not, through accessing t
 *  Pre-conditions: The stack exists
 *  Post-conditions: It returns the state of the stack 1 or 0;
 * @param  Ps: It takes a pointer to struct stack. 
 *
 * @return It returns an enum state.
 */
Stack_Status_t StackEmpty (Stack_t *Ps) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    if (Ps->count == 0) {
        return STACK_EMPTY;
    }
    else {
        return STACK_NOT_EMPTY;
    }
}
/***********************************************************************************/

/**
 * @brief  Push into the Stack's top
 *  
 *  This function is used to push at the top of the stack
 *  through using the pointer 'Ps' to access the struct's elements
 *  by accessing the head pointer to put the pushed element at there, since
 *  the head pointer always points to the top of the stack, and we increment
 *  the count and the head pointer to be ready for the next push, and this whole 
 *  process happens after checking the validation and the capacity of the stack.
 *  Pre-conditions: Ths stack should be initialized and not full.
 *  Post-conditions: The element 'item' is stored at the top of the stack 
    and its value doesn't change there.

 * @param  item: It takes a value of the data type STACKENTRY.
 * @param  Ps: It takes a pointer to struct stack. 
 *
 * @return It returns an enum state.
 */
Stack_Status_t Push(Stack_t *Ps, STACKENTRY item) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    if (StackFull(Ps) == STACK_FULL) {
        return STACK_FULL;
    }
    else {
        *(Ps->head++) = item;
        Ps->count++;
        return STACK_NO_ERROR;
    }
}
/***********************************************************************************/

/**
 * @brief  Pop off the Stack's top
 *  
 *  This function is used to pop an element off the top of the
 *  stack, through accessing the struct's elements by using the 
 *  head pointer, since the head pointer points to the next to be pushed
 *  So, to get the top element we must decrement the head pointer first
 *  to get the top value, and we decrement the count variable.
 *  Pre-conditions: Ths stack should be initialized and not empty.
 *  Post-conditions: The last element entered is returned.

 * @param  Pe: It takes a pointer to the data type STACKENTRY.
 * @param  Ps: It takes a pointer to struct stack. 
 *
 * @return It returns an enum state.
 */
Stack_Status_t Pop(Stack_t *Ps, STACKENTRY *item) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    if (StackEmpty(Ps) == STACK_EMPTY) {
        return STACK_EMPTY;
    }
    else {
        *item = *(--Ps->head);
        Ps->count--;
        return STACK_NO_ERROR;
    }
}
/***********************************************************************************/

/**
 * @brief  Copy the top element of the stack
 *  
 *  This function is used to copy the top element of 
 *  the stack through assigning the value of the head - 1 pointer
 *  points to, and hence the stack doesn't change.
 *  Pre-Conditions: The same as pop pre-conditions.
 *  Post-Conditions: It returns the value of the last pushed element.

 * @param  Ps: It takes a pointer to struct stack.
 * @param  Pe: It takes a pointer to the data type STACKENTRY.
 *
 * @return It returns an enum state.
 */
Stack_Status_t StackTop (Stack_t *Ps, STACKENTRY *item) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    if (StackEmpty(Ps) == STACK_EMPTY) {
        return STACK_EMPTY;
    }
    else {
        *item = *(Ps->head - 1);
        return STACK_NO_ERROR;
    }
}
/***********************************************************************************/

/**
 * @brief  Get the stack size
 *  
 *  This function is used to get the size of the stack
 *  through checking the count variable of the struct stack.
 *  Pre-conditions: The stack is just initialized
 *  Post-conditions: It returns no.elements in the stack.
 *  Note that: This function achieves here the information hiding
 *  in the implementation level (Abstraction), because someone may think
 *  that he can use direclty an access to the stack in the user-level to get
 *  the value of top and then it's the value of the stack size.

 * @param  Ps: It takes a pointer to struct stack.
 *
 * @return It returns an integer.
 */
STACKENTRY StackSize (Stack_t *Ps) {
    if (!Ps->base || !Ps->head || !Ps) {
        return 0;
    }
    return Ps->count;
}
/***********************************************************************************/

/**
 * @brief  Clearing the stack
 *  
 *  This function is used to clear the stack through
 *  assigning zero to the top variable.
 *  Pre-conditions: The stack is just initialized.
 *  Post-conditions: It destroys all elements in the stack
 *  and it's considered to initialize the stack.
 *  Note that: This function is similar to the createStack() function
 *  in code, but it's different from the concept, beacuse at the user-level
 *  the user doesn't know the details, and it appears that each function has
 *  a different task to do.

 * @param  Ps: It takes a pointer to struct stack.
 *
 * @return It returns nothing
 */
Stack_Status_t ClearStack (Stack_t *Ps) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    Ps->count = 0;
    Ps->head = Ps->base;
    return STACK_CLEARED;
}
/***********************************************************************************/

/**
 * @brief  Traversing the stack
 *  
 *  This function is used to traverse or visit all elements of the stack
 *  without changing the stack itself, through creating a local pointer 'Pn'
 *  and points to the head - 1 pointer or the last area that has an element,
 *  bacause when we push a new element, the head pointer becomes pointing to
 *  the next area, and as the 'Pn' pointer becomes less than or equal
 *  the base pointer, the loop breaks.
 *  Pre-conditions: The stack is just initialized.
 *  Post-conditions: It visits all elements in the stack, and the user only
 *  has to do some actions on all elements such as displaying them.

 * @param  Ps: It takes a pointer to struct stack.
 * @param  Pf: It takes a pointer to function takes a data type
 * of STACKENTRY and returns void
 *
 * @return It returns an enum state.
 */ 
Stack_Status_t TraverseStack(Stack_t *Ps, void (*Pf) (STACKENTRY)) {
    if (!Ps->base || !Ps->head || !Ps) {
        return STACK_NULL;
    }
    for (STACKENTRY *Pn = Ps->head - 1; Pn >= Ps->base; Pn--) {
            (*Pf) (*Pn);
        }
    return STACK_NO_ERROR;
}
/***********************************************************************************/

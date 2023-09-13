/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Data Structures 
 * Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file LIFO.h
 * @brief Stack_Status_terfaces of LIFO_Buf_t Data Structure
 *
 * @author Abdelrahman Kamal
 * @date 10/9/2023
 *
 */
#ifndef __Stack_H__
#define __Stack_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#define MAX_STACK  10
typedef uint32_t STACKENTRY;

typedef struct Stack_t {
    STACKENTRY length;
    STACKENTRY count;
    STACKENTRY *base;
    STACKENTRY *head;
}Stack_t;

typedef enum status {
    STACK_NO_ERROR,
    STACK_NULL,
    STACK_FULL,
    STACK_NOT_FULL,
    STACK_EMPTY,
    STACK_NOT_EMPTY,
    STACK_CLEARED,

}Stack_Status_t;

/* APIS */
Stack_Status_t initializeStack(Stack_t *, STACKENTRY *);
Stack_Status_t StackFull (Stack_t *);
Stack_Status_t Push(Stack_t *, STACKENTRY);
Stack_Status_t Pop (Stack_t *, STACKENTRY *);
Stack_Status_t StackEmpty (Stack_t *);
Stack_Status_t StackTop (Stack_t *, STACKENTRY *);
STACKENTRY StackSize (Stack_t *); 
Stack_Status_t ClearStack (Stack_t *);
Stack_Status_t TraverseStack(Stack_t *, void (*) (STACKENTRY));

#endif /* __Stack_H__ */
/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Data Structures 
 * Learn-In-Depth Diploma
 *****************************************************************************/
/**
 * @file Queue.h
 * @brief Queue Data Structure Interfaces Functions 
 *
 * @author Abdelrahman Kamal
 * @date 12/9/2023
 *
 */
#ifndef __Queue_H__
#define __Queue_H__

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#define MAXQUEUE  10
typedef uint32_t QUEUEENTRY;

typedef struct queue {
    QUEUEENTRY length;
    QUEUEENTRY count;
    QUEUEENTRY *base;
    QUEUEENTRY *head;
    QUEUEENTRY *tail;
}Queue_t;

typedef enum status {
    QUEUE_NO_ERROR,
    QUEUE_NULL,
    QUEUE_FULL,
    QUEUE_NOT_FULL,
    QUEUE_EMPTY,
    QUEUE_NOT_EMPTY,
    QUEUE_CLEARED,

}Queue_Status_t;

/* APIS */
Queue_Status_t initializeQueue(Queue_t *, QUEUEENTRY *);
Queue_Status_t QueueFull (Queue_t *);
Queue_Status_t Enqueue(Queue_t *, QUEUEENTRY);
Queue_Status_t Dequeue (Queue_t *, QUEUEENTRY *);
Queue_Status_t QueueEmpty (Queue_t *);
Queue_Status_t QueueFront (Queue_t *, QUEUEENTRY *);
QUEUEENTRY QueueSize (Queue_t *); 
Queue_Status_t ClearQueue (Queue_t *);
Queue_Status_t TraverseQueue (Queue_t *, void (*) (QUEUEENTRY));

#endif /* __Queue_H__ */
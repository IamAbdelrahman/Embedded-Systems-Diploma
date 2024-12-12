/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Introduction to Data Structures
 * By Phd. Walid Youssef - Course introduced by Helwan-University and Recorded
 * on YouTube.
 *****************************************************************************/

/*****************************************************************************
 * @file Queue.h
 * @brief The header definitions of the queue(FIFO) data structure
 * it's ideal for handling circular buffers in USART communication.
 * @author Abdelrahman Kamal
 * @date 7/9/2023
 *****************************************************************************/

#ifndef __QUEUE_H__
#define __QUEUE_H__

/*- INCLUDES
-----------------------------------------------------------------------*/
#include "../Platform_Types.h"

/*- GLOBAL MACROS
-----------------------------------------------------------------------*/
#define MAXQUEUE   100U

/*- GLOBAL TYPEDEFS
-----------------------------------------------------------------------*/
typedef vuint8_t QueueEntry;

typedef struct queue {
    vuint8_t front;
    vuint8_t rear;
    vuint8_t size;
    QueueEntry entry [MAXQUEUE];
}ST_Queue_t;

/*- GLOBAL VARIABLES
-----------------------------------------------------------------------*/

/*- APIs PROTOTYPES
-----------------------------------------------------------------------*/
/************************************************************************
 * @brief  initialize the queue
 * @param pq a pointer to the queue structure
 * @return None
 *************************************************************************/
void Queue_init (ST_Queue_t *pq);

/************************************************************************
 * @brief  check if the queue if full or not
 * @param pq a pointer to the queue structure
 * @return 1 if full, 0 otherwise
 *************************************************************************/
int Queue_full (ST_Queue_t *pq);

/************************************************************************
 * @brief  insert an element at the rear of queue
 * @param pq a pointer to the queue structure
 * @param e Element to insert (type: QueueEntry)
 * @return None
 *************************************************************************/
void Enqueue(QueueEntry e, ST_Queue_t *pq);

/************************************************************************
 * @brief  Remove an element from the front of the queue
 * @param pq a pointer to the queue structure
 * @param pe a pointer to store the popped element
 * @return None
 *************************************************************************/
void Dequeue (QueueEntry *pe, ST_Queue_t *pq);

/************************************************************************
 * @brief  Check if the queue is empty or not
 * @param pq a pointer to the queue structure
 * @return 1 if empty, 0 otherwise
 *************************************************************************/
int Queue_empty (ST_Queue_t *pq);

/************************************************************************
 * @brief Copy the first element of the queue
 * @param pq a pointer to the queue structure
 * @return the first element of the queue
 *************************************************************************/
int Queue_front (ST_Queue_t *pq);

/************************************************************************
 * @brief Get the size of the queue
 * @param pq a pointer to the queue structure
 * @return Number of elements in the queue
 *************************************************************************/
int Queue_size (ST_Queue_t *pq);

/************************************************************************
 * @brief Clear the queue
 * @param pq a pointer to the queue structure
 * @return None
 *************************************************************************/
void Queue_clear (ST_Queue_t *pq);

/************************************************************************
 * @brief  traverse the queue
 * @param pq a pointer to the queue structure
 * @param pf a pointer to a display function (takes StackEntry as input)
 * @return None
 *************************************************************************/
void Queue_traverse(ST_Queue_t *pq, void (*pf) (QueueEntry));


#endif /* __QUEUE_H__ */

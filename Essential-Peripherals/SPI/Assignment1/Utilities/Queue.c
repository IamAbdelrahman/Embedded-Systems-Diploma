/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Introduction to Data Structures
 * By Phd. Walid Youssef - Course introduced by Helwan-University and Recorded
 * on YouTube.
 *****************************************************************************/

/*****************************************************************************
 * @file Queue.c
 * @brief Implementation of Queue Data Structure
 * @author Abdelrahman
 * @date 5/9/2023
 *****************************************************************************/

/*- INCLUDES
------------------------------------------------------------------*/
#include "Queue.h"

/*- APIs IMPLEMENTATION
-------------------------------------------------------*/
void Queue_init(ST_Queue_t *pq) {
    pq->front = 0;
    pq->rear = 99;
    pq->size = 0;
}

int Queue_full(ST_Queue_t *pq) {
    return (pq->size == MAXQUEUE);
}

int Queue_empty(ST_Queue_t *pq) {
    return (pq->size == 0);
}

void Enqueue(QueueEntry e, ST_Queue_t *pq) {
    if (Queue_full(pq))
        return;
    pq->rear = (pq->rear + 1) % MAXQUEUE;
    pq->entry[pq->rear] = e;
    pq->size++;
}

void Dequeue(QueueEntry *pe, ST_Queue_t *pq) {
    if (Queue_empty(pq))
        return;
    *pe = pq->entry[pq->front];
    pq->front = (pq->front + 1) % MAXQUEUE;
    pq->size--;
}

int Queue_front(ST_Queue_t *pq) {
    if (Queue_empty(pq))
        return -1;
    return pq->entry[pq->front];
}

int Queue_size(ST_Queue_t *pq) {
    return pq->size;
}

void Queue_clear(ST_Queue_t *pq) {
    Queue_init(pq);
}

void Queue_traverse(ST_Queue_t *pq, void (*pf)(QueueEntry)) {
    int pos = pq->front;
    for (int i = 0; i < pq->size; i++) {
        pf(pq->entry[pos]);
        pos = (pos + 1) % MAXQUEUE;
    }
}

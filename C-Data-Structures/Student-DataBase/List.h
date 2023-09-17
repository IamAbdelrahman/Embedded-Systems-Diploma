/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Introduction to Data Structures
 * By Phd. Walid Youssef - Course introduced by Helwan-University and Recorded
 * on YouTube.
 *****************************************************************************/
/**
 * @file List.h
 * @brief Interface of List data structures.
 *
 * @author Abdelrahman Kamal
 * @date 13/9/2023
 *
 */
#ifndef __LIST_H__
#define __LIST_H__
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#define PRINT(...)  {fflush(stdout); \
                    fflush(stdin);    \
                    printf(__VA_ARGS__); \
                    fflush(stdout); \
                    fflush(stdin);}
typedef struct sdata {
    int ID;
    char name [40];
    float height;
}Sdata_t;
typedef Sdata_t LISTENTRY;

typedef struct listnode {
    LISTENTRY student;
    struct listnode *next;
}List_Node_t;

typedef struct list {
    int size;
    List_Node_t *head;
}List_t;

/* Functions Prototypes */
void initializeList (List_t *);
int ListFull (List_t *);
int ListEmpty (List_t *);
int ListSize (List_t *);
int DestroyList (List_t *);
int InsertList(int, List_t *);
int DeleteList_Pos(List_t *);
int DeleteList_ID(List_t *);
int RetrieveList(List_t *);
int RetrieveListFromEnd(List_t *);
int ReplaceList (List_t *);
int TraverseList(List_t *, void (*) (LISTENTRY*));
int MiddleList(List_t *);
void ReverseList(List_t *);
#endif /* __LIST_H__ */

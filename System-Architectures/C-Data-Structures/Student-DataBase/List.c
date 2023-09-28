/******************************************************************************
 * Copyright (C) 2023 by Abdelrahman Kamal - Introduction to Data Structures
 * By Phd. Walid Youssef - Course introduced by Helwan-University and Recorded
 * on YouTube.
 *****************************************************************************/
/**
 * @file List.c
 * @brief Implementaion of List Data Structure
 *
 * @author Abdelrahman Kamal
 * @date 12/9/2023
 *
 */
#include "List.h"
/**
 * @brief  Initialize the List
 *
 * This function initializes a linked list by setting its size to zero and the 'head' pointer to NULL.
 * It should be called when a new list is declared or created.
 *
 * @param Pl: It takes a pointer to a struct List.
 *
 * @return It returns nothing.
 */
void initializeList(List_t *Pl)
{
    Pl->size = 0;
    Pl->head = NULL;
}

/*------------------------------------------------------------------------------------*/
/**
 * @brief  Check if the list is empty or not
 *
 * This function is used to determine whether the list is empty or not.
 * It checks the value of the list's size, and if the size is 0, it returns 1,
 * indicating that the list is truly empty. Otherwise, it returns 0, indicating
 * that the list contains one or more elements.
 *
 * Pre-condition: The list is just initialized.
 * Post-condition: It returns 0 or 1
 *
 * @param Pl: It takes a pointer to a struct List.
 *
 * @return It returns an integer: 0 (not empty) or 1 (empty).
 */
int ListEmpty(List_t *Pl)
{
    return !(Pl->size);
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Check if the list is full or not
 *
 * This function is used to check if the list is full or not, but in this
 * implementation, the list is always considered not full. This is because
 * linked lists can theoretically grow until you exhaust the available memory,
 * so they don't have a fixed "full" state like arrays.
 *
 * Pre-condition: The list is just initialized.
 * Post-condition: It always returns false (0).
 *
 * @param Pl: It takes a pointer to struct List.
 *
 * @return It returns an integer: 0 (not full).
 */
int ListFull(List_t *Pl)
{
    return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Get the size of the List
 *
 * This function is used to get the size of the linked list by returning
 * the current number of elements in the list. The size increments when new
 * elements are inserted into the list and decreases when elements are removed.
 *
 * Pre-condition: The list is initialized.
 * Post-condition: It returns the current size of the list.
 *
 * @param Pl: It takes a pointer to struct List.
 *
 * @return It returns an integer representing the current size of the list.
 */
int ListSize(List_t *Pl)
{
    return (Pl->size);
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Destroy the List
 *
 * This function is used to destroy the linked list by deallocating memory for
 * all the nodes in the list. It starts by iterating through the list, freeing
 * each node one by one until it reaches the end of the list (when `head` becomes NULL).
 * After deallocating all nodes, it sets the size of the list to 0.
 *
 * Pre-condition: The list is initialized.
 * Post-condition: All nodes in the list are deallocated, and the list is empty.
 *
 * @param Pl: It takes a pointer to struct List.
 *
 * @return It returns 1 if the list was successfully destroyed (non-empty list),
 *         0 if the list was already empty.
 */
int DestroyList(List_t *Pl)
{
    if (!ListEmpty(Pl))
    {
        List_Node_t *PCurrentStudent;
        while (Pl->head)
        {
            PCurrentStudent = Pl->head->next;
            free(Pl->head);
            Pl->head = PCurrentStudent;
        }
        Pl->size = 0;
        PRINT("\nDeleted Successfully");
        return 1;
    }
    else
        PRINT("\nEmpty List!");
    return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Insert elements in the List
 *
 * This function is used to insert new elements into the list at the specified 'pos' position.
 * It dynamically allocates memory for a new list node 'PNewStudent' to store the element.
 * It then prompts the user to input the values (ID, name, height) for the new element.
 * The new node's 'next' pointer is initially set to NULL.
 *
 * If 'pos' is 0, the new node becomes the head of the list, and its 'next' pointer
 * is updated to point to the previous head of the list, and the list's 'head' pointer
 * is updated to point to the new node.
 *
 * If 'pos' is greater than 0, it iterates through the list to find the node at the
 * position just before 'pos'. It then updates the 'next' pointers to insert the new node
 * in the desired position.
 *
 * After insertion, the size of the list is increased by one, and a success message is printed.
 *
 * Pre-condition: The list is just initialized, and not full.
 * Post-condition: The element 'e' is inserted at the 'pos' location, and the size of the list is increased by one.
 *
 * @param pos: It takes an integer 'pos' that indicates the index/location.
 * @param Pl: It takes a pointer to struct List.
 *
 * @return It returns 1 if the element was successfully inserted, 0 if memory allocation failed.
 */
int InsertList(int pos, List_t *Pl)
{
    List_Node_t *PNewStudent, *Qn;
    if ((PNewStudent = (List_Node_t *)malloc(sizeof(List_Node_t))))
    {
        PRINT("\nEnter your ID:");
        scanf("%d", &PNewStudent->student.ID);
        PRINT("\nEnter your name:");
        scanf("%s", PNewStudent->student.name);
        getc(stdin);
        PRINT("\nEnter your height:");
        scanf("%f", &PNewStudent->student.height);
        PNewStudent->next = NULL;
        if (pos == 0)
        {
            PNewStudent->next = Pl->head;
            Pl->head = PNewStudent;
        }
        else
        {
            int i = 0;
            for (Qn = Pl->head; i < pos - 1; i++)
                Qn = Qn->next;
            PNewStudent->next = Qn->next;
            Qn->next = PNewStudent;
        }
        Pl->size++;
        PRINT("\n\nAdded Successfully");
        return 1;
    }
    else
        return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Delete elements in the List by Position
 *
 * This function deletes an element from the list at a specified position.
 * If successful, it returns 1. If the position is out of bounds,
 * or, if the list is empty, it returns 0.
 *
 * @param Pl: Pointer to struct List.
 * @param pos: Position of the element to be deleted.
 *
 * @return It returns 1 if the element was successfully deleted, and 0 if the list
 * is empty, or the position entered by the user is out of the boundry.
 */
int DeleteList_Pos(List_t *Pl)
{
    int pos;
    PRINT("Please Enter your position: ");
    scanf("%d", &pos);
    pos--;
    if (ListEmpty(Pl))
    {
        PRINT("\nEmpty List!, cannot delete");
        return 0;
    }

    if (pos < 0 || pos >= Pl->size)
    {
        PRINT("\nPosition is out of boundry, cannot delete");
        return 0;
    }

    List_Node_t *temp;
    LISTENTRY *deletedElement;
    if (pos == 0)
    {
        temp = Pl->head->next;
        free(Pl->head);
        Pl->head = temp;
    }
    else
    {
        int i = 0;
        List_Node_t *Qn;
        for (Qn = Pl->head; i < pos - 1; i++)
        {
            Qn = Qn->next;
        }
        temp = Qn->next->next;
        free(Qn->next);
        Qn->next = temp;
    }

    Pl->size--;
    PRINT("\n\nDeleted Successfully")
    return 1;
}
/*------------------------------------------------------------------------------------*/
/**
 * @brief  Delete elements in the List by ID
 *
 * This function deletes an element from the list with a specified ID.
 * If successful, it returns DELETE_SUCCESS. If the ID is not found in the list,
 * or, if the list is empty, it returns 0.
 *
 * @param Pl: Pointer to struct List.
 * @param id: ID of the element to be deleted.
 *
 * @return It returns 1 if the element was successfully deleted, and 0 if the list
 * is empyt, or the ID entered by the user was not found.
 */
int DeleteList_ID(List_t *Pl)
{
    if (ListEmpty(Pl))
    {
        PRINT("\nEmpty List!, cannot delete");
        return 0;
    }

    List_Node_t *temp, *Qn = Pl->head;
    int id;
    PRINT("Please, Enter your id: ");
    scanf("%d", &id);
    if (id == Pl->head->student.ID)
    {
        temp = Pl->head->next;
        free(Pl->head);
        Pl->head = temp;
        Pl->size--;
        PRINT("\nDeleted Successfully");
        return 1;
    }
    else
    {
        while (Qn->next)
        {
            if (id == Qn->next->student.ID)
            {
                temp = Qn->next->next;
                free(Qn->next);
                Qn->next = temp;
                Pl->size--;
                PRINT("\nDeleted Successfully");
                return 1;
            }
            Qn = Qn->next;
        }
    }
    PRINT("\nID is not found");
    return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Replace an element in the List
 *
 * This function is used to replace an element in the list with an element
 * entered by a user. It takes a pointer to a function that prints the replaced data.
 *
 * @param Pl: Pointer to struct List.
 * @param Pf: Pointer to a function that prints the replaced data.
 *
 * @return It returns an integer 0 or 1, If successful, it returns 1. If the specified position is out of bounds,
 * or, if the list is empty, it returns 0.
 */
int ReplaceList(List_t *Pl, void (*Pf)(LISTENTRY *))
{
    if (ListEmpty(Pl))
    {
        PRINT("\nEmpty List!, cannot replaced");
        return 0;
    }
    int pos;
    PRINT("Please, Enter your position: ");
    scanf("%d", &pos);
    pos--;
    if (pos < 0 || pos >= ListSize(Pl))
    {
        PRINT("\nPosition is out of boundry, cannot replaced");
        return 0;
    }

    List_Node_t *Qn = Pl->head;
    LISTENTRY *replaceData = (LISTENTRY *)malloc(sizeof(LISTENTRY));
    if (replaceData)
    {
        PRINT("\nEnter your new data here: ");
        PRINT("\nID: ");
        scanf("%d", &replaceData->ID);
        PRINT("\nName: ");
        scanf("%s", replaceData->name);
        getc(stdin);
        PRINT("\nHeight: ");
        scanf("%f", &replaceData->height);
        for (int i = 0; i < pos; i++)
        {
            Qn = Qn->next;
        }

        Qn->student.height = replaceData->height;
        Qn->student.ID = replaceData->ID;
        strcpy(Qn->student.name, replaceData->name);

        if (Pf != NULL)
        {
            (*Pf)(&Qn->student);
        }
        PRINT("\nReplaced Successfully");
        return 1;
    }
    else
        return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Retrieve elements from the List
 *
 * This function is used to retrieve an element from the list at a specified position
 * and copy it to the provided pointer '*Pe'. It also takes a pointer to a function 'Pf'
 * that can be used to print the retrieved data.
 *
 * @param Pl: Pointer to struct List.
 * @param Pf: Pointer to a function that prints the retrieved data.
 *
 * @return It returns an integer 0 or 1, If successful, it returns 1. If the specified position is out of bounds,
 * or, if the list is empty, it returns 0.
 */
int RetrieveList(List_t *Pl, void (*Pf)(LISTENTRY *))
{
    if (ListEmpty(Pl))
    {
        PRINT("\nEmpty List!, cannot retrieve");
        return 0;
    }
    int pos;
    PRINT("\nEnter your position: ");
    scanf("%d", &pos);
    pos--;
    if (pos < 0 || pos >= ListSize(Pl))
    {
        PRINT("\nThis position is out of boundry!");
        return 0;
    }

    List_Node_t *Qn = Pl->head;
    int i = 0;
    for (i = 0; i < pos; i++)
    {
        Qn = Qn->next;
    }
    LISTENTRY *PStudent = (LISTENTRY *)malloc(sizeof(LISTENTRY));
    if (PStudent)
    {
        PStudent->height = Qn->student.height;
        PStudent->ID = Qn->student.ID;
        strcpy(PStudent->name, Qn->student.name);
        if (Pf != NULL)
        {
            (*Pf)(PStudent);
        }
        PRINT("\n\nRetreived Successfully");
        return 1;
    }
    else
        return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Retrieve elements from the List (from the end)
 *
 * This function is used to retrieve an element from the list at a position
 * specified from the end and copy it to the provided pointer '*Pe'.
 * It also takes a pointer to a function 'Pf' that can be used to print the retrieved data.
 *
 * @param Pl: Pointer to struct List.
 * @param Pf: Pointer to a function that prints the retrieved data.
 *
 * @return It returns an integer 0 or 1, If successful, it returns 1. If the specified position is out of bounds,
 * or, if the list is empty, it returns 0.
 */
int RetrieveListFromEnd(List_t *Pl, void (*Pf)(LISTENTRY *))
{
    if (ListEmpty(Pl))
    {
        PRINT("\nEmpty List!, cannot retrieve");
        return 0;
    }
    int pos;
    PRINT("\nEnter your position: ");
    scanf("%d", &pos);
    pos--;
    if (pos < 0 || pos >= ListSize(Pl))
    {
        PRINT("\nThis position is out of boundry!");
        return 0;
    }
    pos = ListSize(Pl) - (pos + 1);
    List_Node_t *Qn = Pl->head;
    int i = 0;
    for (i = 0; i < pos; i++)
    {
        Qn = Qn->next;
    }
    LISTENTRY *PStudent = (LISTENTRY *)malloc(sizeof(LISTENTRY));
    if (PStudent)
    {
        PStudent->height = Qn->student.height;
        PStudent->ID = Qn->student.ID;
        strcpy(PStudent->name, Qn->student.name);
        if (Pf != NULL)
        {
            (*Pf)(PStudent);
        }
        PRINT("\n\nRetreived Successfully");
        return 1;
    }
    else
        return 0;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Traverse elements in the List and apply a user-defined function
 *
 * This function is used to traverse all elements in the list and apply a user-defined function
 * to each element. The user-defined function `Pf` takes a `LISTENTRY` as an argument.
 *
 * @param Pl: Pointer to struct List.
 * @param Pf: Pointer to a function that takes `LISTENTRY` and returns void.
 *
 * @return It returns an integer 0 or 1. If successful, it returns 1.
 * If the list is empty, it returns 0.

 */
int TraverseList(List_t *Pl, void (*Pf)(LISTENTRY *))
{
    if (ListEmpty(Pl))
    {
        PRINT("\nEmpty List!, cannot traverse");
        return 0;
    }

    int count = 0;
    List_Node_t *PCurrentStudent = Pl->head;

    for (; PCurrentStudent != NULL; PCurrentStudent = PCurrentStudent->next)
    {
        PRINT("\n\t Record number %d ", ++count);
        (*Pf)(&(PCurrentStudent->student));
    }

    return 1;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Get the middle node of the list and apply a user-defined function
 *
 * This function is used to find the middle node in the list and apply a user-defined function
 * to it. The user-defined function `Pf` takes a `LISTENTRY` as an argument.
 *
 * @param Pl: Pointer to struct List.
 * @param Pf: Pointer to a function that takes `LISTENTRY` and returns void.
 *
 * @return It returns an integer 0 or 1. If successful, it returns 1.
 * If the list is empty, it returns 0.
 */
int MiddleList(List_t *Pl, void (*Pf)(LISTENTRY *))
{
    if (ListEmpty(Pl))
    {
        return 0;
    }

    List_Node_t *SlowPtr = Pl->head, *FastPtr = Pl->head;
    LISTENTRY *PStudent = malloc(sizeof(LISTENTRY));

    if (PStudent == NULL)
    {
        return 0;
    }

    while (FastPtr && FastPtr->next)
    {
        SlowPtr = SlowPtr->next;
        FastPtr = FastPtr->next->next;
    }

    PStudent->ID = SlowPtr->student.ID;
    PStudent->height = SlowPtr->student.height;
    strcpy(PStudent->name, SlowPtr->student.name);

    PRINT("\n\t Middle List is:");
    (*Pf)(PStudent);

    free(PStudent);
    return 1;
}
/*------------------------------------------------------------------------------------*/

/**
 * @brief  Reverse elements in the List
 *
 *  This function is used to reverse the elements in the linked list.
 *  It iterates through the list, reversing the direction of the pointers.
 *  Pre-condition: The list is initialized.
 *  Post-condition: The elements in the list are reversed.
 * @param Pl: It takes a pointer to struct List.
 *
 * @return It returns nothing
 */
void ReverseList(List_t *Pl)
{
    List_Node_t *prev = NULL;
    List_Node_t *current = Pl->head;
    List_Node_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    Pl->head = prev;
    PRINT("\n\nReversed Successfully");
}
/*------------------------------------------------------------------------------------*/
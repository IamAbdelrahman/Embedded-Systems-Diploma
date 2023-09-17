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
 *  This function is used to initialize the List through
 *  initializing the size with zero, and the 'head' pointer to
 *  point to NULL.
 *  Pre-condition: The list is just declared or created.
 *  Post-condition: The list is just initialized.
 * @param Pl: It takes a pointer to struct List
 *
 * @return It returns nothing
 */
void initializeList(List_t *Pl)
{
    Pl->size = 0;
    Pl->head = NULL;
}
/***********************************************************************************/

/**
 * @brief  Check if the list is empty or not
 *
 *  This function is used to check if the list is empty or not by
 *  checking the value of the size, if the size is 0, it returned 1
 *  that means the list is truely empty and vice versa.
 *  Pre-condition: The list is initialized.
 *  Post-condition: It returns the state of the list.
 * @param Pl: It takes a pointer to struct List
 *
 * @return It returns an integer 0 or 1
 */
int ListEmpty(List_t *Pl)
{
    return !(Pl->size);
}
/***********************************************************************************/

/**
 * @brief  Check if the list is full or not
 *
 *  This function is used to check if the list is full or not
 *  but here, the list is always not full (supposed if the user doesn't
 *  exceed the physical size of the memory).
 *  Pre-condition: The list is just initialized.
 *  Post-condition: It returns always false.
 * @param Pl: It takes a pointer to struct List
 *
 * @return It returns an integer 0 or 1.
 */
int ListFull(List_t *Pl)
{
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Get the size of the List
 *
 *  This function is used to get the size of the list through
 *  returning the current size of the list, as the size increments
 *  when inserting new elemnts in the list, and decrments in the opposite
 *  process.
 * @param Pl: It takes a pointer to struct List
 *
 * @return It returns an integer 0 or 1.
 */
int ListSize(List_t *Pl)
{
    return (Pl->size);
}
/***********************************************************************************/

/**
 * @brief  Destroy the List
 *
 *  This function is used to destroy the List through
 *  creating a local pointer 'PNewStudent' that points to the next node
 *  after the node the head points to, so now we have two pointers, the 'head'
 *  holds the 1st node and 'PNewStudent' holds the second node, now we free the 'head',
 *  repeating this process until we find out the 'head' points to NULL, then we
 *  zero the size.
 * @param Pl: It takes a pointer to struct List
 *
 * @return It returns nothing
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
        PRINT("\nDeleted Successully");
        return 1;
    }
    else
        PRINT("\nEmptyList!");
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Insert elements in the List
 *
 *  This function is used to insert new elements in the list
 *  in the 'p' position, through creating a pointer that point to a listnode,
 *  the first one is 'PNewStudent' and it's dynamically allocated to store
 *  the element we want to insert in the list, and it access the listnode
 *  to make the next pointer points to NULL as an initial value, then we check
 *  the position, if it is the 1st position (i.e. the list is empty) so directly
 *  the next pointer of the 'PNewStudent' will point to NULL, and the head pointer will point
 *  to the 'PNewStudent', and the 'current' pointer points to the inserted node and the currentpos will be 0
 *  if not and the position is > 1, we check again about the 'pos' and the current position
 *  to see if the position less than or equal, we will iterate from the head till the position
 *  that is before the position we want to insert in then we make the the next pointer of the node
 *  before the inserted node points to the new node, and the next pointer of the inserted node points
 *  to the node the current->next points to, but if the position is higher than the current position
 *  the iteration will start from the current position till the determined position, and hence
 *  we enhance the performance here and save the execution time of this function.
 *  Pre-condition: The list is just initialized, and not full
 *  Post-condition: The element 'e' is inserted in the 'p' location and
 *  the size is increased by one.
 * @param Pl: It takes a pointer to struct List.
 * @param e: It takes an element of a LISTENTRY data type.
 * @param pos: It takes an int pos indicates the index/location.
 *
 * @return It returns nothing
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
        PRINT("\n\nAdded Successully");
        return 1;
    }
    else
        return 0;
}
/***********************************************************************************/

/**
 * @brief  Delete elements in the List
 *
 *  This function is used to delete an already existed element in
 *  the list at location p, by creating two local pointers that point
 *  to listnode 'Qn' and 'temp', if the position equals zero, so we want to
 *  delete the only element in the list, so we will get the element from
 *  the only node and store it in the (*Pe) that is passed by the user, then we use
 *  the 'temp' pointer to point to the areat that the 'next' pointer of the 1st node
 *  points to which is NULL here, and then we free the 'head' pointer, and make it
 *  points to the temp, but if the position is not zero, and we want to delete from
 *  any position in the list, so we use the 'Qn' pointer to loop inside the list
 *  to get the node before the node we want to delete it, then we get the value of the
 *  element of the node we want to delete it by using this pointer 'Qn', and we make the
 *  'temp' pointer to point to the node that the deleted-node points to, then we free the 'Qn->next'
 *  pointer, to use this pointer to point to the node that's after the deleted node.
 *  Pre-condition: The list is just initialized and not empty
 *  Post-condition: The element 'e' is returned and the size is decreased by one.
 * @param Pl: It takes a pointer to struct List.
 * @param Pe: It takes a pointer to a element of LISTENTRY data type.
 * @param pos: It takes an int indicating the index/location of the element.
 *
 * @return It returns nothing
 */
int DeleteList_Pos(List_t *Pl)
{
    if (!ListEmpty(Pl))
    {
        int pos;
        PRINT("\nEnter Position to be deleted: ");
        scanf("%d", &pos);
        List_Node_t *temp, *Qn;
        if (pos == 0)
        {
            temp = Pl->head->next;
            free(Pl->head);
            Pl->head = temp;
            Pl->size--;
            PRINT("\nDeleted Successully");
            return 1;
        }
        else if (pos > 0 && pos < Pl->size)
        {
            int i = 0;
            for (Qn = Pl->head; i < pos - 1; i++)
                Qn = Qn->next;
            temp = Qn->next->next;
            free(Qn->next);
            Qn->next = temp;
            Pl->size--;
            PRINT("\nDeleted Successully");
            return 1;
        }
        else if (pos < 0 || pos >= Pl->size)
        {
            PRINT("\nPosition is out of boundry!, Cannot delete");
            return 0;
        }
    }
    else
        PRINT("\nEmpty List!, Cannot delete");
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Delete elements in the List
 *
 *  This function is used to delete an already existed element in
 *  the list at location p, by creating two local pointers that point
 *  to listnode 'Qn' and 'temp', if the position equals zero, so we want to
 *  delete the only element in the list, so we will get the element from
 *  the only node and store it in the (*Pe) that is passed by the user, then we use
 *  the 'temp' pointer to point to the areat that the 'next' pointer of the 1st node
 *  points to which is NULL here, and then we free the 'head' pointer, and make it
 *  points to the temp, but if the position is not zero, and we want to delete from
 *  any position in the list, so we use the 'Qn' pointer to loop inside the list
 *  to get the node before the node we want to delete it, then we get the value of the
 *  element of the node we want to delete it by using this pointer 'Qn', and we make the
 *  'temp' pointer to point to the node that the deleted-node points to, then we free the 'Qn->next'
 *  pointer, to use this pointer to point to the node that's after the deleted node.
 *  Pre-condition: The list is just initialized and not empty
 *  Post-condition: The element 'e' is returned and the size is decreased by one.
 * @param Pl: It takes a pointer to struct List.
 * @param Pe: It takes a pointer to a element of LISTENTRY data type.
 * @param pos: It takes an int indicating the index/location of the element.
 *
 * @return It returns nothing
 */
int DeleteList_ID(List_t *Pl)
{
    if (!ListEmpty(Pl))
    {
        int id;
        PRINT("\nPlease Enter ID: ");
        scanf("%d", &id);
        List_Node_t *PSelected_Id = Pl->head, *Qn = Pl->head, *temp;
        if (id == Pl->head->student.ID)
        { // 1st position
            temp = Pl->head->next;
            free(Pl->head);
            Pl->head = temp;
            Pl->size--;
            PRINT("\nDeleted Successully");
            return 1;
        }
        else
        {
            while (PSelected_Id)
            {
                PSelected_Id = PSelected_Id->next;
                if (PSelected_Id == NULL)
                    break;
                if (id == PSelected_Id->student.ID)
                {
                    temp = Qn->next->next;
                    free(Qn->next);
                    Qn->next = temp;
                    Pl->size--;
                    PRINT("\nDeleted Successully");
                    return 1;
                }
                Qn = Qn->next;
            }
            PRINT("\nID is not found!");
            return 0;
        }
    }
    else
        PRINT("\nEmpty List!, Cannot delete");
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Replace an element in the List
 *
 *  This function is used to replace an element in the list with an element
 *  entered by a user, through creating a 'Qn' pointer
 *  to loop till reaching the position of the node we want to
 *  replace its element, and replace the value of the node with the value that's
 *  passed by the user.
 *  Pre-condition: The list is just initialized, and not empty.
 *  Post-condition: The element 'e' is returned and the size doesn't change.
 * @param Pl: It takes a pointer to struct List.
 * @param e: It takes an element of LISTENTRY data type.
 * @param p: It takes an int indicating the index/location of the element.
 *
 * @return It returns nothing
 */
int ReplaceList(List_t *Pl)
{  
    if (!ListEmpty(Pl))
    {
        int pos;
        PRINT("\nEnter Position to be replaced: ");
        scanf("%d", &pos);
        int i = 0;
        List_Node_t *PStudent;
        LISTENTRY *PReplaceStudent;
        PRINT("\nEnter ID:");
        scanf("%d", &PReplaceStudent->ID);
        PRINT("\nEnter name:");
        scanf("%s", PReplaceStudent->name);
        getc(stdin);
        PRINT("\nEnter height:");
        scanf("%f", &PReplaceStudent->height);
        for (PStudent = Pl->head; i < pos; i++)
            PStudent = PStudent->next;
        PStudent->student.ID = PReplaceStudent->ID;
        PStudent->student.height = PReplaceStudent->height;
        strcpy(PStudent->student.name, PReplaceStudent->name);
        PRINT("\nReplaced Successfully");
        return 1;
    }
    else
        PRINT("\nEmpty List!, cannot replace");
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Retrieve elements from the List
 *
 *  This function is used to copy an already existed element in
 *  the list at location pos, through creating a 'Qn' pointer
 *  to loop till reaching the position of the node we want to
 *  retrieve its element, and get the value in the '*Pe' that's
 *  passed by the user.
 *  Pre-condition: The list is just initialized and not empty
 *  Post-condition: The element 'e' is returned and the list doesn't change
 * @param Pl: It takes a pointer to struct List.
 * @param Pe: It takes a pointer to a element of LISTENTRY data type.
 * @param pos: It takes an int indicating the index/location of the element.
 *
 * @return It returns nothing
 */
int RetrieveList(List_t *Pl)
{
    if (!ListEmpty(Pl))
    {
        int pos;
        PRINT("\nEnter Position: ");
        scanf("%d", &pos);
        if (pos < 0 || pos >= ListSize(Pl))
        {
            PRINT("\nPosition is out of boundry!, cannot retrieve");
            return 0;
        }
        else
        {
            int i = 0;
            List_Node_t *Qn = Pl->head;
            LISTENTRY *PStudent;
            for (Qn = Pl->head; i < pos; i++)
            {
                Qn = Qn->next;
            }
            PStudent->ID = Qn->student.ID;
            PStudent->height = Qn->student.height;
            strcpy(PStudent->name, Qn->student.name);
            PRINT("\nRetrieved Successfully");
            PRINT("\n\t Retrieved List is:");
            PRINT("\n\t Student ID: %d", PStudent->ID);
            PRINT("\n\t Student Height: %.2f", PStudent->height);
            PRINT("\n\t Student Name: %s", PStudent->name);
            return 1;
        }
    }
    else
        PRINT("\nEmpty List!, cannot retrieve");
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Retrieve elements from the List
 *
 *  This function is used to copy an already existed element in
 *  the list at location pos, through creating a 'Qn' pointer
 *  to loop till reaching the position of the node we want to
 *  retrieve its element, and get the value in the '*Pe' that's
 *  passed by the user.
 *  Pre-condition: The list is just initialized and not empty
 *  Post-condition: The element 'e' is returned and the list doesn't change
 * @param Pl: It takes a pointer to struct List.
 * @param Pe: It takes a pointer to a element of LISTENTRY data type.
 * @param pos: It takes an int indicating the index/location of the element.
 *
 * @return It returns nothing
 */
int RetrieveListFromEnd(List_t *Pl)
{
    if (!ListEmpty(Pl))
    {
        int pos;
        PRINT("Enter Position: ");
        scanf("%d*c", &pos);
        pos = ListSize(Pl) - pos + 1;
        int i = 0;
        if (pos >= 0)
        {
            List_Node_t *Qn;
            LISTENTRY *PStudent;
            for (Qn = Pl->head; i < pos; i++)
            {
                Qn = Qn->next;
            }
            PStudent->ID = Qn->student.ID;
            PStudent->height = Qn->student.height;
            strcpy(PStudent->name, Qn->student.name);
            PRINT("\n\t Retrieved List is:");
            PRINT("\n\t Student ID: %d", PStudent->ID);
            PRINT("\n\t Student Height: %.2f", PStudent->height);
            PRINT("\n\t Student Name: %s", PStudent->name);
            return 1;
        }
        else
        {
            PRINT("This position is out of boundry!\n");
            return 0;
        }
    }
    else
    {
        PRINT("You cannot retrieve, Empty List!\n");
        return 0;
    }
}
/***********************************************************************************/

/**
 * @brief  Traverse elements in the List
 *
 *  This function is used to traverse all elements in the list
 *  so the user can use a function from his own idea to do some actions
 *  on all elements, so the implementer visits each element and pass it
 *  to a pointer to a function to the user.
 *  Pre-condition: The list is just initialized.
 *  Post-condition: All elements are passed to the user's function (e.g. Display())
 *  Post-condition: The element 'e' is returned and the size is decreased by one.
 * @param Pl: It takes a pointer to struct List.
 * @param Pf: It takes a pointer to a function takes LISTENTRY and returns void.
 *
 * @return It returns nothing
 */
int TraverseList(List_t *Pl, void (*Pf)(LISTENTRY *Ps))
{
    if (!ListEmpty(Pl))
    {
        int count = 0;
        List_Node_t *PCurrentStudent = Pl->head;
        while (PCurrentStudent)
        {
            PRINT("\n\t Record number %d ", ++count);
            (*Pf)(&PCurrentStudent->student);
            PCurrentStudent = PCurrentStudent->next;
        }
        return 1;
    }
    else
    {
        PRINT("Empty List\n");
    }
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Traverse elements in the List
 *
 *  This function is used to traverse all elements in the list
 *  so the user can use a function from his own idea to do some actions
 *  on all elements, so the implementer visits each element and pass it
 *  to a pointer to a function to the user.
 *  Pre-condition: The list is just initialized.
 *  Post-condition: All elements are passed to the user's function (e.g. Display())
 *  Post-condition: The element 'e' is returned and the size is decreased by one.
 * @param Pl: It takes a pointer to struct List.
 * @param Pf: It takes a pointer to a function takes LISTENTRY and returns void.
 *
 * @return It returns nothing
 */
int MiddleList(List_t *Pl)
{
    if (!ListEmpty(Pl) && (ListSize(Pl) > 2))
    {
        List_Node_t *SlowPtr = Pl->head, *FastPtr = Pl->head;
        while (1)
        {
            SlowPtr = SlowPtr->next;
            FastPtr = FastPtr->next->next;
            if (FastPtr == NULL)
                break;
            else
                continue;
        }
        LISTENTRY *PStudent;
        PStudent->ID = SlowPtr->student.ID;
        PStudent->height = SlowPtr->student.height;
        strcpy(PStudent->name, SlowPtr->student.name);
        PRINT("\n\t Middle List is:");
        PRINT("\n\t Student ID: %d", PStudent->ID);
        PRINT("\n\t Student Height: %.2f", PStudent->height);
        PRINT("\n\t Student Name: %s", PStudent->name);
        return 1;

        return 1;
    }
    else
    {
        PRINT("Empty List\n");
    }
    return 0;
}
/***********************************************************************************/

/**
 * @brief  Traverse elements in the List
 *
 *  This function is used to traverse all elements in the list
 *  so the user can use a function from his own idea to do some actions
 *  on all elements, so the implementer visits each element and pass it
 *  to a pointer to a function to the user.
 *  Pre-condition: The list is just initialized.
 *  Post-condition: All elements are passed to the user's function (e.g. Display())
 *  Post-condition: The element 'e' is returned and the size is decreased by one.
 * @param Pl: It takes a pointer to struct List.
 * @param Pf: It takes a pointer to a function takes LISTENTRY and returns void.
 *
 * @return It returns nothing
 */
void ReverseList(List_t *Pl)
{
    List_Node_t *prev = NULL;
    List_Node_t *next = NULL;
    while (Pl->head)
    {
        next = Pl->head->next;
        Pl->head->next = prev;
        prev = Pl->head;
        Pl->head = next;
    }
    prev = Pl->head;
}
/***********************************************************************************/
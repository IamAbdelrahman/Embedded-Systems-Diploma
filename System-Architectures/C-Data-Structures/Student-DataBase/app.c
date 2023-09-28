#include "List.h"
List_t gFirstStudent = {0};
void Display(LISTENTRY *);
int main(void)
{
    initializeList(&gFirstStudent);
    int order = 0;
    while (1)
    {
        PRINT("\n\t ====================== ");
        PRINT("\n\t Choose one of the following options:");
        PRINT("\n\t 1: Add Student ");
        PRINT("\n\t 2: Delete Student with ID ");
        PRINT("\n\t 3: Delete Student with Position ");
        PRINT("\n\t 4: Delete All ");
        PRINT("\n\t 5: Replace Student");
        PRINT("\n\t 6: View Students ");
        PRINT("\n\t 7: View Size ");
        PRINT("\n\t 8: Reverse Students ");
        PRINT("\n\t 9: Display Student with Position ");
        PRINT("\n\t 10: Display Student with Position from the End ");
        PRINT("\n\t 11: Display the Middle Student ");
        PRINT("\n\t  : ");

        scanf("%d", &order);
        switch (order)
        {
        case 1:
            InsertList(ListSize(&gFirstStudent), &gFirstStudent);
            break;
        case 2:
            DeleteList_ID(&gFirstStudent);
            break;
        case 3:
            DeleteList_Pos(&gFirstStudent);
            break;
        case 4:
            DestroyList(&gFirstStudent);
            break;
        case 5:
            ReplaceList(&gFirstStudent, Display);
            break;
        case 6:
            TraverseList(&gFirstStudent, Display);
            break;
        case 7:
            PRINT("Size of the list is %d\n", ListSize(&gFirstStudent));
            break;
        case 8:
            ReverseList(&gFirstStudent);
            break;
        case 9:
            RetrieveList(&gFirstStudent, Display);
            break;
        case 10:
            RetrieveListFromEnd(&gFirstStudent, Display);
            break;
        case 11:
            MiddleList(&gFirstStudent, Display);
            break;
        default:
            break;
        }
    }

    return 0;
}

/**
 * @brief  Displaying elements.
 *
 *  This function is used to print an element of the list
 *  using the PRINT() function.

 * @param PStudent: It is a pointer to struct student data
 *
 * @return It returns nothing
 */
void Display(LISTENTRY *PStudent)
{
    PRINT("\n \t ID:%d ", PStudent->ID);
    PRINT("\n \t Name:%s ", PStudent->name);
    PRINT("\n \t Height:%.2f cm ", PStudent->height);
}

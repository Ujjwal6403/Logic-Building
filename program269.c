#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *next;
    struct Node *prev;      // #
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = iNo;
    newn->prev = NULL;
    newn->next = NULL;
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        (*Head)->prev = newn;
        newn->next = *Head;
        *Head = newn;

    }
}
void Insertlast(PPNODE Head,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = iNo;
    newn->prev = NULL;
    newn->next = NULL;
    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
       while(temp->next != NULL)
       {
            temp = temp->next;
       }
       temp->next = newn;
       temp->prev = temp;

    }
}
void Display(PNODE Head)
{
    printf("Element of linklist are :\n");
    printf("NULL<=>");
    while(Head != NULL)
    {
        printf("| %d |<=>",Head->Data);
        Head = Head->next;
    }
    printf("NULL\n");
}

int Count(PNODE Head)
{
    int iCnt = 0;
    while(Head != NULL)
    {
        iCnt++;
        Head = Head->next;
    }
    return iCnt;
}
void DeleteFirst(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
          
    }
}
void DeleteLast(PPNODE Head)
{
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {

    }
}
int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First,14);
    InsertFirst(&First,13);
    InsertFirst(&First,12);
    InsertFirst(&First,11);

    Display(First);

   Insertlast(&First,101);

    Display(First);
    iRet = Count(First);
    printf("Element of linklist are : %d\n",iRet);
    return 0;
}
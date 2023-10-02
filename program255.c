#include<stdio.h>
#include<stdlib.h>

 typedef struct Node
{
    int Data;
    struct Node *next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head,int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
                                                                                                
    newn->Data = iNo;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }
    else
    {
        newn->next = *Head;
        *Head = newn;
    }

}
void InsertLast(PPNODE Head,int iNo)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->Data = iNo;
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
    }


}

void Display(PNODE Head)
{
    printf("Element of linklist are : \n");

    while(Head != NULL)
    {
        printf("|%d|->",Head->Data);
        Head = Head->next;
    }
    printf("NULL\n");
    
}
int  Count(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    
}
void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;
    
    if(*Head == NULL)
    {
        return;
    }
    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }
    else
    {
       while(temp->next->next != NULL)
       {
        temp = temp->next;
       }
       free(temp->next);
       temp->next = NULL;
       
    }
}
void InsertAtPos(PPNODE Head,int No,int Pos)
{
    int iLength = 0;
    iLength = Count(*Head);

    PNODE newn = NULL;
    PNODE temp = *Head;
    int iCnt = 0;
    /*if((Pos > 1) || (Pos < iLength + 1))
    {
        printf("Invalid Input \n");
        return;
    }*/

    if(Pos == 1)
    {
        InsertFirst(Head,No);
    }
    else if(Pos == iLength + 1)
    {
        InsertLast(Head,No);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->Data = No;
        newn->next = NULL;

        for(iCnt = 1; iCnt < (Pos-1); iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        
    }
}
void DeleteAtPos(PPNODE Head,int Pos)
{
    
    int iLength = 0;
    iLength = Count(*Head);

    PNODE newn = NULL;
    PNODE temp = *Head;
    int iCnt = 0;
    /*if((Pos > 1) || (Pos < iLength + 1))
    {
        printf("Invalid Input \n");
        return;
    }*/

    if(Pos == 1)
    {
        DeleteFirst(Head);
    }
    else if(Pos == iLength + 1)
    {
        DeleteLast(Head);
    }
    {
        for(iCnt = 1; iCnt < (Pos-1); iCnt++)
        {
            temp = temp->next;
        }
        
        
    }
}

int main()
{
    PNODE First = NULL;
    InsertFirst(&First,11);
    InsertFirst(&First,21);
    InsertFirst(&First,31);

    InsertLast(&First,51);
    InsertLast(&First,61);
    InsertLast(&First,55);
    InsertLast(&First,76);
     Display(First);

   InsertAtPos(&First,77,5);

    Display(First);



  

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
};

struct DLL *first, *last;

void insertionAtBegining(int element)
{
    struct DLL *newNode;
    newNode = (struct DLL *)malloc(sizeof(struct DLL));
    if (newNode == NULL)
    {
        printf("Memory loccation failed");
    }
    else
    {
        newNode->data = element;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (first == NULL)
        {
            first = last = newNode;
        }
        else
        {
            newNode->next = first;
            first->prev = newNode;
            first = newNode;
        }
    }
}

void insertionAtEnd(int element)
{
    struct DLL *newNode;
    newNode = (struct DLL *)malloc(sizeof(struct DLL));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed");
    }
    else
    {
        newNode->data = element;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (first == NULL)
        {
            first = last = newNode;
        }
        else
        {
            struct DLL *temp;
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
            newNode->next = NULL;
        }
    }
}

void insertionAtPosition(int element, int pos)
{
    struct DLL *newNode;
    newNode = (struct DLL *)malloc(sizeof(struct DLL));
    if (newNode == NULL)
    {
        printf("Memory cannot be allocated\n");
    }
    else
    {
        newNode->data = element;
        if (first == NULL)
        {
            newNode->next = NULL;
            newNode->prev = NULL;
            newNode = first;
        }
        else if (pos == 0)
        {
            insertionAtBegining(element);
        }
        else
        {
            struct DLL *temp;
            temp = first;
            for (int i = 0; i < pos - 1; i++)
            {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next = newNode;
            temp->next->prev = newNode;
        }
    }
}

void transverse()
{
    struct DLL *temp = first;
    if (first == NULL)
    {
        printf("empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deletionAtBegining()
{
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else if (first->next == NULL)
    {
        printf("%d is going to be deleted", first->data);
        free(first->data);
    }
    else
    {
        struct DLL *temp = first;
        printf("%d is going to be deleted \n", first->data);
        temp = first;
        first = first->next;
        first->prev = NULL;
        free(temp);
    }
}

void deletionAtPosition(int position)
{
    if (first == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        struct DLL *nextNode;

        struct DLL *temp = first;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        nextNode = temp->next;
        temp->next = nextNode->next;
        free(nextNode);
    }
}

void deletionAtEnd()
{
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else if (first->next == NULL)
    {
        printf("%d is going to be deleted\n", first->data);
        free(first->data);
    }
    else
    {
        struct DLL *temp = last;
        printf("%d is going to be deleted from last\n", last->data);
        last = last->prev;
        last->next = NULL;
        free(temp);
    }
}

// Searching in Linked List
void search(int key)
{
    int flag = 0;
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        struct DLL *temp = first;
        do
        {
            if (temp->data == key)
            {
                flag = 1;
                printf("%d element is found\n", temp->data);
            }
            temp = temp->next;
        } while (temp != NULL);
        if (flag == 0)
        {
            printf(" element not found\n");
        }
    }
}

int main()
{
    first = NULL;
    last = NULL;

    transverse();
    insertionAtBegining(10);
    insertionAtBegining(20);
    insertionAtBegining(30);
    insertionAtBegining(40);
    insertionAtBegining(50);
    transverse();
    insertionAtEnd(35);
    insertionAtPosition(32, 2);
    transverse();
    insertionAtBegining(5);
    transverse();
    deletionAtPosition(2);
    transverse();
    deletionAtBegining();
    transverse();
    deletionAtEnd();
    transverse();
    search(20);
}
#include <stdio.h>
#include <stdlib.h>

int count = 0;
struct CLL
{
    int data;
    struct CLL *next;
};

struct CLL *first;

void insertionAtBegining(int element)
{
    struct CLL *newNode;
    newNode = (struct CLL *)malloc(sizeof(struct CLL));
    if (newNode == NULL)
    {
        printf("Memory cannot be allocated.");
    }
    else
    {
        newNode->data = element;
        newNode->next = NULL;
        struct CLL *temp;
        temp = first;

        if (first == NULL)
        {
            newNode->next = newNode;
            first = newNode;
        }
        else
        {
            while (temp->next != first)
            {
                temp = temp->next;
            }

            newNode->next = first;
            temp->next = newNode;
            first = newNode;
        }
        count++;
    }
}

void insertionAtEnd(int element)
{
    struct CLL *newNode;
    newNode = (struct CLL *)malloc(sizeof(struct CLL));
    if (newNode == NULL)
    {
        printf("Memory cannot be Allocated\n");
    }
    else
    {
        newNode->data = element;
        struct CLL *temp = first;

        if (first == NULL)
        {
            newNode = first;
        }
        else
        {
            while (temp->next != first)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = first;
        }
        count++;
    }
}

void insertAtPosition(int element, int pos)
{
    struct CLL *newNode;
    newNode = (struct CLL *)malloc(sizeof(struct CLL));
    if (newNode == NULL)
    {
        printf("Empty List.\n");
    }
    else
    {
        struct CLL *temp;
        newNode->data = element;
        newNode->next = NULL;
        temp = first;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        count++;
    }
}

/**
 * Deletes the first node from a circularly linked list.
 * If the list is empty, it prints "Empty list".
 * If the list has only one node, it frees the memory and sets the first pointer to NULL.
 * If the list has more than one node, it updates the pointers and frees the memory of the first node.
 */
void deleteFromBegining()
{
    if (first == NULL)
    {
        printf("Empty list\n");
    }
    else
    {
        struct CLL *temp;
        temp = first;

        if (first->next == first)
        {
            free(first);
            first = NULL;
        }
        else
        {
            while (temp->next != first)
            {
                temp = temp->next;
            }
            temp->next = first->next;
            struct CLL *second = first->next;
            free(first);
            first = second;
        }
        count--;
    }
}

void deletionFromEnd()
{
    if (first == NULL)
    {

        printf("Empty List\n");
    }
    else if (first->next == first)
    {
        free(first);
        first = NULL;
    }
    else
    {
        struct CLL *temp, *previous;
        temp = first;
        while (temp->next != first)
        {
            previous = temp;
            temp = temp->next;
        }
        previous->next = first;
        first = previous->next;
        free(temp);
        count--;
    }
}

void deleteFromPosition(int pos)
{
    if (first == NULL)
    {
        printf("Empty List\n");
    }
    else if (pos == 0)
    {
        deleteFromBegining();
    }

    else if (pos > count)
    {
        printf("Invalid position\n");
    }
    else
    {
        struct CLL *temp, *previous;
        temp = first;
        for (int i = 0; i < pos - 1; i++)
        {
            previous = temp;
            temp = temp->next;
        }

        previous->next = temp->next;
        free(temp);
        count--;
    }
}

void traverse()
{
    if (first == NULL)
    {
        printf("\nEmpty List.");
    }
    else
    {
        struct CLL *temp;
        temp = first;
        do
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        } while (temp != first);
        printf("\n");
    }
}

int main()
{
    first = NULL;
    insertionAtBegining(10);
    insertionAtBegining(20);
    insertionAtEnd(35);
    traverse();
    insertionAtBegining(30);
    insertionAtBegining(40);
    insertionAtBegining(50);
    traverse();
    insertAtPosition(60, 2);
    insertAtPosition(27, 4);
    traverse();
    deleteFromBegining();
    traverse();
    deletionFromEnd();
    traverse();
    deleteFromPosition(0);
    traverse();
    printf("Total length of list is: %d\n", count);
    return 0;
}
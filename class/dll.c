#include <stdio.h>
#include <stdlib.h>

struct DLL
{
    int data;
    struct DLL *next;
    struct DLL *prev;
};
int count = 0;

struct DLL *first = NULL, *last = NULL;

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
        count++;
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
        count++;
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
            first = newNode;
        }
        else if (pos > count)
        {
            printf("invalidposition");
        }
        else if (pos == 0)
        {
            insertionAtBegining(element);
            count++;
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
            count++;
        }
    }
}

void traverse()
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
        free(first);
        count--;
    }
    else
    {
        struct DLL *temp = first;
        printf("%d is going to be deleted \n", first->data);
        temp = first;
        first = first->next;
        first->prev = NULL;
        free(temp);
        count--;
    }
}

void deletionAtPosition(int position)
{
    if (first == NULL)
    {
        printf("Empty List\n");
    }
    else if (position == 0)
    {
        deletionAtBegining();
        count--;
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
        count--;
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
        free(first);
        count--;
    }
    else
    {
        struct DLL *temp = last;
        printf("%d is going to be deleted from last\n", last->data);
        last = last->prev;
        last->next = NULL;
        free(temp);
        count--;
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
    int choice, element, position, key;

    do
    {
        printf("\n1. Insert element at front");
        printf("\t2. Insert element at end");
        printf("\t3. Insert element at position");
        printf("\t4. Delete element from front");
        printf("\n5. Delete element from end");
        printf("\t6. Delete element from position");
        printf("\t7. search Element");
        printf("\t8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertionAtBegining(5);
            insertionAtBegining(6);
            insertionAtBegining(10);
            printf("Enter element to insert at beginning: ");
            scanf("%d", &element);
            insertionAtBegining(element);
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 2:
            printf("Enter element to insert at end: ");
            scanf("%d", &element);
            insertionAtEnd(element);
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 3:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            printf("Enter position: ");
            scanf("%d", &position);
            insertionAtPosition(element, position);
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 4:
            deletionAtBegining();
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 5:
            deletionAtEnd();
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deletionAtPosition(position);
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 7:
            printf("Enter element to search: ");
            scanf("%d", &key);
            search(key);
            printf("Total length of list is: %d\n", count);
            traverse();
            break;
        case 8:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 9.\n");
        }

    } while (choice != 8);

    return 0;
}
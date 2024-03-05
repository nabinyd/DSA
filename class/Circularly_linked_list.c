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
        printf("\nEmpty List.\n");
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
    int choice;
    do
    {
        printf("\n1. Insert element at front");
        printf("\t2. Insert element at end");
        printf("\t3. Insert element at position");
        printf("\t4. Delete element from front");
        printf("\n5. Delete element from end");
        printf("\t6. Delete element from position");
        printf("\t7. Display Element");
        printf("\t8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertionAtBegining(10);
            insertionAtBegining(20);
            insertionAtBegining(30);
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 2:
            insertionAtEnd(40);
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 3:
            insertAtPosition(25, 2);
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 4:
            deleteFromBegining();
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 5:
            deletionFromEnd();
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 6:
            deleteFromPosition(2);
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 7:
            traverse();
            printf("Total length of list is: %d\n", count);
            break;
        case 8:
            printf("Exit\n");
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (choice != 8);
    return 0;
}

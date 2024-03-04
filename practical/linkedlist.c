#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last;

void insertAtFront(int element)
{
    struct SLL *newnode;
    newnode = (struct SLL *)malloc(sizeof(struct SLL));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else
    {
        newnode->data = element;
        newnode->next = NULL;
        if (first == NULL)
        {
            first = last = newnode;
        }
        else
        {
            newnode->next = first;
            first = newnode;
        }
        printf("%d was inserted at the front\n", element);
    }
}

void insertAtEnd(int element)
{
    struct SLL *newnode;
    newnode = (struct SLL *)malloc(sizeof(struct SLL));
    if (newnode == NULL)
    {
        printf("memory allocation failed\n");
    }
    else
    {
        newnode->data = element;
        newnode->next = NULL;
        if (first == NULL)
        {
            first = last = newnode;
        }
        else
        {
            newnode->data = last;
            last = newnode;
        }
        printf("%d was inserted at the End\n", element);
    }
}

void displayList()
{
    struct SLL *temp = first;
    if (first == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> NULL\n", temp->data);
    }
}

void deletion()
{
    struct SLL *temp = first;
    if (first == NULL)
    {
        printf("Empty List cant be deleted");
    }
    else if (first->next == NULL)

    {
        first = last = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
        free(temp);
    }
}

int main()
{
    first = NULL;
    last = NULL;

    printf("insertion at first \n");
    insertAtFront(10);
    displayList();
    insertAtFront(20);
    displayList();
    insertAtFront(30);
    displayList();
    insertAtFront(40);
    displayList();

    printf("deleting from first\n");
    deletion();
    displayList();
    deletion();
    displayList();
    deletion();
    displayList();
    deletion();
    displayList();
}
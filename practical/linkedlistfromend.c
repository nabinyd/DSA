

#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last;

void insertAtEnd(int element)
{
    struct SLL *newnode;
    struct SLL *temp = first;

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
            while (temp->next != NULL)
            {

                temp = temp->next;
            }
            temp->next = newnode;
        }

        printf("%d was inserted at the end\n", element);
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
        // printf("Elements of Linked list are : \n");
        while (temp->next != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("%d -> NULL\n", temp->data);
    }
}


void deletionFromEnd()
{
    struct SLL *temp = first;
    struct SLL *prevNode;
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
        while (temp->next != NULL)
        {
            prevNode = temp;
            temp = temp->next;
        }
        prevNode->next = NULL;
        free(temp);
    }
}

int main()
{
    first = NULL;
    last = NULL;

    printf("..........insertion at end ...............\n");
    insertAtEnd(10);
    displayList();
    insertAtEnd(20);
    displayList();
    insertAtEnd(30);
    displayList();
    insertAtEnd(40);
    displayList();

    // printf("...............deleting from first.......................\n");
    // displayList();
    // deletionFromBeg();
    // displayList();
    // deletionFromBeg();
    // displayList();
    // deletionFromBeg();
    // displayList();
    // deletionFromBeg();
    // displayList();

    printf("................deleting from End.........................\n");
    displayList();
    deletionFromEnd();
    displayList();
    deletionFromEnd();
    displayList();
    deletionFromEnd();
    displayList();
    deletionFromEnd();
    displayList();
    deletionFromEnd();
    displayList();
}
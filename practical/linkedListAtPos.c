

#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last;
int count = 0;

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
        count++;
        printf("%d was inserted at the front\n", element);
    }
}

void insertAtPos(struct SLL **first, int element)
{
    int i = 1;
    int pos;
    printf("Enter the position to be inserted: ");
    scanf("%d", &pos);
    struct SLL *newNode;
    struct SLL *temp = *first;
    newNode = (struct SLL *)malloc(sizeof(struct SLL));
    if (newNode == NULL)
    {
        printf("Memory not allocated \n");
    }
    else
    {

        if (*first == NULL)
        {
            *first = last = newNode;
        }
        else
        {
            if (pos > count)
            {
                printf("invalid position\n");
            }
            else
            {
                temp = *first;
                while (i < pos)
                {
                    temp = temp->next;
                    i++;
                }
                newNode->data = element;
                newNode->next = temp->next;
                temp->next = newNode;
                count++;
            }
            printf("%d was inserted at the %d position in list\n", element, pos);
        }
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

void deletionFromPos()
{
    int i = 1;
    int pos;
    printf("\nEnter the position to delete an element: ");
    scanf("%d", &pos);
    if (pos > count || pos < 1)
    {
        printf("Invalid Position!\n");
    }
    else
    {
        struct SLL *nextNode;
        struct SLL *temp = first;
        if (first == NULL)
        {
            printf("Empty list cannot be deleted");
        }
        else if (first->next == NULL)
        {
            first = last = NULL;
        }
        else
        {
            while (i < pos - 1)
            {
                temp = temp->next;
                i++;
            }
            nextNode = temp->next;
            temp->next = nextNode->next;
            free(nextNode);
            count--;
        }
    }
}

int main()
{
    first = NULL;
    last = NULL;
    insertAtFront(10);
    displayList();
    insertAtFront(20);
    displayList();
    insertAtFront(30);
    displayList();
    insertAtFront(40);
    displayList();
    insertAtFront(50);
    displayList();
    printf("total count before insertion is %d\n", count);
    insertAtPos(&first, 15);
    displayList();
    printf("total count after insertion is %d\n", count);

    deletionFromPos();
    displayList();
    printf("total count after deletion is %d\n", count);
}
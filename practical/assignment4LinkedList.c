#include <stdio.h>
#include <stdlib.h>

struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first, *last;
int count = 0;

/* ---------- inserting element at front -------*/
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

/* ------------- inserting element from end -------------*/
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
        count++;
        printf("%d was inserted at the end\n", element);
    }
}

/* ---------- inserting element at specific position ------- */
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

/* ------------ deleting element from front ---------- */
void deletionfromFront()
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
        count--;
    }
}

/* ----------- deleting element from end -------- */
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
        count--;
    }
}

/* -------- deleting elemnt from specific position -------- */

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

/* ------------ display list ------------- */
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

int main()
{

    first = NULL;
    last = NULL;
    int choice;
    do
    {
        printf("\n1. Insert element at front");
        printf("\t2. Insert element at end");
        printf("\t3. Insert element at position");
        printf("\n4. Delete element from front");
        printf("\n5. Delete element from end");
        printf("\n6. Delete element from position");
        printf("\n7. Display Element");
        printf("\n8. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertAtFront(10);
            printf("Total length of list is: %d\n", count);
            break;
        case 2:
            insertAtEnd(20);
            printf("Total length of list is: %d\n", count);
            break;
        case 3:
            insertAtPos(&first, 30);
            printf("Total length of list is: %d\n", count);
            break;
        case 4:
            deletionfromFront();
            printf("Total length of list is: %d\n", count);
            break;
        case 5:
            deletionFromEnd();
            printf("Total length of list is: %d\n", count);
            break;
        case 6:
            deletionFromPos();
            printf("Total length of list is: %d\n", count);
            break;
        case 7:
            displayList();
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

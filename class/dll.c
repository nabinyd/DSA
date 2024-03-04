#include <stdio.h>
#include <stdlib.h>

struct CLL
{
    int data;
    struct CLL *next;
    struct CLL *prev;
};

struct CLL *first, *last;

void insertionAtBegining(int element)
{
    struct CLL *newNode;
    newNode = (struct CLL *)malloc(sizeof(struct CLL));
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
        printf("%d <->", first->data);
        printf("\n");
    }
}
// void insertAtEnd(int element)
// {
//     struct CLL *newNode;
//     newNode = (struct CLL *)malloc(sizeof(struct CLL));
//     if (newNode == NULL)
//     {
//     }
// }
void transverse()
{
    struct CLL *temp = first;
    // newNode =(struct CLL *)malloc(sizeof(struct CLL));
    if (first == NULL)
    {
        printf("empty");
    }
    else
    {
        while (temp->next != NULL)
        {
            printf("%d<->", temp->data);
            temp = temp->next;
        }
        printf("%d <-> \n ", temp->data);
    }
}

void deletionAtBeginig()
{
    // struct CLL *temp= first;
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else if (first->next == NULL)
    {
        printf("%d is going to be deleted", first->data);
    }
    else
    {
        struct CLL *temp = first;
        printf("%d is going to be deleted \n", first->data);
        temp = first;
        first = first->next;
        first->prev = NULL;
        free(temp);
    }
}
void deletionAtEnd()
{
    // struct CLL *temp= first;
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else if (first->next == NULL)
    {
        printf("%d is going to be deleted", first->data);
    }
    else
    {
        struct CLL *temp = last;
        printf("%d is going to be deleted from last", last->data);
        last = last->prev;
        last->next = NULL;
        free(temp);
    }
}

void search(int key)
{
    int flag = 0;
    if (first == NULL)
    {
        printf("empty list\n");
    }
    else
    {
        struct CLL *temp = first;
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
    insertionAtBegining(10);
    insertionAtBegining(20);
    insertionAtBegining(30);
    insertionAtBegining(40);
    insertionAtBegining(50);
    insertionAtBegining(60);
    transverse();
    search(20);

    // deletionAtBeginig();
    // deletionAtEnd();
    // deletionAtEnd();
}
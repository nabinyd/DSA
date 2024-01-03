// A program about implementation of queue using an array of strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define True 1
#define False 0

struct queue
{
    int FRONT;
    int REAR;
    char DATA[MAX][50];
};

int isfull(struct queue *Sq);
int isempty(struct queue *Sq);
void enqueue(struct queue *Sq, const char *element);
void dequeue(struct queue *Sq, char *element);

int main()
{
    struct queue q;
    q.FRONT = 0;
    q.REAR = -1;
    int choice;
    char element[50];

    do
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.EXIT\n");
        printf("CHOICE? ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter string to enqueue: ");
            scanf("%s", element);
            enqueue(&q, element);
            break;

        case 2:
            if (isempty(&q))
                printf("QUEUE UNDERFLOW\n");
            else
            {
                dequeue(&q, element);
                printf("The dequeued element is %s\n", element);
            }
            break;

        case 3:
            printf("BYE\n");
            break;

        default:
            printf("Enter a valid option\n");
            break;
        }
    } while (choice != 3);

    return 0;
}

int isfull(struct queue *Sq)
{
    if (Sq->REAR == MAX - 1)
        return True;
    else
        return False;
}

int isempty(struct queue *Sq)
{
    if (Sq->FRONT > Sq->REAR)
        return True;
    else
        return False;
}

void enqueue(struct queue *Sq, const char *element)
{
    if (isfull(Sq))
        printf("QUEUE OVERFLOW\n");
    else
    {
        Sq->REAR += 1;
        strcpy(Sq->DATA[Sq->REAR], element);
        printf("%s was enqueued\n", element);
    }
}

void dequeue(struct queue *Sq, char *element)
{
    strcpy(element, Sq->DATA[Sq->FRONT]);
    Sq->FRONT += 1;
}



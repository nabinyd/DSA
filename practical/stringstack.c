
// A program about implementation of stack using an array of strings

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define True 1
#define False 0

struct stack
{
    int TOS;
    char DATA[MAX][50];
};

int isfull(struct stack *ss);
int isempty(struct stack *ss);
void push(struct stack *ss, const char *element);
void pop(struct stack *ss, char *element);

int main()
{
    struct stack S;
    S.TOS = -1;
    int choice;
    char element[50];

    do
    {
        printf("1.PUSH\n2.POP\n3.EXIT\n");
        printf("CHOICE? ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%s", element);
            push(&S, element);
            break;

        case 2:
            if (isempty(&S))
                printf("STACK UNDERFLOW\n");
            else
            {
                char Element[50];
                pop(&S, Element);
                printf("The popped element is %s\n", Element);
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

int isfull(struct stack *ss)
{
    if (ss->TOS == MAX - 1)
        return True;
    else
        return False;
}

int isempty(struct stack *ss)
{
    if (ss->TOS == -1)
        return True;
    else
        return False;
}

void push(struct stack *SS, const char *element)
{
    if (isfull(SS))
        printf("STACK OVERFLOW\n");
    else
    {
        SS->TOS += 1;
        strcpy(SS->DATA[SS->TOS], element);
        printf("%s was pushed\n", element);
    }
}

void pop(struct stack *SS, char *element)
{
    strcpy(element, SS->DATA[SS->TOS]);
    SS->TOS -= 1;
}

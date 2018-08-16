#include <stdio.h>
#include <stdlib.h>

//*******************************************************************************

struct stack
{
    int data;
    struct stack *link;
};
struct stack *head = NULL;
struct stack *top;
int count = 0;

//**********************************************************************************

void push()
{
    int d;
    printf("\nEnter data: ");
    scanf("%d", &d);
    struct stack *node;
    node = (struct stack *)malloc(sizeof(struct stack));
    node->data = d;
    printf(" \n %d is pushed into the stack as top ", node->data);
    node->link = NULL;
    if (head == NULL)
    {
        head = node;
        top = node;
        count++;
    }
    else
    {
        top->link = node;
        top = node;
        count++;
    }
}

//***************************************************************************************

void pop()
{
    struct stack *temp;
    temp = head;
    if (head == NULL)
    {
        printf(" \n UNDERFLOW......... ");
    }
    else
    {
        if (top == head)
        {
            printf("\n %d is popped out of the stack ", top->data);
            free(top);
            head = NULL;
            count--;
        }
        else
        {
            printf("\n %d is popped out of the stack ", top->data);
            free(top);
            int i;
            for (i = 1; i < count - 1; i++)
            {
                temp = temp->link;
            }
            top = temp;
            temp->link = NULL;
            count--;
        }
    }
}

//**************************************************************************************************

void print(void)
{
    struct stack *temp;
    temp = head;
    printf("\n");
    while (temp != NULL)
    {
        printf(" %d --->", temp->data);
        temp = temp->link;
    }
    printf(" NULL     ");
}

//*************************************************************************************************

void size()
{
    printf("\n stack size: %d \n", count);
}

//*************************************************************************************************

main()
{
    int c;
    while (1)
    {
        puts("\n\nAvailable operations:\n1.Push\n2.Pop\n3.Print\n4.Size\n5.Exit\nEnter your choice: ");
        scanf("%d", &c);
        if (c == 1)
            push();
        else if (c == 2)
            pop();
        else if (c == 3)
            print();
        else if (c == 4)
            size();
        else
        {
            break;
            exit(1);
        }
    }
}

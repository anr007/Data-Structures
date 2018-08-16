#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *link;
};
struct queue *front = NULL;
struct queue *rear;

//**********************************************************************************

void insert()
{
    int d;
    printf("\nEnter data: ");
    scanf("%d", &d);
    struct queue *node;
    node = (struct queue *)malloc(sizeof(struct queue));
    node->data = d;
    printf("\n %d is inserted at the rear ", node->data);
    node->link = NULL;
    if (front == NULL)
    {
        front = node;
        rear = node;
    }
    else
    {
        rear->link = node;
        rear = node;
    }
}

//**********************************************************************************

void delete (void)
{
    struct queue *temp;
    if (front == NULL)
    {
        printf("\n UNDERFLOW....... ");
    }
    else
    {
        printf("\n %d is deleted from the front ", front->data);
        temp = front->link;
        free(front);
        front = temp;
    }
}

//**********************************************************************************

void print(void)
{
    struct queue *temp;
    temp = front;
    printf("\n");
    while (temp != NULL)
    {
        printf(" %d --->", temp->data);
        temp = temp->link;
    }
    printf(" NULL ");
}

//**********************************************************************************

void search()
{
    int s;
    printf("Enter item value: ");
    scanf("%d", &s);
    if (front == NULL)
        printf("\n UNDERFLOW....... ");
    else
    {
        struct queue *temp;
        temp = front;
        int y = 0, f = 1;
        while (temp != NULL)
        {
            if (temp->data == s)
            {
                printf("\n %d is found in the queue ", temp->data);
                f = 0;
            }
            temp = temp->link;
            y++;
        }
        if (f)
            printf("\n %d is not found in the queue ", s);
    }
}

//**********************************************************************************

main()
{
    int c;
    while (1)
    {
        puts("\n\nAvailable operations:\n1.Enqueue\n2.Dequeue\n3.Print\n4.Search\n5.Exit\nEnter your choice: ");
        scanf("%d", &c);
        if (c == 1)
            insert();
        else if (c == 2)
            delete ();
        else if (c == 3)
            print();
        else if (c == 4)
            search();
        else
        {
            break;
            exit(1);
        }
    }
}

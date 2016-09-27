#include<stdio.h>
#include<stdlib.h>

//*******************************************************************************

struct stack{
int data;
struct stack * link;
};
struct stack *head=NULL;
struct stack *top;

//**********************************************************************************

void push(int d)
{
struct stack *node;
node=(struct stack *)malloc(sizeof(struct stack));
node->data=d;
printf(" \n %d is pushed into the stack as top ",node->data);
node->link=NULL;
if(head==NULL)
{
head=node;
top=node;
}
else
{
top->link=node;
top=node;
}
}

//***************************************************************************************

void pop(void)
{
struct stack * temp;
temp=head;
if(head==NULL)
{
printf(" \n UNDERFLOW......... ");
}
else
{
if(top==head)
{
printf("\n %d is popped out of the stack ",top->data);
free(top);
head=NULL;
}
else
{
printf("\n %d is popped out of the stack ",top->data);

while (temp->link !=top)
{
temp=temp->link;
}

temp->link=NULL;
free(top);
top=temp;
}
}
}

//**************************************************************************************************

void print(void)
{
struct stack* temp;
temp =head;
printf("\n");
while(temp!= NULL)
{
printf(" %d --->",temp->data);
temp=temp->link;
}
printf(" NULL     ");
}

//*************************************************************************

main()
{
push(21);
push(22);
push(23);
print();
pop();
print();
pop();
print();
pop();
print();
pop();
push(24);
push(25);
push(26);
print();
}

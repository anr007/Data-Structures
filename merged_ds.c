#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//***************************** linkedlist ******************************************************
struct list{
int data;
struct list * link;
};
struct list * head=NULL;
struct list * current;
int count=0;

void insert_ll()
{
struct list *node;
int d;
node=(struct list *)malloc(sizeof(struct list));
printf("\nEnter data: ");
scanf("%d", &d);
node->data=d;
printf("%d is inserted in the list ",node->data);
node->link=NULL;
if(head==NULL)
{
head=node;
current=node;
count++;
}
else
{
current->link=node;
current=node;
count++;
}
}

void insert_at()
{
struct list *temp;
struct list *node;
temp=head;
int d,loc,t;
t=0;
node=(struct list *)malloc(sizeof(struct list));

printf("\nEnter data: ");
scanf("%d", &d);
printf("Enter location: ");
scanf("%d", &loc);
node->data=d;
node->link=NULL;

if(loc==1 && count!=0)
{
node->link=head; // copying the location present in the head to the node->link
head=node;	 // now assigning the loc of node to head
printf("%d is inserted in the list in the location:%d ",node->data,loc);
count++;
}
else if(loc>1 && loc<=count)
{
while(temp!=NULL) // relocating the temp var. to the req. location
{
if(t!=loc-1)	  // here loc-1 as 't' is started from 0
{
temp=temp->link;
t++;
}
else
break;
}
node->link=temp->link;   // copying the loc of nxt. node to the newley created node
temp->link=node;	// copying the location of newly created node to its previous node
printf("%d is inserted in the list in the location:%d ",node->data,loc);
count++;
}
else
printf("loc:%d is not present or not yet created",loc);
}

void delete_ll()
{
struct list *temp;
struct list *node;
temp=head;
int loc;
printf("Enter location: ");
scanf("%d", &loc);
int t=0;

if(loc==1 && count!=0)
{
node=head;		
printf("%d is deleted from the list from the location:%d ",node->data,loc);
free(head);
node=node->link;	// copying the location present in the 1st node to the node->link
head=node;		// assigning the location present in 1st node->link  to head
count--;
}
else if(loc>1 && loc<=count)
{
while(temp!=NULL)	// relocating the temp var. to the req. location ie.location of deletion
{
if(t!=loc-1)		// as t starts from 0
{
temp=temp->link;
t++;
}
else
break;
}
node=temp->link;	//copying the loc. present in the link of node going to be deleted
printf("%d is deleted in the list from the location:%d ",temp->data,loc);
free(temp);
temp=head;
t=0;
while(temp!=NULL)	// relocating the temp var. to the req. location ie.location left to deletion loc
{
if(t!=loc-2)
{
temp=temp->link;
t++;
}
else
break;
}
temp->link=node;	//assigning the address present in deleted node->link to its left side(previous) node->link
count--;
}
else
printf("loc:%d is not present or not yet created",loc);
}

//********************************************** Queue ******************************************************************

struct queue{
int data;
struct queue * link;
};
struct queue * rear;
struct queue * front=NULL;

void insert_q()
{
struct queue * node;
int d;
node=(struct queue *)malloc(sizeof(struct queue));
printf("\nEnter any data: ");
scanf("%d",&d);
node->data=d;
printf("%d is enqueued",node->data);
if(front==NULL)
{
front=node;
rear=node;
}else 
{
rear->link=node;
rear=node;
}
}

void delete_q() {
 struct queue * temp;
  if(front==NULL)
   {
   		printf("\n UNDERFLOW....... ");
   } else
   {
     	printf("\n %d is deleted from the front ",front->data);
      	temp=front->link;
       	free(front);
        front=temp;
    }
}

//**************************************************** stack ****************************************************
struct stack{
int data;
struct stack * link;
};
struct stack *top;
struct stack *bottom=NULL;

void insert_s()
{
	struct stack * node;
	int d;
	node=(struct stack *)malloc(sizeof(struct stack));
	printf("\nEnter any data: ");
	scanf("%d",&d);
	node->data=d;
	printf("%d is pushed",node->data);
	if(bottom==NULL)
	{
		bottom=node;
		top=node;
	}else
	{
		top->link=node;
		top=node;
	}


}

void delete_s()
{
	struct stack * temp;
	temp=top;
if(temp==NULL)
{
printf(" \n UNDERFLOW......... ");
}else if(top==bottom)
{
	top=NULL;
	bottom=NULL;
}
else
{
	printf("\n %d is popped ",temp->data);
      	struct stack * temp2;
      	temp2=bottom;
      	while(temp2->link!=temp)
      	{
      		temp2=temp2->link;
      	}
      	temp2->link=NULL;
      	free(top);
      	top=temp2;
}
}

//**************************************************** display ******************************************************

void print(char t)
{
	if(t=='s')
	{
		if(bottom==NULL)
		{
			printf("The Stack is Empty");
		}else{
			struct stack * temp;
		temp = bottom;

		printf("\nThe Stack is printed from the bottom\n");
		while(temp!=NULL)
		{
			printf("%d",temp->data);
			temp=temp->link;
			if(temp!=NULL)
				printf(" --> ");
		}
		}
		
	}else if(t=='l')
	{
		struct list* temp;
		temp =head;
		printf("\n");
		while(temp!= NULL)
		{
			printf(" %d --->",temp->data);
			temp=temp->link;
		}
		printf(" NULL  \n");

	}else if(t=='q')
	{
		
		struct queue* temp;
		temp =front;
		printf("\n");
		while(temp!= NULL)
		{
			printf(" %d --->",temp->data);
			temp=temp->link;
		}
		printf(" NULL  \n");
	}

}

//********************************************************** main *********************************************


main(int argc, char *argv[])
{
	if(strcmp(argv[1],"stack")==0)
	{
	int c;
	while(1)
	{
	puts("\n\nEnter your choice:\n1.Push\n2.Display\n3.Pop");
	scanf("%d", &c);
	if(c==1)
		insert_s();
	else if(c==2)
		print('s');
	else if(c==3)
		delete_s();
	else
	{
	break;
	exit(1);
	}
	}
		
	}else if(strcmp(argv[1],"linked_list")==0)
	{
		int c;
	while(1)
	{
	puts("\n\nEnter your choice:\n1.Insert\n2.Display\n3.Insert at particlar position\n4.Delete");
	scanf("%d", &c);
	if(c==1)
		insert_ll();
	else if(c==2)
		print('l');
	else if(c==3)
		insert_at();
	else if(c==4)
		delete_ll();
	else
	{
	break;
	exit(1);
	}
	}
		
	}else if(strcmp(argv[1],"queue")==0)
	{
		int c;
	while(1)
	{
	puts("\n\nEnter your choice:\n1.Enqueue\n2.Display\n3.Dequeue");
	scanf("%d", &c);
	if(c==1)
		insert_q();
	else if(c==2)
		print('q');
	else if(c==3)
		delete_q();
	else
	{
	break;
	exit(1);
	}
	}
	}
}

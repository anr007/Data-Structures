#include <stdio.h>
#include <stdlib.h>

struct list{
int data;
struct list * plink;
struct list * nlink;
};
struct list * head=NULL;
struct list * current;
int count=0;

//*******************************************************

void insert()
{
struct list *node;
int d;
node=(struct list *)malloc(sizeof(struct list));
printf("\nEnter data: ");
if(scanf("%d", &d)!=1)
{
printf("Error");
return;
}

__fpurge(stdin);
node->data=d;
printf("%d is inserted in the list ",node->data);
node->nlink=NULL;
node->plink=current;


if(head==NULL)
{
node->plink=NULL;
head=node;
current=node;
count++;
}
else
{
current->nlink=node;
current=node;
count++;
}
}

//************************************************************

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
node->nlink=NULL;

if(loc==1 && count!=0)
{
node->nlink=head; // copying the location present in the head to the node->nlink
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
temp=temp->nlink;
t++;
}
else
break;
}
node->nlink=temp->nlink;   // copying the loc of nxt. node to the newley created node
temp->nlink=node;	// copying the location of newly created node to its previous node
printf("%d is inserted in the list in the location:%d ",node->data,loc);
count++;
}
else
printf("loc:%d is not present or not yet created",loc);
}

//********************************************************************************

void print(void)
{
struct list* temp;
temp =head;
printf("\n");
while(temp!= NULL)
{
printf(" %d --->",temp->data);
temp=temp->nlink;
}
printf(" NULL     ");
temp =head;
while(temp!= NULL)
{
printf(" %d ###### %d --->",temp->plink,temp->nlink);
temp=temp->nlink;
}

printf(" NULL     ");
}

//********************************************************************************

void delete()
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
node=node->nlink;	// copying the location present in the 1st node to the node->nlink
head=node;		// assigning the location present in 1st node->nlink  to head
count--;
}
else if(loc>1 && loc<=count)
{
while(temp!=NULL)	// relocating the temp var. to the req. location ie.location of deletion
{
if(t!=loc-1)		// as t starts from 0
{
temp=temp->nlink;
t++;
}
else
break;
}
node=temp->nlink;	//copying the loc. present in the nlink of node going to be deleted
printf("%d is deleted in the list from the location:%d ",temp->data,loc);
free(temp);
temp=head;
t=0;
while(temp!=NULL)	// relocating the temp var. to the req. location ie.location left to deletion loc
{
if(t!=loc-2)
{
temp=temp->nlink;
t++;
}
else
break;
}
temp->nlink=node;	//assigning the address present in deleted node->nlink to its left side(previous) node->nlink
count--;
}
else
printf("loc:%d is not present or not yet created",loc);
}

//*************************************************************************************

void search()
{
int s;
printf("Enter item value: ");
scanf("%d",&s);
if(head==NULL)
printf("\n UNDERFLOW....... ");
else
{
struct list * temp;
temp=head;
int y=1;
while(temp!=NULL)
{
if(temp->data==s)
{
printf("\n %d is found in the list ",temp->data);
y=0;
}
temp=temp->nlink;
}
if(y)
printf("\n %d is not found in the list ",s);
}
}

//***************************************************************************************


void traverse(void)
{

if(head==NULL)
printf("\n UNDERFLOW....... ");
else
{
struct list * temp;
temp=head;
int s=0;
while(temp!=NULL)
{
s+=temp->data;
temp=temp->nlink;
}
printf("\nTraversing is generally executing a given process visitng once a node ");
printf("\nHere it is printing the sum of all the data stored in the list & it is \"%d\"",s);
}
}


//***************************************************************************************

main()
{
int c;
while(1)
{
__fpurge(stdin);
printf("\n\nAvailable choices:\n1.Normal Insertion\n2.Insert at particlar position\n3.Print\n4.Delete\n5.Search\n6.Traversing\n7.Exit");
printf("\nEnter your choice: ");
scanf("%d", &c);

switch(c)
{
case 1:
	insert();
	break;
case 2:
	insert_at();
	break;
case 3:
	print();
	break;
case 4:
	delete();
	break;
case 5:
	search();
	break;
case 6:
	traverse();
	break;
case 7:
	exit(0);
	break;
default:
	printf("\n	INPUT ERROR.......\n	TRY AGAIN.........\n");
	break;
}
}
}





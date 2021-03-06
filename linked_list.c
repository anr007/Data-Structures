#include <stdio.h>
#include <stdlib.h>

struct list
{
	int data;
	struct list *link;
};
struct list *head = NULL;
struct list *current;
int count = 0;

//*******************************************************

void insert()
{
	struct list *node;
	int d;
	node = (struct list *)malloc(sizeof(struct list));
	printf("\nEnter data: ");
	scanf("%d", &d);
	node->data = d;
	printf("%d is inserted in the list ", node->data);
	node->link = NULL;
	if (head == NULL)
	{
		head = node;
		current = node;
		count++;
	}
	else
	{
		current->link = node;
		current = node;
		count++;
	}
}

//************************************************************

void insert_at()
{
	struct list *temp;
	struct list *node;
	temp = head;
	int d, loc, t;
	t = 0;
	node = (struct list *)malloc(sizeof(struct list));

	printf("\nEnter data: ");
	scanf("%d", &d);
	printf("Enter location: ");
	scanf("%d", &loc);
	node->data = d;
	node->link = NULL;

	if (loc == 1 && count != 0)
	{
		node->link = head; // copying the location present in the head to the node->link
		head = node;	   // now assigning the loc of node to head
		printf("%d is inserted in the list in the location:%d ", node->data, loc);
		count++;
	}
	else if (loc > 1 && loc <= count)
	{
		while (temp != NULL) // relocating the temp var. to the req. location
		{
			if (t != loc - 1) // here loc-1 as 't' is started from 0
			{
				temp = temp->link;
				t++;
			}
			else
				break;
		}
		node->link = temp->link; // copying the loc of nxt. node to the newley created node
		temp->link = node;		 // copying the location of newly created node to its previous node
		printf("%d is inserted in the list in the location:%d ", node->data, loc);
		count++;
	}
	else
		printf("loc:%d is not present or not yet created", loc);
}

//********************************************************************************

void print(void)
{
	struct list *temp;
	temp = head;
	printf("\n");
	while (temp != NULL)
	{
		printf(" %d --->", temp->data);
		temp = temp->link;
	}
	printf(" NULL     ");
}

//********************************************************************************

void delete ()
{
	struct list *temp;
	struct list *node;
	temp = head;
	int loc;
	printf("Enter location: ");
	scanf("%d", &loc);
	int t = 0;

	if (loc == 1 && count != 0)
	{
		node = head;
		printf("%d is deleted from the list from the location:%d ", node->data, loc);
		free(head);
		node = node->link; // copying the location present in the 1st node to the node->link
		head = node;	   // assigning the location present in 1st node->link  to head
		count--;
	}
	else if (loc > 1 && loc <= count)
	{
		while (temp != NULL) // relocating the temp var. to the req. location ie.location of deletion
		{
			if (t != loc - 1) // as t starts from 0
			{
				temp = temp->link;
				t++;
			}
			else
				break;
		}
		node = temp->link; //copying the loc. present in the link of node going to be deleted
		printf("%d is deleted in the list from the location:%d ", temp->data, loc);
		free(temp);
		temp = head;
		t = 0;
		while (temp != NULL) // relocating the temp var. to the req. location ie.location left to deletion loc
		{
			if (t != loc - 2)
			{
				temp = temp->link;
				t++;
			}
			else
				break;
		}
		temp->link = node; //assigning the address present in deleted node->link to its left side(previous) node->link
		count--;
	}
	else
		printf("loc:%d is not present or not yet created", loc);
}

//*************************************************************************************

void search()
{
	int s;
	printf("Enter item value: ");
	scanf("%d", &s);
	if (head == NULL)
		printf("\n UNDERFLOW....... ");
	else
	{
		struct list *temp;
		temp = head;
		int y = 0, f = 0;
		while (temp != NULL)
		{
			if (temp->data == s)
			{
				printf("\n %d is found in the list at position %d ", temp->data, y);
				f = 1;
			}
			temp = temp->link;
			y++;
		}
		if (!f)
			printf("\n %d is not found in the list ", s);
	}
}

//***************************************************************************************

void traverse(void)
{

	if (head == NULL)
		printf("\n UNDERFLOW....... ");
	else
	{
		struct list *temp;
		temp = head;
		int s = 0;
		while (temp != NULL)
		{
			s += temp->data;
			temp = temp->link;
		}
		printf("\nTraversing is generally executing a given process visitng once a node ");
		printf("\nHere it is printing the sum of all the data stored in the list & it is \"%d\"", s);
	}
}

//***************************************************************************************

main()
{
	int c;
	while (1)
	{
		puts("\n\nAvailable operations:\n1.Normal Insertion\n2.Insert at particlar position\n3.Print\n4.Delete\n5.Search\n6.Traversing\n7.Exit\nEnter your choice: ");
		scanf("%d", &c);
		if (c == 1)
			insert();
		else if (c == 2)
			insert_at();
		else if (c == 3)
			print();
		else if (c == 4)
			delete ();
		else if (c == 5)
			search();
		else if (c == 6)
			traverse();
		else
		{
			break;
			exit(1);
		}
	}
}

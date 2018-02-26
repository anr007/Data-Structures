/* 
insertion takes place at the rear
deletion takes place at the front

insertion in circular queue has 2 cases. they are as follows :
1. if the rear is < MAX-1 , we can do rear++ and insert the item in queue[rear].
2. if the rear is = MAX-1 , we should set the value to rear=0 and continue queue[rear].

deletion in circular queue has 3 cases. they are as follows :
1. if the front is equal to rear ,then the queue has only one element. so, after deleting the element the values of front and rear should be reset ie. front=-1,rear=-1
2. if the front is < MAX-1 , we can delete the item in queue[front] and do front++ .
3. if the front is = MAX-1 , we should set the value to front=0 and continue queue[rear].

*/


#include<stdio.h>
#define MAX 6

int queue[MAX];
int front=-1,rear=-1;   /* front = -1, rear = -1 is just for helpful identification when queue is empty, if we start from front = 0 , rear = 0 we should think of other ways to represent OVERFLOW , UNDERFLOW conditions... */

void insert(int d)
{
if((front==rear+1)||(front==0 && rear==MAX-1))   /* front==rear+1 is for cicular nature of queue   and  front==0&&rear==MAX-1  is for normal queue   */
{
printf("\n OVERFLOW....");
}
else
{
if(front==-1)
front=0;
rear=(rear+1)%MAX;

/*
Meaning of the above step is 

if(rear=MAX-1) here MAX-1 not MAX as rear is starting from -1 
rear=0;
else
rear++; 
*/

queue[rear]=d;
printf("\n %d is inserted ",queue[rear]);
}
}

void delete()
{
if(front==-1)
printf("\n UNDERFLOW.....");
else
{
printf("\n %d is deleted ",queue[front]);
queue[front]=0;
if(front==rear)   /* only one element is present in the queue so resetting default values */
{
front=-1;
rear=-1;
}
else
front=(front+1)%MAX;
/*
Meaning of the above step is 

if(front=MAX-1)  here MAX-1 not MAX as front is starting from -1 
front=0;
else
front++;
*/

}
}
main()
{
delete();
insert(1);
insert(2);
delete();
insert(3);
insert(4);
insert(5);
insert(6);
insert(1);
insert(7);


int i;
for(i=0;i<MAX;i++)
{
printf("\n%d ",queue[i]);
}
}

#include<stdio.h>
main()
{
int max_size,i,j;
printf("enter the no of items ");
scanf("%d",&max_size);
int a[max_size];

for(i=0;i<max_size;i++)
{
	printf("enter the item:%d \n",i+1);
	scanf("%d",&a[i]);
}
int swap;
for(i=0;i<(max_size-1);i++)
{
	for(j=0;j<(max_size-i-1);j++)
	{
		if(a[j]>a[j+1])
		{
			swap=a[j];
			a[j]=a[j+1];
			a[j+1]=swap;
		}
	}
}
printf("\n");

for(i=0;i<max_size;i++)
printf("%d\n",a[i]);

}




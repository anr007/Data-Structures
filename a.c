#include<stdio.h>
main()
{
int max_size,i,j;

printf("enter the no of items ");
scanf("%d",&max_size);
float a[max_size],swap;

for(i=0;i<max_size;i++)
{

	printf("enter the item:%d \n",i+1);
	scanf("%f",&a[i]);

	for(j=0;j<i;j++)
	{
		if(a[i]<a[j])
		{
			swap=a[i];
			a[i]=a[j];
			a[j]=swap;
		}

	}

}


printf("\n");

for(i=0;i<max_size;i++)
printf("%f\n",a[i]);

}




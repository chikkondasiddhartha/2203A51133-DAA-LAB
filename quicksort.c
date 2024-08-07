#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int a[],int low,int high)
{
	int j,pivot=a[high],i=low-1;
	for(j=low;j<high;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(&a[i],&a[j]);
		}
	}
	swap(&a[i+1],&a[high]);
	return i+1;
}
void quickSort(int a[],int low,int high)
{
	if(low<high)
	{
		int pivIndex=partition(a,low,high);
		quickSort(a,low,pivIndex-1);
		quickSort(a,pivIndex+1,high);
	}
}
int main()
{
	int a[10],i,n,low,high;
	printf("Enter size");
	scanf("%d",&n);
	printf("Enter elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	quickSort(a,0,n-1);
	printf("\nSorted Array:\n ");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
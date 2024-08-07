#include <stdio.h>
#include <stdlib.h> 
void ascending(int arr[], int n) 
{
    int i, j, key;
    for (i = 1; i <n ; i++) 
	{
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j]>key)
		{
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
void descending(int arr[], int n) 
{
    int i, j, key;
    for (i=1;i<n;i++) 
	{
        key = arr[i];
        j = i - 1;
        while (j>=0 && arr[j]<key)
		{
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main() 
{
    int *a;
    int i,n;
    char choice;
    printf("Enter size: ");
    scanf("%d", &n);
    a=(int*)malloc(n*sizeof(int));
    printf("Enter elements:\n");
    for (i=0;i<n;i++) 
	{
        scanf("%d",&a[i]);
    }
    printf("Select a/d for sorting: ");
    scanf(" %c",&choice);
    if (choice == 'a') 
	{
        ascending(a,n);
    } 
	else 
	{
        descending(a,n);
    } 
    printf("Sorted times:\n");
    for (i=0;i<n;i++)
	{
        printf("%d\n",a[i]);
    }
    free(a); 
    return 0;
}
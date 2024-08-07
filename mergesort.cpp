#include <stdio.h>
#include <stdlib.h>
void merge(int* arr, int low, int mid, int high, int order)
 {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0; 
    j = 0; 
    k = low; 
    while (i < n1 && j < n2)
	 {
        if (order == 0) 
		{
            if (L[i] <= R[j]) 
			{
                arr[k] = L[i];
                i++;
            }
			else 
			{
                arr[k] = R[j];
                j++;
            }
        } 
		else 
		{ 
            if (L[i] >= R[j]) 
			{
                arr[k] = L[i];
                i++;
            }
			 else 
			{
                arr[k] = R[j];
                j++;
            }
        }
        k++;
    }
    while (i < n1) 
	{
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
	{
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}
void mergeSort(int* arr, int low, int high, int order) 
{
    if (low < high) 
	{
        int mid = low + (high - low) / 2;
        mergeSort(arr, low, mid, order);
        mergeSort(arr, mid + 1, high, order);
        merge(arr, low, mid, high, order);
    }
}
int main() 
{
    int n, order;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &arr[i]);
    }
    printf("Enter 0 for ascending order and 1 for descending order: ");
    scanf("%d", &order);
    mergeSort(arr, 0, n - 1, order);
    printf("\nSorted array is: \n");
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

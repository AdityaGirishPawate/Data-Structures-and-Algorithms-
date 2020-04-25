//Rselect Algo using quicksort
#include<stdio.h>
#include<stdlib.h>

int kthSmallest(int arr[], int l, int r, int k);
void swap(int* a, int* b);
int partition(int arr[], int l, int r);

int main() 
{ 
	int arr[30]; 
	int n; 
	int k,i;
	printf("Enter the number of elements in the array and the value for k \n");
	scanf("%d %d",&n,&k);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)	
		scanf("%d",arr+i);
 
	printf("K-th Largest element is %d \n",kthLargest(arr, 0, n - 1, k));
 
	return 0; 
}

int partition(int arr[], int l, int r) 
{ 
	int j;
	int x = arr[r], i = l; 
	for (j = l; j <= r - 1; j++)
		{ 
			if (arr[j] >= x)
			{ 
				swap(&arr[i], &arr[j]); 
				i++; 
			} 
		} 
	swap(&arr[i], &arr[r]); 
	return i; 
} 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

int kthLargest(int arr[], int l, int r, int k) 
{ 
	if (k > 0 && k <= r - l + 1) { 

		int index = partition(arr, l, r); 

		if (index - l == k - 1) 
			return arr[index]; 


		if (index - l > k - 1) 
			return kthLargest(arr, l, index - 1, k); 
 
		return kthLargest(arr, index + 1, r, 
							k - index + l - 1); 
	} 
 
	return -1; 
} 





















 


//Quicksort
#include<stdio.h>
#include<stdlib.h>

  
int partition (int arr[], int low, int high);
void swap(int* a, int* b); 
void quickSort(int arr[], int low, int high); 
void printArray(int arr[], int size);

int main() 
{ 
    int arr[30]; 
    int n,i; 
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)	
		scanf("%d",arr+i);
    quickSort(arr, 0, n-1); 
    printf("Sorted array: \n"); 
    printArray(arr, n); 
    return 0; 
}


void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  

int partition (int arr[], int low, int high) 
{ 
	int j;
    int pivot = arr[high];     
    int i = (low - 1);  
    for (j = low; j <= high- 1; j++) 
    {  
        if (arr[j] <= pivot) 
        { 
            i++;    
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 

} 
  

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 

        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
  

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 




















 



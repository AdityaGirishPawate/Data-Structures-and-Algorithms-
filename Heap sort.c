//heapsort
#include<stdio.h>
#include<stdlib.h>
  

void printArray(int arr[], int n);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
void swap(int* a, int* b);


int main() 
{ 
    int arr[30]; 
    int n,i; 
	printf("Enter the number of elements in the array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)	
		scanf("%d",arr+i);

    heapSort(arr, n); 
  
    printf("Sorted array is \n"); 
    printArray(arr, n); 
} 

void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;  
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
   
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    
    if (largest != i) 
    { 
        swap(&arr[i],&arr[largest]); 
  
        
        heapify(arr, n, largest); 
    } 
} 
  

void heapSort(int arr[], int n) 
{ 
    int i;
    for (i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
 
    for (i=n-1; i>=0; i--) 
    { 
      
        swap(&arr[0],&arr[i]); 
  
       
        heapify(arr, i, 0); 
    } 
} 
  

void printArray(int arr[], int n) 
{ 
	int i;
    for (i=0; i<n; ++i) 
        printf("%d ",arr[i]); 
    printf("\n"); 
} 

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  













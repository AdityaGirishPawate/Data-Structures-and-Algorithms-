#include<stdio.h>
#include<stdlib.h>

int partition(int arr[], int l, int r, int k); 
int findMedian(int arr[], int n) ;
int kthSmallest3(int arr[], int l, int r, int k) ;
int kthSmallest5(int arr[], int l, int r, int k) ;
int kthSmallest7(int arr[], int l, int r, int k) ;
void swap(int *a, int *b) ;
void Sort(int arr[], int n) ;
int partition(int arr[], int l, int r, int x) ;


int main() 
{ 
	int k,n,g,i;
    printf("Enter the number of elements, value for k and value for g\n");
	scanf("%d %d",&n,&k);
	printf("Enter the elements of array\n");
	
	int* arr=(int *)malloc(sizeof(int)*n);
	 
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("The kth smallest element using 3 groups is:%d\n", kthSmallest3(arr,0,n-1,k));
	printf("The kth smallest element using 5 groups is:%d\n", kthSmallest5(arr,0,n-1,k));
	printf("The kth smallest element using 7 groups is:%d\n", kthSmallest7(arr,0,n-1,k));
 
    return 0; 
} 
  
 
int findMedian(int arr[], int n) 
{ 
    Sort(arr, n); 
    return arr[n/2];  
} 
  

int kthSmallest5(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
  
        // Divide arr[] in groups of size 5, calculate median 
        // of every group and store it in median[] array. 
        int i, median[(n+4)/5]; // There will be floor((n+4)/5) groups; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) //For last group with less than 5 elements 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        // Find median of all medians using recursive call. 
        // If median[] has only one element, then no need 
        // of recursive call 
        int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest5(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest5(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest5(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return 9999; 
} 


int kthSmallest7(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
  
        // Divide arr[] in groups of size 7, calculate median 
        // of every group and store it in median[] array. 
        int i, median[(n+6)/7]; // There will be floor((n+6)/7) groups; 
        for (i=0; i<n/7; i++) 
            median[i] = findMedian(arr+l+i*7, 7); 
        if (i*7 < n) //For last group with less than 7 elements 
        { 
            median[i] = findMedian(arr+l+i*7, n%7);  
            i++; 
        }     
  
        // Find median of all medians using recursive call. 
        // If median[] has only one element, then no need 
        // of recursive call 
        int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest7(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest7(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest7(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return 9999; 
} 
  
int kthSmallest3(int arr[], int l, int r, int k) 
{ 
    // If k is smaller than number of elements in array 
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; // Number of elements in arr[l..r] 
  
        // Divide arr[] in groups of size 3, calculate median 
        // of every group and store it in median[] array. 
        int i, median[(n+2)/3]; // There will be floor((n+2)/3) groups; 
        for (i=0; i<n/3; i++) 
            median[i] = findMedian(arr+l+i*3, 3); 
        if (i*3 < n) //For last group with less than 3 elements 
        { 
            median[i] = findMedian(arr+l+i*3, n%3);  
            i++; 
        }     
  
        // Find median of all medians using recursive call. 
        // If median[] has only one element, then no need 
        // of recursive call 
        int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest3(median, 0, i-1, i/2); 
  
        // Partition the array around a random element and 
        // get position of pivot element in sorted array 
        int pos = partition(arr, l, r, medOfMed); 
  
        // If position is same as k 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  // If position is more, recur for left 
            return kthSmallest3(arr, l, pos-1, k); 
  
        // Else recur for right subarray 
        return kthSmallest3(arr, pos+1, r, k-pos+l-1); 
    } 
  
    // If k is more than number of elements in array 
    return 9999; 
} 
void swap(int *a, int *b) 
{ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void Sort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    
    for (i = 0; i < n-1; i++) 
    { 
        
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
  
 
int partition(int arr[], int l, int r, int x) 
{ 
    
    int i,j; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
   
    i = l; 
    for (j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
  




#include<stdio.h>

int number=0;


void mergeSort(int arr[], int l, int r);
int insertion(int a[],int n);
void merge(int arr[], int l, int m, int r);
	

int main()
{
	int n,i,temp,a[30],b[30];
	printf("Enter the number of terms in an array\n");
	scanf("%d",&n);
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("The elements before sorting are:\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("\n");
	temp=insertion(a,n);
	printf("The elements after sorting are:\n");
	for(i=0;i<n;i++)
		printf("%d  ",a[i]);
	printf("The runtime of insertion %d\n",temp);

	
	printf("Enter the number of terms in an array for merge sort\n");
	scanf("%d",&n);
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	printf("The elements before sorting are:\n");
	for(i=0;i<n;i++)
		printf("%d  ",b[i]);
	printf("\n");
	mergeSort(b,0,n-1);
	printf("The elements after sorting are:\n");
	for(i=0;i<n;i++)
		printf("%d  ",b[i]);
	printf("The runtime of merge sort %d\n",number);


	
	
	return 0;
}

/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 



//Insertion sort algorithm
int insertion(int a[],int n)
{
	int i,j,temp,key;
	temp=0;
	for(j=1;j<n;j++)
	{
		key=a[j];
		for(i=j-1;i>=0&&key<a[i];i--)
		{
			a[i+1]=a[i];
			a[i]=key;
			temp++;
		}
	}
}

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
	number++;
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
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 	
	number++;
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
	number++;
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 










insertion-selection.c
Displaying insertion-selection.c.

#include<stdio.h>
#include<stdlib.h>

void radixsort(int arr[], int n) ;
void countSort(int arr[], int n, int exp);
int getMax(int arr[], int n);

int main()
 {
        int i,k,n;
        printf("Enter the number of elements \n");
	scanf("%d",&n);
	int* arr=(int *)malloc(sizeof(int)*n);
	printf("Enter the elements of array\n");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	

        radixsort(arr, n);

        printf("The sorted elements are:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);	
	

        return 0;

    }        
int getMax(int arr[], int n) {
        int mx = arr[0];
        int i;
        for (i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }
void countSort(int arr[], int n, int exp) 
    {
        int output[n];
        int i, count[10] = { 0 };    
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
        for (i = n - 1; i >= 0; i--) 
        {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }   
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }
void radixsort(int arr[], int n) 
{
        int m = getMax(arr, n);  
        int exp;
        for (exp = 1; m / exp > 0; exp *= 10)
            countSort(arr, n, exp);
}


     

   

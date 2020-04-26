#include<stdio.h>
#include<stdlib.h>



void countingsort(int** a,int n,int k);

//main function
int main()
{
	int i,k,n;
	printf("Enter the number of elements and max element\n");
	scanf("%d %d",&n,&k);
	printf("Enter the elements of array\n");
	
	int* arr=(int *)malloc(sizeof(int)*n);
	
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	
	
	countingsort(&arr,n,k);
	printf("The sorted elements are:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);	
	
}

//counting sort algo
void countingsort(int** a,int n,int k)
{
	int i;
	int* c=(int *)malloc(sizeof(int)*n);
	int* b=(int *)malloc(sizeof(int)*k);
	for(i=0;i<k;i++)
		b[i]=0;
	for(i=0;i<n;i++)
		b[(*a)[i]]++;
	for(i=0;i<k;i++)
		b[i+1]+=b[i];
	for(i=k;i>=0;i--)
	{
		if(b[i]>0)
		{
			c[b[i]-1]=i;
			b[i]--;
			i++;
		}
	}
	*a=c;
}
	
	 

#include <stdio.h>



int main()
{
        //insertion sort
	int a[20],data[20],min,temp;
        int i,j,k,n;
	     
	printf("Enter the number of arrays\n");
        scanf("%d",&n);

        printf("Enter the array\n");

	for(i=0;i<n;i++)		
		scanf("%d",&a[i]);

	for(j=1;j<n;j++)
	{
		temp=a[j];
		for(i=j;i>0&&temp<a[i-1];i--)
			a[i]=a[i-1];
		a[i]=temp;
	}


	for(i=0;i<n;i++)		
		printf("%d",a[i]);

	printf("\n");



	//selection sort
	int a[20],data[20],min,temp;
        int i,j,k,n;

	printf("Enter the number of arrays\n");
        scanf("%d",&n);

        printf("Enter the array\n");

	for(i=0;i<n;i++)		
		scanf("%d",&a[i]);

	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			min=a[i];
			if(a[j]<min)
			{
				min=a[j];
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<n;i++)		
		printf("%d",a[i]);

	printf("\n");				
			
		


	






}

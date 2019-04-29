#include<stdio.h>
#include<conio.h>

int main()
{
	int n,i,j,a[20],temp;
	printf("\nEnter size of array:");
	scanf("%d",&n);
	printf("\nEnter elements of array:");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	i=0;
	while(i<n-1)
	{
		j=i+1;
		while(j<n)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			j++;
		}
		i++;
	}
	printf("\nSorted Array....");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
}

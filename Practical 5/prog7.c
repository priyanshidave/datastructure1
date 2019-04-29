#include<stdio.h>
#define N 10
int q[N];
int a[N];
int top=-1;
int f=-1;
int r=-1;
void enqueue(int val)
{
	if(r>=N-1)
		printf("Queue overflow\n");

	else if(r==-1 && f== -1) 
	{
		f=r=0;
		q[r]=val;
		//printf("value inserted  : %d \n",val);
	}
	else
	{
		r++;
		q[r]=val;
		//printf("value inserted  : %d \n",val);
	}
	
	

}
int dequeue()
{
	int tmp=0;
	if(f==-1)
		printf("queue underflow\n");
	tmp=q[f];
	if(f==r)
		f=r=0;
	else
		f++;
	return tmp;
	
}
void display()
{
	int i;
	if(f>r && r==-1)
		printf("Queue underflow\n");
	else
	{
		for(i=f;i<=r;i++)
		{
			printf("%d \t",q[i]);
		}
	}
}
int isfull()
{
	if(top==N-1)
		return 1;
	else 
		return 0; 
}
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
void push(int val)
{
		if(isfull()!=1)
		{
			top++;
			a[top]=val;			
		}
}
void reverse()
{
	int i;
	for(i=f;i<=r;i++)
	{
		push(dequeue());
	}
}

void display_s()
{
	int i;
	if(isempty()!=1)
	{
		for(i=top;i>=0;i--)
		{
			printf("%d \t",a[i]);
		}
	}
}
int main()
{
	int n,i,val;
	printf("Enter size of queue");
	scanf("%d",&n);
	printf("Enter queue element :");
	for(i=0;i<n;i++)
	{
		scanf("%d",&val);
		enqueue(val);
	}
	printf("\nOrginal queue\n");
	display();
	printf("\nReverse queue\n");
	reverse();
	display_s();
}


#include<stdio.h>
#define N 10
int a[N];
int tmp[N];
int top=-1;
int top1=-1;
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int isempty_tmp()
{
	if(top1==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(top==N-1)
		return 1;
	else 
		return 0; 
}
int isfull_tmp()
{
	if(top1==N-1)
		return 1;
	else 
		return 0; 
}
void push(int val)
{
		if(isfull()!=1)
		{	top++;
			a[top]=val;
					
		}
}
void push_tmp(int val)
{
		if(isfull_tmp()!=1)
		{
			top1++;
			tmp[top1]=val;
			
		}
}
int pop()
{
	int tmp;
	if(isempty()!=1)
	{
		tmp=a[top];
		top--;
		return tmp;
	}	
}
int pop_tmp()
{
	int tmp1;
	if(isempty()!=1)
	{
		tmp1=tmp[top1];
		top1--;
		return tmp1;
	}	
}
void enqueue(int val)
{
	if(top>=N-1)
		printf("queue full");
	else
	{
		
			while(!isempty())
			{
				push_tmp(pop());
			}
			push(val);
			while(!isempty_tmp())
			{
				push(pop_tmp());
			}
	}
}
int dequeue()
{
	int tmp;
	if(top==-1)
		printf("stack is empty");
	else
	{
		tmp=a[top];
		top--;
		return tmp;
	}
}
void display()
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
	int ch,con=1,val;
	while(con)
	{
		printf("\n---------menu---------");
		printf("\n1.Insert \n2.delete\n3.display\n4.Exit\n");
		printf("Enter choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				printf("\nEnter value for insert  : " );
				scanf("%d",&val);
				enqueue(val);
				break;
			case 2:
				val=dequeue();
				printf("\nDeleted valude = %d",val);
				break;
			case 3:
				display();
				break;
			case 4:
				//exit(1);
				break ;
			default :
				printf("Invalid choice try again ");
				break;
		
		}
		printf("\npress 0 for end");
		scanf("%d",&con);

	}
	
}


#include<stdio.h>
#define N 10
int a[N];
int top=-1;
void push(int );
int pop();
void display();
int isempty();
int isfull();
int isempty()
{
	if(top==-1)
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
void push(int val)
{
		if(isfull()==1)
		{
			printf("\nStack is overflow");
		}
		else
		{
			top++;
			a[top]=val;
			display();
			
		}
}
int pop()
{
	int tmp;
	if(isempty()==1)
	{
		printf("\nStack is underflow");

		return -1;
	}
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
	if(isempty()==1)
		printf("Stack undeflow");
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d \t",a[i]);
		}
	}
}



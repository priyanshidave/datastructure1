#include<stdio.h>
#define N 10 
int a[]={34, 3, 31, 98, 92, 23};
int top=sizeof(a)/sizeof(int);
int tmp[N];
int ttop=-1;
void push(int );
int pop();
void main()
{
	int i;
	for(i=top;i>=0;i--)
	{
		int a=pop();
		if(ttop==-1)
		{
			ttop++;
			tmp[ttop]=a;		
		}
		else if(a<tmp[ttop])
		{
			push(a);
		}
		else
		{
			
		}
	}
}
int isempty()
{
	if(ttop==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(ttop==N-1)
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
			ttop++;
			tmp[ttop]=val;
			
			
		}
}
void pop()
{
	int tmp1;
	if(isempty()==1)
	{
		printf("\nStack is underflow");

		return -1;
	}
	else
	{
		ttmp=tmp[top];
		ttop--;
		
	}	
}

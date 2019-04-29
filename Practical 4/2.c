#include<stdio.h>

#define N 10
int a[N];
int top=-1;
void push(int );
int pop();
void main()
{
	char post[10];
	int i=0,n1,n2,ans;
	printf("Enter postfix expression : ");
	scanf("%s",post);
	while(post[i]!='\0')
	{
		if(post[i]>=48 &&post[i]<=57)
			push(post[i]-48);
		else
		{
			n2=pop();
			n1=pop();
			if(post[i]=='+')
				ans=n1+n2;
			else if(post[i]=='-')
				ans=n1-n2;
			else if(post[i]=='*')
				ans=n1*n2;
			else if(post[i]=='/')
				ans=n1/n2;
			push(ans);
			
		} 
		
		i++;
	}
	printf("Answer =%d\n",pop());
}
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
		a[top]=0;
		top--;
		return tmp;
	}	
}

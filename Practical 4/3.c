#include<stdio.h>
#define N 10
char a[N];
int top=-1;
void push(char );
char pop();
void main()
{
	char in[20],post[20],c;
	int i=0,j=0;
	printf("\nEnter infix expression  ");
	scanf("%s",in);
	while(in[i]!='\0')
	{
		if((in[i]>=97&&in[i]<=122)||(in[i]>=65&&in[i]<=90))
		{
			post[j]=in[i];
			j++;
		}
		else if(in[i]==')')
		{
			c=pop();
			while(c!='(')
			{
				post[j]=c;
				j++;
				c=pop();				
			}
		}
		else
		{
			push(in[i]);
		}
		i++;
	}
	post[j]='\0';
	printf("postfix expression : %s",post);
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
void push(char val)
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
char pop()
{
	char tmp;
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


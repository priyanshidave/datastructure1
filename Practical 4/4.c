#include<stdio.h>
#include<string.h>
#define N 10
char a[N];
int top=-1;
void push(char );
char pop();
void main()
{
	char in[20],pre[20],prer[20],c;
	int i=0,j=0;
	printf("\nEnter infix expression  ");
	scanf("%s",in);
	for(i=strlen(in)-1,j=0;i>=0;i--,j++)
		prer[j]=in[i];
	prer[j]='\0';
	strcpy(in,prer);
	i=j=0;
	while(in[i]!='\0')
	{
		if((in[i]>=97&&in[i]<=122)||(in[i]>=65&&in[i]<=90))
		{
			pre[j]=in[i];
			j++;
		}
		else if(in[i]=='(')
		{
			c=pop();
			while(c!=')')
			{
				pre[j]=c;
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
	pre[j]='\0';
	for(i=strlen(pre)-1,j=0;i>=0;i--,j++)
		prer[j]=pre[i];
	prer[j]='\0';
	
	printf("prefix expression : %s",prer);
	
	
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


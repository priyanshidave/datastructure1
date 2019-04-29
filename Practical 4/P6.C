//Sort using Recursion
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int);
void sortedInsert(int);
void sortStack();
int pop();
void printStack();
void main(void)
{
    int n,i,data;
    printf("Enter Number of Element Insert in Stack : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	printf("Enter Data : ");
	scanf("%d",&data);
	push(data);
    }
    printf("Stack elements before sorting:\n");
    printStack();

    sortStack();
    printf("\n\n");

    printf("Stack elements after sorting:\n");
    printStack();
    getch();
}
int isEmpty()
{
    if(top == -1)
	return 1;
    else
	return 0;
}

void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	//	printf("PUSH : %d\n",item);
	}
}

int pop()
{
    int item;
	if(top <0)
	{
		printf("stack under flow:");
    }
	else
	{
		item = stack[top];
		//printf("\t %d : DELETE\n",item);
		top = top-1;
	       //	return(item);
	}
	return item;
}
void sortedInsert(int x)
{   int temp;
    if (isEmpty() || x > stack[top] )
    {
	push(x);
	return;
    }

    temp = pop();
    sortedInsert(x);
    push(temp);
    //return temp;
}

void sortStack()
{

    if (!isEmpty())
    {
	int x = pop();
      //  printf("POP : %d\n",x);
	sortStack();
	//printf("Value : %d\n",x);
	sortedInsert(x);
    }
}

void printStack()
{   int i;
    if(top==-1)
    {
	printf("\tSTACK IS EMPTY\n");
    }

    for(i=top;i>=0;i--)
    {
        printf("\t| %d |\n",stack[i]);
    }
}

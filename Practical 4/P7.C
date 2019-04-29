#include<stdio.h>
#include<string.h>
//#include<conio.h>
#define MAX 100

int top = -1;
char stack[MAX];
void display();
char push(char item)
{
	if(top >= MAX-1)
		printf("Stack Overflow\n");
	else
	{
	top = top + 1;
		stack[top] =item;
	}
	return item;
}

char pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
		return stack[top--];
	return 1;
}

int main()
{
	char str[20];
	int i;
	//clrscr();
	printf("Enter the string : " );
	gets(str);
	for(i=0;i<strlen(str);i++)
		push(str[i]);
	display();
//	getch();
}
void display()
{       int i;
	for(i=top;i>-1;i--)
	{
		printf("%s",stack[i]);
	}
}
//hello395world216

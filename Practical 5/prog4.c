#include<stdio.h>
#define N 3
int q[N];
int f=-1;
int r=-1;
void enqueue(int val)
{
	if((f==-1 && r==N-1) ||(r-f+1 ==0 ))
		printf("Queue overflow\n");
	else if(r==-1 && f== -1) 
	{
		f=r=0;
		q[r]=val;
		printf("value inserted  : %d \n",val);
	}
	else if(r==N-1)
	{
		r=0;
		q[r]=val;
		printf("value inserted  : %d \n",val);
	}
	else
	{	
		r++;
		q[r]=val;
		printf("value inserted  : %d \n",val);	
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
	else if(f==N-1)
		f=0;
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
		if(f<r)
		{
			for(i=f;i<=r;i++)
			{
				printf("%d \t",q[i]);
			}
		}
		else
		{
			
			for(i=f;i<=N-1;i++)
			{
				printf("%d \t",q[i]);
			}
			for(i=0;i<=r;i++)
			{
				printf("%d \t",q[i]);
			}
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
				printf("\n Enter value for insert  : " );
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


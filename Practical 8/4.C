#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
void preorder(struct node* root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
struct node* createnode(int value)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* insleft(struct node* root,int value)
{
	root->left=createnode(value);
	return root->left;
}

struct node* insright(struct node* root,int value)
{
	root->right=createnode(value);
	return root->right;
}
void main()
{
	struct node* root=createnode(1);
	clrscr();
	insleft(root,12);
	insright(root,9);
	insleft(root->left,5);
	insright(root->left,6);
	printf("preorder traversal\n");
	preorder(root);
	getch();
}
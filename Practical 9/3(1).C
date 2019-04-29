#include<stdio.h>
#include<conio.h>
struct tree_node
{
    struct tree_node*right,*left;
    int data;
};
struct tree_node *stemp=NULL;
struct tree_node* del(struct tree_node*,int);
struct tree_node* insert(struct tree_node*,int);
struct tree_node* travel(struct tree_node*,struct tree_node*);
void inorder(struct tree_node *);
void main()
{
    struct tree_node* root=NULL;
    int item,ch;
    do
    {

        printf("\n 1) insert a node");
        printf("\n 2) delete a node");
        printf("\n 3) display ");
        printf("\n 4) exit");
        printf("\n Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element to insert\n");
                scanf("%d",&item);
                root=insert(root,item);
            break;
            case 2:
                printf("Enter element to delete\n");
                scanf("%d",&item);
                root=del(root,item);
                if(stemp!=NULL)//condition for any break link is present to insert or not
                travel(root,stemp);//to insert break link during insertion
            break;
            case 3:
                printf("inorder travel\n");
                inorder(root);
            
            break;
            case 4:exit(0);
            break;
            default :
               printf("wrong choice\n");
        }
    }while(ch!=4);
}
void inorder(struct tree_node *root)
{
    if (root != NULL)
    {
    inorder(root->left);
    printf("%d \n", root->data);
    inorder(root->right);
    }
}
struct tree_node* insert(struct tree_node*root,int item)
{
    if(root==NULL)
    {
        struct tree_node* temp;
        temp=(struct tree_node*)malloc(sizeof(struct tree_node));
        temp->left=NULL;
        temp->right=NULL;
        temp->data=item;
        root=temp;
    }
    else
    {
            if(root->data<item)
            {
                root->right=insert(root->right,item);
            }
            else
            {
                root->left=insert(root->left,item);
            }
    }
    return(root);
}
struct tree_node* del(struct tree_node*root,int item)
{
    if(item==root->data)
    {
        if(root->left==NULL&&root->right==NULL) //no child
        {
            root=NULL;

        }
        else if(root->left==NULL||root->right==NULL) //one child
        {
            if(root->left!=NULL) //left child
            {
                root=root->left;
            }
            else               //right child
            {
                root=root->right;
            }
        }
        else  if(root->left!=NULL&&root->right!=NULL) //both child
        {
            struct tree_node* temp;
            stemp=root->right->left;
            temp=root;
            root=root->right;
            root->left=temp->left;
        }
    }
    else
    {
            if(root->data<item)
            {
                root->right=del(root->right,item);
            }
            else
            {
                root->left=del(root->left,item);
            }
    }
    return(root);
}
struct tree_node* travel(struct tree_node*root,struct tree_node*stemp)
{
    if (stemp != NULL)
    {
        insert(root,stemp->data);
        travel(root,stemp->left);
        travel(root,stemp->right);
    }
    return(root);
}

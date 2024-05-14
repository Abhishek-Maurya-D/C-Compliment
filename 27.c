// Binary Tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};
struct node *root;

struct node *create()
{
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data(type -1 for no node): ");
    scanf("%d",&x);
    if(x==-1)
        return NULL;
    else
    {
        newnode->data=x;
        printf("Enter left Child of %d\n",x);
        newnode->left=create();
        printf("Enter right Child of %d\n",x);
        newnode->right=create();
    }
    return newnode;
}

void preorder(struct node *root)
{
    if(root==NULL)
        return ;
    else
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if(root==NULL)
        return ;
    else
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root==NULL)
        return ;
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
}

int main()
{
    root=NULL;
    root = create();
    printf("Pre-Order Transversal is : ");
    preorder(root);
    printf("\n");
    printf("Inorder Transversal is : ");
    inorder(root);
    printf("\n");
    printf("Post-Order Transversal is : ");
    postorder(root);
    printf("\n");
    return 0;
}
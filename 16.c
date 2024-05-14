// Stack Implementation Full
// push, pop, peek & display
// Using Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
} *top=NULL;
void push()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->link=top;
    top=newnode;
}
void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
        printf("Empty Stack");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
void peek()
{
    if(top==NULL)
        printf("Empty Stack");
    else
        printf("%d",top->data);
}
void pop()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
        printf("Empty Stack");
    else
    {
        top=top->link;
        free(temp);
    }
}
int main()
{
    int choice;
    do
    {
        printf("\t\t ----- Stack Operation with Implementing -----\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Peek Element\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("ENTER THE OPERATION NUMBER\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3: 
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid Option");
        }
    }while(choice!=5);
}
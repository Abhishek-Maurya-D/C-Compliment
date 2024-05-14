// CIRCULAR LINKED LIST
// head pointer is only used

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
void create()
{
    int choice;
    head=NULL;
    struct node *newnode, *temp;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the Data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
        printf("Do you want to enter more data(0/1): ");
        scanf("%d",&choice);
    }while(choice);
}
void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("Empty List\n");
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=head);
}
int main()
{
    create();
    display();
    return 0;
}
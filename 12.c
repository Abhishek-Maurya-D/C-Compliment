// Circular linked list using both head & tail pointer

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *tail;
void create()
{
    struct node *newnode;
    int choice;
    do
    {    
        newnode=(struct node *)malloc(sizeof(struct node));
        head = NULL;
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=tail=newnode;
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        tail->next=head;
        printf("Do you want to enter more data(0/1): ");
        scanf("%d",&choice);
    } while (choice);
}
int main()
{
    create();
    return 0;
}
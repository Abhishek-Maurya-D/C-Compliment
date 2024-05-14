// Doubly Linked List creation and display only
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *head;
void create()
{
    head = NULL;
    struct node *temp;
    int choice;
    do
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Data: ");
        scanf("%d", &newnode->data);
        newnode->pre = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->pre = temp;
            temp = newnode;
        }
        printf("Do you want to enter more data(0/1): ");
        scanf("%d", &choice);
    } while (choice);
}
void display()
{
    struct node *temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main()
{
    create();
    display();
    return 0;
}
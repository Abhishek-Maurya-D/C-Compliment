 // Priorty Queue

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);
    printf("Enter the Priorty: ");
    scanf("%d",&newnode->priority);
    newnode->next=NULL;
    if (front == NULL || newnode->priority >= front->priority)
    {
        newnode->next = front;
        front = newnode;
    }
    else
    {
        struct node *temp = front;
        while (temp->next != NULL && temp->next->priority > newnode->priority)
            temp = temp->next;
        newnode->next = temp->next;
        temp->next = newnode;
    }
    if (rear == NULL)
        rear = newnode;
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Empty Queue!\n");
        return;
    }
    struct node *temp=front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

void display()
{
    struct node *temp=front;
    if(temp==NULL)
        printf("Queue is Empty!\n");
    else
    {
        printf("Priority Queue is --\n");
        while(temp!=NULL)
        {
            printf("(%d,%d) \t",temp->data,temp->priority);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    printf("\t\t ----- Priority Queue -----\n");
    do
    {
        printf("\t--Operation on Queue--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                enqueue();
                break;
            case 2: 
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting the Program\n");
                break;
            default:
                printf("Invalid option Choosen\n");
        }
    }while(choice!=4);
    return 0;
}
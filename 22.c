// Implementation of Circular Queue by Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==NULL)
    {
        front=rear=newnode;
        newnode->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}

void dequeue()
{
    struct node *temp;
    temp=front;
    if(front==NULL)
        printf("Empty Queue\n");
    else if((front == rear) && (front != NULL))
    {
        front = rear = NULL;
        free(temp);
    }
    else
    {
        rear->next=front->next;
        front=front->next;
        free(temp);
    }
}

void display()
{
    struct node *temp;
    temp=front;
    if (temp == NULL)
    {
        printf("Empty Queue\n");
        return;
    }
    else
    {
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=front);
        printf("\n");
    }
}

void peek()
{
    if(front==NULL)
        printf("Empty Queue\n");
    else
        printf("%d\n",front->data);
}

int main()
{
    int choice, ch;
    printf("\t\t ----- Queue -----\n");
    do
    {
        printf("\t--Enter the Choice--\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
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
                peek();
                break;
            default:
                ch=0;
                break;
        }
        printf("Do you want to continue!(0/1):  ");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}
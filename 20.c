// Queues Implementation using Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front, *rear;
void insert()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(front==NULL)
        front=rear=newnode;
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}
void delete()
{
    struct node *temp;
    temp=front;
    front=front->next;
    free(temp);
}
void display()
{
    struct node *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void peek()
{
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
                insert();
                break;
            case 2: 
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
        printf("Do you want to continue!(0/1) ");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}

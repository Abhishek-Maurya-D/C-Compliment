// Queues Implementation using Array
#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    printf("Enter the Data: ");
    scanf("%d",&x);
    if(rear==N-1)
        printf("Queue is Overflow\n");
    else if(front == -1 && rear == -1)
    {
        rear=front=0;
        queue[rear]=x;
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Empty List\n");
    else if(rear == front)
        front=rear=-1;
    else
        front++;
}

void display()
{
    if(front==-1 && rear==-1)
        printf("Empty List\n");
    else
    {
        for(int i=front; i<=rear; i++)
            printf("%d\t",queue[i]);
        printf("\n");
    }
}

void peek()
{
    if(front==-1 && rear==-1)
        printf("Empty List\n");
    else
        printf("%d",queue[front]);
    printf("\n");
}

int main()
{
    int choice, ch;
    printf("\t\t ----- Queue -----\n");
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("\t--Enter the Choice--\n");
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
                printf("Invalid Choice!\n");
                break;
        }
        printf("Do you want to continue!(0/1) ");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}
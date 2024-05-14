// Circular Queue using Array
// It is an advantage over the Normal Queue

#include<stdio.h>
#include<stdlib.h>

#define N 5
int queue[N];
int front=-1;
int rear=-1;

void enqueue()
{
    int x;
    printf("Enter the Data: ");
    scanf("%d",&x);
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if(((rear+1)%N)==front)
        printf("Queue is Full\n");
    else
    {
        rear=((rear+1)%N);
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Empty Queue\n");
    else if(front==rear)
        rear=front=-1;
    else
        front=((front+1)%N);
}

void display()
{
    int temp=front;
    if(front==-1 && rear==-1)
        printf("Empty List\n");
    else if(front==rear)
        printf("%d\t",queue[front]);
    else
    {
        while(temp!=rear)
        {
            printf("%d\t",queue[temp]);
            temp=((temp+1)%N);
        }
        printf("%d\t",queue[temp]);
    }
    printf("\n");
}

void peek()
{
    printf("%d\n",queue[front]);
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
        printf("Do you want to continue!(0/1) ");
        scanf("%d",&ch);
    }while(ch);
    return 0;
}
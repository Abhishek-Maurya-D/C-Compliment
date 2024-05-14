/* +++++ Important +++++ Double Ended Queue
Deque
both property FIFO & LIFP
There are two type of deque 1. Input Restracted 2. Output Restracted
Operation on Deque are 1. Insert at front 2. Insert at rear 3. Delete from front 4. Delete from rear 5. Getfront 6. GetRear 7. Isfull 8. IsEmpty
*/
#define N 5
int deque[N];
int f=-1, r=-1;
#include<stdio.h>
#include<stdlib.h>
void enqueue_front()
{
    int x;
    printf("Enter the Data: ");
    scanf("%d",&x);
    if(f==r+1 || (f==0 && r==N-1))
        printf("Deque is Full");
    else if(f==-1 && r==-1)
    {
        f=r=0;
        deque[f]=x;
    }
    else if(f==0)
    {
        f=N-1;
        deque[f]=x;
    }
    else
    {
        deque[--f]=x;
    }
}
void enqueue_rear()
{
    int x;
    printf("Enter the Data: ");
    scanf("%d",&x);
    if(f==r+1 || (f==0 && r==N-1))
        printf("Deque is Full");
    else if(f==-1 && r==-1)
    {
        f=r=0;
        deque[r]=x;
    }
    else if(r==N-1)
    {
        r=0;
        deque[r]=x;
    }
    else
    {
        deque[++r]=x;
    }
}
void display()
{
    int i=f;
    while(i!=r)
    {
        printf("%d\t",deque[i]);
        i=(i+1)%N;
    }
    printf("%d\n",deque[i]);
}
void getfront()
{
    printf("%d\n",deque[f]);
}
void getrear()
{
    printf("%d\n",deque[r]);
}
void dequeue_front()
{
    if(f==-1 && r==-1)
        printf("Empty Deque!\n");
    else if(f==r)
        f=r=-1;
    else if(f==N-1)
        f=0;
    else
        f++;
}
void dequeue_rear()
{
    if(f==-1 && r==-1)
        printf("Empty Deque!\n");
    else if(f==r)
        f=r=-1;
    else if(r==0)
        r=N-1;
    else
        r--;
}
int main()
{
    int choice, ch;
    printf("\t\t ----- Queue -----\n");
    do
    {
        printf("\t--Enter the Choice--\n");
        printf("1. Enqueue From Front\n");
        printf("2. Enqueue From Rear\n");
        printf("3. Dequeue From Front\n");
        printf("4. Dequeue From Rear\n");
        printf("5. Display\n");
        printf("6. Peek From Front\n");
        printf("7. Peek From Rear\n");
        printf("8. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue_front();
            break;
        case 2:
            enqueue_rear();
            break;
        case 3:
            dequeue_front();
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            display();
            break;
        case 6:
            getfront();
            break;
        case 7:
            getrear();
            break;
        case 8:
            printf("Exit!");
            break;
        }
        printf("Do you want to continue!(0/1):  ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}
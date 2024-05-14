// Implementing Queues using Stack(of Array)

#define N 5
int s1[N], s2[N];
int top1 = -1, top2 = -1;
int count = 0;

#include <stdio.h>
#include <stdlib.h>

int pop1()
{
    return s1[top1--];
}

int pop2()
{
    return s2[top2--];
}

void push1(int x)
{
    if (top1 == (N - 1))
        printf("Over Flow Condition\n");
    else
        s1[++top1] = x;
}

void push2(int x)
{
    s2[++top2] = x;
}

void enqueue()
{
    int x;
    printf("Enter the Data: ");
    scanf("%d", &x);
    if(top1==(N-1))
        printf("Queue is Full");
    else
        push1(x);
    count++;
}

void dequeue()
{
    int b;
    if (top1 == -1 && top2 == -1)
        printf("Empty Queue!\n");
    else
    {
        for (int i = 0; i < count; i++)
            push2(pop1());
        b = pop2();
        printf("The Pop element is %d", b);
        count--;
        for (int i = 0; i < count; i++)
            push1(pop2());
    }
}

void display()
{
    for (int i = top1; i >= 0; i--)
        printf("%d\t", s1[i]);
    printf("\n");
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
        printf("4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
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
            printf("Exit!");
            break;
        }
        printf("Do you want to continue!(0/1):  ");
        scanf("%d", &ch);
    } while (ch != 4);
    return 0;
}
// Stack Implementation full
// push, pop, peek & display
// by using static memory location
#include<stdio.h>
#include<stdlib.h>
#define N 5
int Stack[N];
int top=-1;
void push()
{
    int x;
    printf("Enter the Data: ");
    scanf("%d",&x);
    if(top==N-1)
        printf("Stack Over Flow Condition\n");
    else
    {
        top++;
        Stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
        printf("Stack Under Flow Condition\n");
    else
        top--;
}
void peek()
{
    if(top==-1)
        printf("Empty Stack\n");
    else
        printf("%d\n",Stack[top]);
}
void display()
{
    if(top==-1)
        printf("Empty Stack\n");
    else
    {
        for(int i=top; i>-1; i--)
            printf("%d\t",Stack[i]);
    }
    printf("\n");
}
int main()
{
    int choice;
    do
    {
        printf("\t\t ----- Stack Operation with Implementing -----\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Peek Element\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("ENTER THE OPERATION NUMBER\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3: 
                peek();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid Option");
        }
    }while(choice!=5);
}
// Circular Linked List using only tail
// All operations

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;
int length=0;

void create()
{
    int choice;
    struct node *newnode;
    tail=NULL;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        length++;
        newnode->next=NULL;
        if(tail==NULL)
            tail=newnode->next=newnode;
        else
        {
            newnode->next=tail->next;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Do you want to enter more data(0/1): ");
        scanf("%d",&choice);
    }while(choice);
}

void display()
{
    struct node *temp;
    temp=tail->next;
    do
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }while(temp!=tail->next);
    printf("\n");
}

void insert_at_beg()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);
    length++;
    newnode->next=NULL;
    if(tail==NULL)
        tail->next=tail=newnode;
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
    }
}

void insert_at_end()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);
    length++;
    newnode->next=NULL;
    if(tail==NULL)
        tail->next=tail=newnode;
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
}

void insert_at_pos()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    int pos, i=1;
    printf("Enter the position where you want to insert an element: ");
    scanf("%d",&pos);
    if(pos<0 || pos>length)
        printf("Invalid Position\n");
    else if(pos == 1)
        insert_at_beg();
    else if(pos == length)
        insert_at_end();
    else
    {
        printf("Enter the Data: ");
        scanf("%d",&newnode->data);
        length++;
        newnode->next=NULL;
        temp=tail->next;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void del_from_beg()
{
    struct node *temp;
    temp=tail->next;
    if(temp==NULL)
        printf("Empty List!");
    else if(temp==tail)
    {
        tail=NULL;
        free(temp);
        length--;
    }
    else
    {
        tail->next=temp->next;
        free(temp);
        length--;
    }
}

void del_from_end()
{
    struct node *current, *previous;
    current=tail->next;
    previous=current;
    if(tail==NULL)
        printf("Empty List!");
    else if(current==tail)
    {
        tail=NULL;
        free(current);
        length--;
    }
    else
    {
        while(current->next!=tail->next)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        tail=previous;
        free(current);
        length--;
    }
}

void del_from_pos()
{
    int pos, i=1;
    struct node *current, *previous;
    printf("Enter the position where you want to insert the data: ");
    scanf("%d",&pos);
    previous = tail->next ;
    if(pos<1 || pos>length)
        printf("Invalid Position");
    else if(pos==1)
        del_from_beg();
    else if(pos==length)
        del_from_end();
    else
    {
        while(i<pos-1)
        {
            previous = previous->next;
            i++;
        }
        current=previous->next;
        previous->next=current->next;
        free(current);
        length--;

    }
}

void reverse()
{
    struct node *previous, *current, *nextnode;
    current=tail->next;
    nextnode=current->next;
    if(tail==NULL)
        printf("Empty List!");
    else
    {
        while(current!=tail)
        {
            previous=current;
            current=nextnode;
            nextnode=nextnode->next;
            current->next=previous;
        }
        nextnode->next=tail;
        tail=nextnode;
    }
}

int main()
{
    printf("\t\t----- Circular Linked List -----\n");
    int choice;
    do
    {
        printf("Enter the Operation.\n");
        printf("1. Create Circular Linked List\n");
        printf("2. Enter the element at the Starting Position\n");
        printf("3. Enter the element at the Ending Position\n");
        printf("4. Enter the element at the position\n");
        printf("5. Printing the list.\n");
        printf("6. Delete from Starting\n");
        printf("7. Delete from End\n");
        printf("8. Delete from a specific Position\n");
        printf("9. Reversing the Double linked list.\n");
        printf("10. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_at_beg();
            break;
        case 3:
            insert_at_end();
            break;
        case 4:
            insert_at_pos();
            break;
        case 5:
            display();
            break;
        case 6:
            del_from_beg();
            break;
        case 7:
            del_from_end();
            break;
        case 8:
            del_from_pos();
            break;
        case 9:
            reverse();
            break;
        default:
            break;
        }
    } while (choice != 10);
    return 0;
}
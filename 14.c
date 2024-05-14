// Doubly Circular Linked List
// Full Concept
#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *previous;
    int data;
    struct node *next;
};
struct node *head, *tail;
int length=0;
void create()
{
    struct node *newnode;
    head=NULL;
    int choice;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        length++;
        if(head==NULL)
        {
            head=tail=newnode;
            newnode->next=newnode->previous=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->previous=tail;
            newnode->next=head;
            head->previous=newnode;
            tail=newnode;
        }
        printf("Do you want to enter more data(0/1): ");
        scanf("%d",&choice);
    }while(choice);
}
void display()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        printf("Empty List!");
    else
    {
        while(temp!=tail)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
void insert_at_beg()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d",&newnode->data);
    length++;
    if(head==NULL)
    {
        head=tail=newnode;
        newnode->previous=head;
        newnode->next=head;
    }
    else
    {
        newnode->next=head;
        head->previous=newnode;
        newnode->previous=tail;
        tail->next=newnode;
        head=newnode;
    }
}
void insert_at_end()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);
    length++;
    if(head==NULL)
    {
        head=tail=newnode;
        newnode->previous=head;
        newnode->next=head;
    }
    else
    {
        newnode->previous=tail;
        tail->next=newnode;
        newnode->next=head;
        head->previous=newnode;
        tail=newnode;
    }
}
void insert_at_pos()
{
    struct node *newnode, *temp;
    int pos, i=1;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the position where you want to enter the data: ");
    scanf("%d",&pos);
    if(pos<0 || pos>length)
        printf("Invalid Position");
    else if(pos==1)
        insert_at_beg();
    else if(pos==length)
        insert_at_end();
    else
    {
        printf("Enter the Data: ");
        scanf("%d",&newnode->data);
        length++;
        temp=head;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->previous=temp;
        newnode->next=temp->next;
        temp->next->previous=newnode;
        temp->next=newnode;
    }
}
void delete_from_beg()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("Empty List!");
    else if(temp->next==head)
    {
        head=tail=NULL;
        free(temp);
        length--;
    }
    else
    {
        temp->next->previous=tail;
        tail->next=temp->next;
        head=temp->next;
        free(temp);
        length--; 
    }
}
void delete_from_end()
{
    struct node *temp;
    temp=tail;
    if(head==NULL)
        printf("Empty List!");
    else if(head->next==head)
    {
        head=tail=NULL;
        free(temp);
        length--;
    }
    else
    {
        tail=tail->previous;
        tail->next=head;
        head->previous=tail;
        free(temp);
    }
}
void delete_from_pos()
{
    struct node *temp;
    int pos,i=1;
    printf("Enter the position from where you want to delete the data: ");
    scanf("%d",&pos);
    temp=head->next;
    if(pos<0 || pos>length)
        printf("Invalid position");
    else if(pos==1)
        delete_from_beg();
    else if(pos==length)
        delete_from_end();
    else
    {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        temp->previous->next=temp->next;
        temp->next->previous=temp->previous;
        free(temp);
    }
} 
void reverse()
{
    struct node *current, *temp;
    current = head;
    do
    {
        temp = current->next;
        current->next = current->previous;
        current->previous = temp;
        current = temp;
    } while (current != head);
    head=tail;
    tail=current;
}
int main()
{
    printf("\t\t----- Doubly Circular Linked List -----\n");
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
            delete_from_beg();
            break;
        case 7:
            delete_from_end();
            break;
        case 8:
            delete_from_pos();
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
// fully operations on DOUBLY LINKED LIST
// main
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *pre;
    struct node *next;
};
struct node *head, *tail;
int count = 0;
void create()
{
    int isdata;
    head = NULL;
    struct node *newnode;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Data: ");
        scanf("%d", &newnode->data);
        count++;
        newnode->pre = newnode->next = NULL;
        if (head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            newnode->pre = tail;
            tail = newnode;
        }
        printf("Do You want to Enter more data(0/1): ");
        scanf("%d", &isdata);
    } while (isdata);
}
void insert_start()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Data: ");
    scanf("%d", &newnode->data);
    count++;
    newnode->pre = NULL;
    newnode->next = NULL;
    if (head == NULL)
    {
        tail = head = newnode;
    }
    else
    {
        head->pre = newnode;
        newnode->next = head;
        head = newnode;
    }
}
void insert_end()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the Data: ");
    scanf("%d",&newnode->data);
    count++;
    newnode->pre=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        tail=head=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->pre=tail;
        tail=newnode;
    }
}
void insert_at_pos()
{
    int pos, i=1;
    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &pos);
    if(pos<0 || pos>count)
        printf("INVALID POSITION FOR DATA ENTERY");
    else if(pos==1)
        insert_start();
    else
    {
        struct node *newnode, *temp;
        temp=head;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        count++;
        newnode->next=newnode->pre=NULL;
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        newnode->pre=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp=newnode->next;
        temp->pre=newnode;
    }
}
void insert_after_pos()
{
    int pos, i=1;
    printf("Enter the position where you want to insert the data: ");
    scanf("%d", &pos);
    if(pos<0 || pos>count)
        printf("INVALID POSITION FOR DATA ENTERY\n");
    else if(pos==count)
        insert_end();
    else
    {
        struct node *newnode, *temp;
        temp=head;
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        count++;
        newnode->next=newnode->pre=NULL;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        newnode->pre=temp;
        newnode->next=temp->next;
        temp->next=newnode;
        temp=newnode->next;
        temp->pre=newnode;
    }
}
void print()
{
    struct node *temp;
    temp=head;
    if(temp==NULL)
        printf("Empty List\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
void delete_at_beg()
{
    if(head==NULL)
        printf("Empty List\n");
    else
    {
        struct node *temp;
        temp=head;
        head = head->next;
        head->pre=NULL;
        free(temp);
    }
}
void delete_at_end()
{
    if(tail==NULL)
        printf("Empty List\n");
    else
    {
        struct node *temp;
        temp=tail;
        tail=tail->pre;
        tail->next=NULL;
        free(temp);
    }
}
void delete_at_pos()
{
    int pos;
    printf("Enter the position where you want to insert the data: \n");
    scanf("%d",&pos);
    if(pos<0 || pos>count)
        printf("Invalid Position Entered: \n");
    else
    {
        struct node *temp, *temppre, *tempnext;
        int i=1;
        temp=head;
        while(i<pos)
        {
            temp=temp->next;
            i++;
        }
        temppre=temp->pre;
        temppre->next=temp->next;
        tempnext=temp->next;
        tempnext->pre=temp->pre;
        // temp->pre->next=temp->next;
        // temp->next->pre=temp->pre;
        free(temp);
    }
}
void reverse()
{
    struct node *current, *nextnode;
    if(head==NULL)
        printf("Empty List\n");
    else
    {
        current = head;
        while(current!=NULL)
        {
            nextnode=current->next;
            current->next=current->pre;
            current->pre=nextnode;
            current=nextnode;
        }
        current = head;
        head = tail;
        tail = current;
    }
}
int main()
{
    printf("\t\t----- Doubly Linked List -----\n");
    int choice;
    do
    {
        printf("Enter the Operation.\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Enter the element at the Starting Position\n");
        printf("3. Enter the element at the Ending Position\n");
        printf("4. Enter the element at the position\n");
        printf("5. Enter the element at the After the Position\n");
        printf("6. Printing the list.\n");
        printf("7. Delete from Starting\n");
        printf("8. Delete from End\n");
        printf("9. Delete from a specific Position\n");
        printf("10. Reversing the Double linked list.\n");
        printf("11. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            insert_start();
            break;
        case 3:
            insert_end();
            break;
        case 4:
            insert_at_pos();
            break;
        case 5:
            insert_after_pos();
            break;
        case 6:
            print();
            break;
        case 7:
            delete_at_beg();
            break;
        case 8:
            delete_at_end();
            break;
        case 9:
            delete_at_pos();
            break;
        case 10:
            reverse();
            break;
        default:
            break;
        }
    } while (choice != 11);
    return 0;
}
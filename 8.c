// fully operations on SINGLY LINKED LIST
// main
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head, *temp, *newnode;
int count = 0;
void Linkedlistcreate()
{
    int choice;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        count++;
        if (head == NULL)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
        printf("Do you want to continue(0,1): ");
        scanf("%d", &choice);
    } while (choice);
}
void print_list()
{
    temp = head;
    if(temp==NULL)
        printf("Empty List\n");
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void insertion_at_beg()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element that you want to Insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
void insertion_at_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data that you want to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}
void insertion_inbetween()
{
    int pos, i = 1;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Position: ");
    scanf("%d", &pos);
    if (pos > count + 1 || pos < 1)
    {
        printf("Invalid Option");
    }
    else
    {
        temp = head;
        if (pos == 1)
        {
            printf("Enter the data: ");
            scanf("%d", &newnode->data);
            newnode->next = head;
            head = newnode;
            return;
        }
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        printf("Enter the data: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void delete_at_beg()
{
    if(head==NULL)
        printf("The List is empty");
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}
void delete_at_end()
{
    if(head==NULL)
        printf("Empty List");
    else{
        temp=head;
        struct node *pretemp;
        while(temp->next!=NULL)
        {
            pretemp=temp;
            temp=temp->next;
        }
        pretemp->next = NULL;
        free(temp);
    }
}
void delete_inbetween()
{
    int pos, i=1;
    printf("Enter the Position of element you want to delete: ");
    scanf("%d",&pos);
    struct node *pretemp;
    pretemp=head;
    if(pretemp==NULL)
        printf("The entered list is empty: ");
    else {
        while (i < pos - 1 && pretemp->next) {
            pretemp = pretemp->next;
            i++;
        }
        if (pretemp->next) {
            temp = pretemp->next;
            pretemp->next = temp->next;
            free(temp);
        }
        else
            printf("Invalid Position\n");
    }
}
void getlength()
{
    int count=0;
    temp=head;
    if(temp==NULL)
        printf("The List is empty\n");
    else{
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        printf("The length of the list is %d\n",count);
    }
}
void reverse(){
    struct node *prenode, *currentnode, *nextnode;
    prenode=NULL;
    currentnode=nextnode=head;
    while(nextnode!=NULL){
        nextnode=nextnode->next;
        currentnode->next = prenode;
        prenode = currentnode;
        currentnode=nextnode;
    }
    head=prenode;
}
int main()
{
    int a;
    do
    {
        printf("------  Enter the Operation that you want to perform:  ------\n");
        printf("1. Enter the data to the Singly Linked List\n");
        printf("2. Accessing the elements of the List\n");
        printf("3. Insertion at the begnning of the List\n");
        printf("4. Insertion at the end of the List\n");
        printf("5. Insertion inbetween the list\n");
        printf("6. Deletion at the begnning of the List\n");
        printf("7. Deletion at the end of the List\n");
        printf("8. Deletion inbetween the list\n");
        printf("9. Calculating the length of the list\n");
        printf("10. Reverse the List\n");
        printf("11. Exit\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            Linkedlistcreate();
            break;
        case 2:
            print_list();
            break;
        case 3:
            insertion_at_beg();
            break;
        case 4:
            insertion_at_end();
            break;
        case 5:
            insertion_inbetween();
            break;
        case 6:
            delete_at_beg();
            break;
        case 7:
            delete_at_end();
            break;   
        case 8:
            delete_inbetween();
            break;  
        case 9:
            getlength();
            break; 
        case 10:
            reverse();
            break;
        default:
            break;
        }
    } while (a != 11);
    return 0;
}
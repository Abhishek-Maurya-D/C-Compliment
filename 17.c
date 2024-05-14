// Polynomial Representation
// Addition of two polynomial:
// see 18.c which is connected with the same
#include <stdio.h>
#include <stdlib.h>
struct node
{
    float cofficient;
    int exponent;
    struct node *next;
};
struct node *poly1, *poly2, *sumpoly;
void insert_poly(struct node *temp)
{
    temp = NULL;
    int choice;
    do
    {
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Cofficient of the Variable: ");
        scanf("%f", &newnode->cofficient);
        printf("Enter the Power of exponent: ");
        scanf("%d", &newnode->exponent);
        newnode->next = NULL;
        if (temp == NULL)
            temp = newnode;
        else
        {
            newnode->next = temp;
            temp = newnode;
        }
        printf("Do you want to enter more polynomial variable(0/1): ");
        scanf("%d", &choice);
    } while (choice);
}
void sum_polynomial()
{
    struct node *newnode;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (poly1 == NULL)
        {
            while (poly2 != NULL)
            {
                newnode->cofficient = poly2->cofficient;
                newnode->exponent = poly2->exponent;
                newnode->next = NULL;
                if (sumpoly == NULL)
                    sumpoly = newnode;
                else
                    newnode->next = sumpoly;
                sumpoly = newnode;
                poly2 = poly2->next;
            }
            break;  // Exit the loop when poly1 is NULL
        }
        else if (poly2 == NULL)
        {
            while (poly1 != NULL)
            {
                newnode->cofficient = poly1->cofficient;
                newnode->exponent = poly1->exponent;
                newnode->next = NULL;
                if (sumpoly == NULL)
                    sumpoly = newnode;
                else
                    newnode->next = sumpoly;
                sumpoly = newnode;
                poly1 = poly1->next;
            }
            break;  // Exit the loop when poly2 is NULL
        }
        if (poly1->exponent > poly2->exponent)
        {
            newnode->cofficient = poly1->cofficient;
            newnode->exponent = poly1->exponent;
            newnode->next = NULL;
            if (sumpoly == NULL)
                sumpoly = newnode;
            else
                newnode->next = sumpoly;
            sumpoly = newnode;
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            newnode->cofficient = poly2->cofficient;
            newnode->exponent = poly2->exponent;
            newnode->next = NULL;
            if (sumpoly == NULL)
                sumpoly = newnode;
            else
                newnode->next = sumpoly;
            sumpoly = newnode;
            poly2 = poly2->next;
        }
        else
        {
            newnode->cofficient = (poly1->cofficient + poly2->cofficient);
            newnode->exponent = poly1->exponent;
            newnode->next = NULL;
            if (sumpoly == NULL)
                sumpoly = newnode;
            else
                newnode->next = sumpoly;
            sumpoly = newnode;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    } while (poly1 != NULL || poly2 != NULL);
}
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%.2fx^%d", temp->cofficient, temp->exponent);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    printf("Enter the first polynomial: \n");
    insert_poly(poly1);
    display(poly1);
    printf("Enter the second polynomial: \n");
    insert_poly(poly2);
    display(poly2);
    sum_polynomial();
    printf("Sum of the two Polynomials is: ");
    display(sumpoly);
    return 0;
}
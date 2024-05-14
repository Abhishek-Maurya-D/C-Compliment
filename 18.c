#include <stdio.h>
#include <stdlib.h>
struct node
{
    float coefficient;
    int exponent;
    struct node *next;
};
struct node *poly1, *poly2, *sumpoly;
void insert_poly(struct node **poly)
{
    *poly = NULL;
    int choice;
    do
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the Coefficient of the Variable: ");
        scanf("%f", &newnode->coefficient);
        printf("Enter the Power of exponent: ");
        scanf("%d", &newnode->exponent);
        newnode->next = *poly;
        *poly = newnode;
        printf("Do you want to enter more polynomial variables (0/1): ");
        scanf("%d", &choice);
    } while (choice);
}
void sum_polynomial()
{
    sumpoly = NULL;
    struct node *newnode;
    while (poly1 != NULL || poly2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (poly1 == NULL || (poly2 != NULL && poly1->exponent < poly2->exponent))
        {
            newnode->coefficient = poly2->coefficient;
            newnode->exponent = poly2->exponent;
            poly2 = poly2->next;
        }
        else if (poly2 == NULL || (poly1 != NULL && poly1->exponent > poly2->exponent))
        {
            newnode->coefficient = poly1->coefficient;
            newnode->exponent = poly1->exponent;
            poly1 = poly1->next;
        }
        else
        {
            newnode->coefficient = poly1->coefficient + poly2->coefficient;
            newnode->exponent = poly1->exponent;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        newnode->next = sumpoly;
        sumpoly = newnode;
    }
}
void display(struct node *temp)
{
    while (temp != NULL)
    {
        printf("%.2fx^%d", temp->coefficient, temp->exponent);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}
int main()
{
    printf("Enter the first polynomial:\n");
    insert_poly(&poly1);
    display(poly1);
    printf("Enter the second polynomial:\n");
    insert_poly(&poly2);
    display(poly2);
    sum_polynomial();
    printf("Sum of the two Polynomials is: ");
    display(sumpoly);
    return 0;
}
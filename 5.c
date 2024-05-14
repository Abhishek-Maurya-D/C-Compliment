// Accessing the array with using pointer

#include<stdio.h>
int main()
{
    int n;
    printf("Enter the Number of elements in Array: ");
    scanf("%d",&n);
    int a[n];
    int *p=a;
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        // scanf("%d",&a[i]);
        // scanf("%d",(a+i));
        // scanf("%d",(i+a));
        // scanf("%d",(p+i));
        // scanf("%d",&i[a]);
        scanf("%d",&p[i]);
        // scanf("%d",&i[p]);
    }
    printf("Elements of the array are: ");
    for(int i=0; i<n; i++)
    {
        // printf("%d\t",a[i]);
        // printf("%d\t",*(p+i));
        // printf("%d\t",*(a+i));
        // printf("%d\t",i[a]);
        // printf("%d\t",i[p]);
        printf("%d\t",p[i]);
    }
    return 0;
}
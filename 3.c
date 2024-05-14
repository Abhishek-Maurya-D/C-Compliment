// Traversal of elements of array
#include<stdio.h>
int main()
{
    int n;
    printf("\nEnter the size of the array: ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the Data of Array: ");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("\nElements of the Array are: ");
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    return 0;
}
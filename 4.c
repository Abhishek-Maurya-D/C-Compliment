// Deleting an element from the array 

#include<stdio.h>
int main()
{
    int n, pos;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements to the array: ");
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the position where you want to delete the data: ");
    scanf("%d",&pos);
    if(pos<=0 || pos>n){
        printf("Invalid Position");
    }
    else{
        for(int i=(pos-1); i<(n-1); i++)
        {
            a[i] = a[i+1];
        }
        n--;
    }
    for(int i=0; i<n; i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
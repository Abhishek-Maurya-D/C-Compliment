// 2-D Array

#include<stdio.h>
int main()
{
    int col, row;
    printf("Enter the number of colums & rows: ");
    scanf("%d %d",&col, &row);
    int a[row][col];
    printf("Enter the elements of the array: ");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Elements of the array are: \n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
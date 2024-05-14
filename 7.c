// 2-D array using pointers
#include<stdio.h>
int main()
{
    int a[3][3] = {5,3,6,8,6,3,1,2,3};
    int *p;
    p = &a[0][0];
    // p = a[0];
    // printf("%p",p);
    // printf("%p",a);
    // printf("%p",&a[0][0]);
    // printf("%p",&a);
    // printf("%p",*a);
    printf("%p\n",a[0]);
    printf("%d\n",**a);
    // printf("\n%d",**p);   Wrong Statement
    printf("%d\n",a[1]);
    printf("%d\n",a[1]+1);
    printf("%d\n",&a[1]+1);
    return 0;
}
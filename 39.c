// Radix Sort
// complexity O(n+k)


radix_sort(a,n)
{
    int max  = get_max(a, n);
    for(pos=1; max/pos>0; pos*10)
        count_sort(A, n, pos);
}

count_sort(int a[], int n, int pos)
{
    int count[10] = {0};
    for(int i=0; i<n; i++)
        ++count[(a[i]/pos)%10];
    for(int i=0; i<=k; i++)
        count[i] = count[i]+count[i-1];
    for(int i=n-1; i>=0; i--)
        b[--count[(a[i]/pos)%10]]=a[i];
    for(int i=0; i<n; i++)
        a[i]=b[i];
}
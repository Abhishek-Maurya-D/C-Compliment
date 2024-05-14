// Counting Sort

count_sort(A, n, k)   // A-Array, n-no. of elements, k-key value of the array that is the maximum value of the array
{
    int count[k+1];
    for(int i=0; i<n; i++)
        ++count[a[i]];
    for(int j=1; j<=k; j++)
        count[i]=count[i]+count[i-1];
    for(i=n-1; i>=0; i--)
        b[--count[a[i]]]=a[i];
    for(int i=0; i<n; i++)
        a[i]=b[i];
}
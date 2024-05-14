// Merge Sort
// Best Case Senario O(nlogn)
// Worst Case Senario O(nlogn)

merge(A, lb, mid, ub)
{
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
    if(i>mid)
    {
        while(j<=ub)
            b[k++]=a[j++];
    }
    else
    {
        while(i<=mid)
            b[k++]=a[i++];
    }
    for(int i=lb; i<=ub; i++)
        a[i]=b[i];
}
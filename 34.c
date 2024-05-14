// Quick Sort 
// Worst Case Senario O(n^2)
// Average Case Senario O(nlogn)
// Best Case Senario O(nlogn)

Partion(a,lb,ub)
{
    pivot=a[lb];
    start=lb;
    end=ub;
    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(a[start],a[end]);
    }
    swap(a[lb],a[end]);
    return end;
}

Quick_sort(A,lb,up)
{
    if(lb<up)
    {
        loc=partion(A,lb,ub);
        Quick_sort(A,lb,loc-1)
        Quick_sort(A,loc+1,up)
    }
}
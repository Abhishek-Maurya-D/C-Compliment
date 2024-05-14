// Binary Search
// Data should be in the shorted order
int binarySearch(a, n, data)
{
    int l=0, r=n-1;
    while(l<r)
    {
        mid=(l+r)/2;
        if(data==a[mid])
            return mid;
        else if(data<a[mid])
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}


// Best Case Senario == O(1)
// Worst Case Senario == O(logn)
// Average Case Senario == O(logn)
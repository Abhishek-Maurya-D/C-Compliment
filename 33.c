// Selection Sort
// Best Case Senario O(n^2)
// Average Case Senario O(n^2)
// Worst Case Senario O(n^2)

for(int i=0; i<n-1; i++)
{
    int min=i;
    for(int j=i+1; j<n; j++)
    {
        if(a[j]<a[min])
            min=j;
    }
    if(min!=i)
    {
        temp=a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}
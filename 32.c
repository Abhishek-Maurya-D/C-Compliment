// Insertion sort 
// Best Case Senario O(n)
// Worst case Senario O(n^2)
// Average Case Senario O(n^2)
for(int i=1; i<n; i++)
{
    temp = a[i];
    j=i-1;
    while(j>=0 && a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
}
// Bubble Sort 
// Best Case Senario O(n)
// Worst Case Senario O(n-1)
// Average Case Senario O(n^2)
int flag = 0;
for(int i=0; i<n-1; i++)
{
    for(int j=0; j<n-i-1; j++)
    {
        if(a[j]>a[j+1])
        {
            int temp=a[j];
            a[j] = a[j+1];
            a[j+1] = a[j];
            flag=1;
        }
    }
    if(flag = 0)
        break;
}
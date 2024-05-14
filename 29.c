// Linear search
// Sequiential Search
for(int i=0; i<n; i++)
{
    if(a[a]==data)
    {
        printf("Data is present at index : %dth", i);
        break;
    }
}
if(i==n)
{
    printf("Element not found");
}



// Second way of do the same thing
int found = 0;
for(int i=0; i<n; i++)
{
    if(a[a]==data)
    {
        printf("Data is present at index : %dth", i);
        found = 1;
        break;
    }
}
if(found == 0)
{
    printf("Element not found");
}



// best time complexity == O(1)
// Average time complexity == O(n+1/2)
// Worst Case time complexity == O(n)
// Heap Sort
// Complexity for insertion element is of Order --   (logn)
// Complexity for deleting element is of Order --   (logn)
// Complexity for inserting "n" elements in a heap tree is of Order --   (nlogn)
// Complexity for deleting "n" elements in a heap tree is of Order --   (nlogn)
// in the process of inserting "n" elements in a heap tree and then deleting "n" elements from it -- results in a sorting of the elements of the tree in ascending and descending order based on max_heap or a min_heap
// So we have to note that when we do all these thing the data we got is arragned
// Data so obtained which is sorted one as take complexity as nlogn+nlogn=2nlogn=O(nlogn), because 2 is constant

// INSERTION IN MAX HEAP
insert_heap_min(A, n, value)
{
    n = n + 1;
    A[n] = value;
    i = n;
    while (i > 1)
    {
        parent = i / 2;
        if (A[parent] < A[i])
        {
            swap(A[parent], A[i]);
            i = parent;
        }
        else
            return;
    }
}

// there is one specific method is also exist as "heapify"

Max_Heapify(A, n, i)
{
    int length = i;
    int l = 2 * i;
    int r = 2 * i + 1;
    while (l <= n && A[l] > A[largest])
        largest = l;
    while (r <= n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(A[largest], A[i]);
        Max_Heapify(A, n, largest);
    }
}

heapsort(A, n)
{
    for (i = n / 2; i >= 1; i--)
        Max_Heapify(A, n, i);
    for (i = n; i >= 1; i--)
    {
        swap(A[1], A[i]);
        Max_Heapify(A, n, i);
    }
}
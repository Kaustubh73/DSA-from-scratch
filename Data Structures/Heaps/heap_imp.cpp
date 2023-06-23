#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    int * arr;

    int maxSize;

    int heapSize;

    public: 
        MaxHeap(int maxSize);

        void MaxHeapify(int i);

        int parent(int i)
        {
            return (i - 1) / 2;
        }

        int lChild(int i)
        {
            return (2 * i + 1);
        }

        int rChild(int i)
        {
            return (2 * i + 2);
        }

        int removeMax();

        void increaseKey(int i, int newVal);

        int getMax()
        {
            return arr[0];
        }

        int curSize()
        {
            return heapSize;
        }

        void deleteKey(int i);

        void insertKey(int x);
};


MaxHeap::MaxHeap(int totSize)
{
    heapSize = 0;
    maxSize = totSize;
    arr = new int[totSize];
    // heapSize = 5;
    // arr[heapSize] = {32,324, 23, 12, 943};
}

void MaxHeap::insertKey(int x)
{
    if (heapSize == maxSize)
    {
        cout << "Heap Overflow\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x;

    while (i != 0 && arr[parent(i)] < arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::MaxHeapify(int i)
{
    int l = lChild(i);
    int r = rChild(i);
    int largest = i;
    if (l < heapSize && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < heapSize && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        MaxHeapify(largest);
    }

}

void max_heapify (int Arr[], int i, int N)
{
        int left = 2*i; //left child
        int right = 2*i +1;   
        int largest = i;        //right child
        if(left< N and Arr[left] > Arr[i] )
              largest = left;
        else
             largest = i;
        if(right < N and Arr[right] > Arr[largest] )
            largest = right;
        if(largest != i )
        {
            swap (Arr[i] , Arr[largest]);
            max_heapify (Arr, largest,N);
        } 
}

// void build_maxheap (int Arr[ ], int N)
// {
//     for(int i = N/2 ; i >= 1 ; i-- )
//     {
//         max_heapify (Arr, i) ;
//     }
// }
int main()
{
    MaxHeap h(15); 

    int k, i, n = 6, arr[5] = {32, 12, 3, 54, 43};
    // h.arr;
    // h.insertKey(3);
    // h.insertKey(10);
    // h.insertKey(12);
    // h.insertKey(8);
    // h.insertKey(2);
    // h.insertKey(14);
    for (int i = (5/2) ; i >= 0; i--)
    {
        max_heapify(arr, i,  5);
    }

    for (int i =0  ; i < 5 ; i++)
    {
        cout << arr[i] << " ";
    }

    // Printing the current size
    // of the heap.
    cout << "The current size of the heap is "
         << h.curSize() << "\n";
}
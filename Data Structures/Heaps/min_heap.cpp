#include <bits/stdc++.h>
using namespace std;

class MinHeap {

    public: 
        int * arr;

        int maxSize;

        int heapSize;

        MinHeap(int maxSize);

        void MinHeapify(int i);

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

        int removeMin();

        void decreaseKey(int i, int newVal);

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


MinHeap::MinHeap(int totSize)
{
    heapSize = 0;
    maxSize = totSize;
    arr = new int[totSize];
    // heapSize = 5;
    // arr[heapSize] = {32,324, 23, 12, 943};
}

void MinHeap::insertKey(int x)
{
    if (heapSize == maxSize)
    {
        cout << "Heap Overflow\n";
        return;
    }

    heapSize++;
    int i = heapSize - 1;
    arr[i] = x;

    while (i != 0 && arr[parent(i)] > arr[i])
    {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int newVal)
{
    arr[i] = newVal;
    while (i != 0 && arr[parent(i)] > arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::removeMin()
{
    if (heapSize <= 0)
    {
        return INT_MIN;
    }

    if (heapSize == 1) {
        heapSize--;
        return arr[0];
    }

    int root = arr[0];
    arr[0] = arr[heapSize - 1];
    heapSize--;

    MinHeapify(0);
    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    removeMin();
}
void MinHeap::MinHeapify(int i)
{
    int l = lChild(i);
    int r = rChild(i);
    int smallest = i;
    if (l < heapSize && arr[l] < arr[smallest])
    {
        smallest = l;
    }
    if (r < heapSize && arr[r] < arr[smallest])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        MinHeapify(smallest);
    }

}

void max_heapify (int Arr[], int i, int N)
{
        int left = 2*i; //left child
        int right = 2*i +1;   
        int smallest = i;        //right child
        if(left< N and Arr[left] < Arr[i] )
              smallest = left;
        else
             smallest = i;
        if(right < N and Arr[right] < Arr[smallest] )
            smallest = right;
        if(smallest != i )
        {
            swap (Arr[i] , Arr[smallest]);
            max_heapify (Arr, smallest,N);
        } 
}

// void build_MinHeap (int Arr[ ], int N)
// {
//     for(int i = N/2 ; i >= 1 ; i-- )
//     {
//         max_heapify (Arr, i) ;
//     }
// }
int main()
{
    MinHeap h(15); 

    int k, i, n = 6, arr[5] = {32, 12, 3, 54, 43};
    // h.arr;
    h.insertKey(3);
    h.insertKey(10);
    h.insertKey(12);
    h.insertKey(8);
    h.insertKey(2);
    h.insertKey(14);

    for (int i =0  ; i < h.heapSize ; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.decreaseKey(3, 16);
    for (int i =0  ; i < h.heapSize ; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    h.deleteKey(3);
        for (int i =0  ; i < h.heapSize ; i++)
    {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    cout << "The current size of the heap is "
         << h.curSize() << "\n";
}
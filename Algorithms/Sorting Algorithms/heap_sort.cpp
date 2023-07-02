#include <bits/stdc++.h>
using namespace std;

class MaxHeap {

    public: 
        int * arr;

        int maxSize;

        int heapSize;

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

void MaxHeap::increaseKey(int i, int newVal)
{
    arr[i] = newVal;
    while (i != 0 && arr[parent(i)] < arr[i]) {
        swap(arr[i], arr[parent(i)]);
        i = parent(i);
    }
}

int MaxHeap::removeMax()
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

    MaxHeapify(0);
    return root;
}

void MaxHeap::deleteKey(int i)
{
    increaseKey(i, INT_MAX);
    removeMax();
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


int heap_sort(vector<int>& arr, int n)
{
    MaxHeap heap(n);
    for (int i = 0 ; i < n ; i++)
        heap.insertKey(arr[i]);
    int index = n-1;
    while (heap.heapSize)
    {
        arr[index] = heap.getMax();
        index--;
        heap.removeMax();
    }

    return 1;
}

int print_arr(vector<int> arr, int n)
{
    for (int i = 0; i < n ; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vector<int> arr = {20,5, 7, 25, 34, 32, 34};
    heap_sort(arr, 7);
    print_arr(arr, 7);
}
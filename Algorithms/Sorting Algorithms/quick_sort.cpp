#include <bits/stdc++.h>
using namespace std;

int swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
    return 1;
}


int partition(vector<int>& arr, int l, int r)
{
    int pivot = arr[r];

    int i = l -1;

    for (int j = l ; j < r ; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return (i+1);
}
int sort_quick(vector<int>& arr, int l, int r)
{
    if (l < r) {
        int pi = partition(arr, l, r);

        sort_quick(arr, l, pi-1);
        sort_quick(arr, pi+1, r);
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

int main(int argc, char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vector<int> arr = {20,5, 7, 25, 34, 32, 34};
    sort_quick(arr, 0, 6);
    print_arr(arr, 7);
    return 0;
}

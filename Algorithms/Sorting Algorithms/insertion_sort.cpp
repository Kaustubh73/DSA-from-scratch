#include <bits/stdc++.h>
using namespace std;

int swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
    return 1;
}

int sort_insertion(vector<int>& arr, int n)
{
    int i, key, j;
    for (i = 1; i < n ;i++)
    {
        j = i;
        key = arr[i];

        while ((j >= 1) && (arr[j-1] > key))
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = key;
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
    sort_insertion(arr, 7);
    print_arr(arr, 7);
    return 0;
}

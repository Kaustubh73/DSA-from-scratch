#include <bits/stdc++.h>
using namespace std;

int swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
    return 1;
}

int sort_selection(vector<int>& arr, int n)
{
    int i, j, min_idx;

    for (i = 0 ; i < n - 1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            swap(arr[min_idx], arr[i]);
        }
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
    sort_selection(arr, 7);
    print_arr(arr, 7);
    return 0;
}

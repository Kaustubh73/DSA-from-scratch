#include <bits/stdc++.h>
using namespace std;

int lin_search(vector<int> arr, int x, int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int bin_search(vector<int> arr, int x, int n)
{
    int start = 0;
    int end = n-1;
    int mid = start + (end - start) /2;
    while (start <= end)
    {
        if (arr[mid] > x)
        {
            end = mid-1;
            mid = start + (end - start)/2;
        }
        else if (arr[mid] < x)
        {
            start = mid+1;
            mid = start + (end - start)/2;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int insert(vector<int>& arr, int n, int x, int pos)
{
    int idx = pos;
    arr.push_back(arr[n-1]);
    for (int i = n -1 ; i >= idx; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[idx] = x;
    return n+1;
}

int deleteElem(vector<int>& arr, int n, int x)
{
    int i = 0;
    for (i = 0 ; i < n ; i++)
    {
        if (arr[i] == x)
            break;
    }
    if (i == n)
    {
        return n;
    }
    for (int j = i ; j < n -1; j++)
    {
        arr[j] = arr[j+1];
    }
    return n-1;
}

int main(int argc, char * argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    vector<int> arr = {20,5, 7, 25};
    int x = 7;
    cout << bin_search(arr, x, 4) << endl;
    return 0;
}

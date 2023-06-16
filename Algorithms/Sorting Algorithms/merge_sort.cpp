#include <bits/stdc++.h>
using namespace std;

int swap(int & a, int & b)
{
    int c = a;
    a = b;
    b = c;
    return 1;
}


int merge(vector<int>& arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (i = 0 ; i < n1; i++)
        L[i] = arr[l+i];
    for (j = 0 ; j < n2; j++)
        R[j] = arr[m+1+j];
    
    i = 0, j = 0, k = l;
    while ((i < n1) && (j < n2))
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
int sort_merge(vector<int>& arr, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        sort_merge(arr, l, m);
        sort_merge(arr, m+1, r);

        merge(arr, l, m, r);
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
    sort_merge(arr, 0, 6);
    print_arr(arr, 7);
    return 0;
}

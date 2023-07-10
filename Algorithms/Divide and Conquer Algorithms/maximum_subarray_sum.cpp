#include <bits/stdc++.h>
using namespace std;

int maxCrossingSum(vector<int>& arr, int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;

    for (int i = mid ; i >= low ; i--)
    {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
        }
    }
    int rightSum = INT_MIN;
    sum = 0; 
    for (int i = mid + 1; i <= high ; i++)
    {
        sum += arr[i];
        if (sum > rightSum)
        {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSubarraySum(vector<int>& arr, int low, int high) {
    if (low == high) {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int leftSum = maxSubarraySum(arr, low, mid);
    int rightSum = maxSubarraySum(arr, mid+1, high);

    int crossingSum = maxCrossingSum(arr, low, mid, high);

    return max({leftSum, rightSum, crossingSum});
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = maxSubarraySum(arr, 0, arr.size() - 1);
    cout << "Maximum subarray sum: " << maxSum << endl;
}
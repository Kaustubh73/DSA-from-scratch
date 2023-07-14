#include <bits/stdc++.h>
using namespace std;

void subsetSumHelper(const vector<int>& nums, int target, vector<int>& currentSubset, int currentIndex, int currentSum)
{
    if (currentSum == target) {
        for (int num : currentSubset) {
            cout << num << " " ;
        }
        cout << endl;
    }

    if (currentSum > target || currentIndex == nums.size())
        return;
    
    currentSubset.push_back(nums[currentIndex]);
    subsetSumHelper(nums, target, currentSubset, currentIndex + 1, currentSum + nums[currentIndex]);

    currentSubset.pop_back();
    subsetSumHelper(nums, target, currentSubset, currentIndex + 1, currentSum);
}



void subsetSum(const vector<int>& nums, int target)
{
    vector<int> currentSubset;

    subsetSumHelper(nums, target, currentSubset, 0, 0);
}

int main() {
    vector<int> nums = {2, 4, 6, 8, 10};
    int target = 16;

    subsetSum(nums, target);
    return 0;
}
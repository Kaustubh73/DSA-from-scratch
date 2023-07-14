#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int sum)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int> (sum+1, 0));

    for (int i = 0 ; i < n; i++)
        dp[i][0] = 1;
    
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 1 ; j <= sum; j++)
        {
            int x = (j - coins[i] >= 0) ? dp[i][j - coins[i]] : 0;
            int y = (i >= 1) ? dp[i-1][j] : 0;
            dp[i][j] = x + y;
        }
    }
    return dp[n-1][sum];
}

int main() {
    vector<int> coins = { 1, 2, 3};
    int sum = 4;
    cout << coinChange(coins, sum) << endl;
    return 0;
}
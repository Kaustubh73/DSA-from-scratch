#include <bits/stdc++.h>
using namespace std;


int knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();

    vector<vector<int>> dp(n+1, vector<int> (W+1, 0));
    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= W ; ++j)
        {
            if (wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);

            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}


int main()
{

    vector<int> weights = {10,20,30};
    vector<int> values = {60,100,120};
    int W = 50;

    cout << knapsack(W, weights, values) << endl;
    cout << fractional_knapsack(W, weights, values) << endl;
    return 0;
}
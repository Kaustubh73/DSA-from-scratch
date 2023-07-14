#include <bits/stdc++.h>
using namespace std;

int numPaths(int n ,int m)
{
    vector<vector<int>>dp (n, vector<int> (m, 0));

    for (int i = 0 ; i < n ; i++)
    {
        dp[i][0] = 1;
    }

    for (int j = 0 ; j < m ; j++)
    {
        dp[0][j] = 1;
    }

    for (int i = 1 ; i < n ; i++)
    {
        for (int j = 1 ; j < m ; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

int maxSumPath(vector<vector<int>>& cost, int n, int m)
{
    vector<vector<int>> dp (n, vector<int> (m, 0));

    dp[0][0] = cost[0][0];
    for (int i = 1; i < n ; i++)
    {
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
    for (int j = 1; j < m ; j++)
    {
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }    
    for (int i = 1; i < n ; i++)
    {
        for (int j = 1 ; j < m ; j++)
        {
            if (i != 0 || j != 0)
                dp[i][j] = cost[i][j] + max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}

int main() {
    vector<vector<int>> cost = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };
    cout << maxSumPath(cost, 3, 3) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int LCS(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    string common = "";
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    for (int i = 1 ; i <= m ; ++i)
    {
        for (int j = 1;  j <= m ; ++j)
        {
            if (text1[i-1] == text2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                common += text1[i-1];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << "LCS = " << common << endl;
    return dp[m][n];
}

int main() {
    string text1 ="ABCDGH";
    string text2 = "AEDFHR";

    cout << LCS(text1, text2) << endl;
}
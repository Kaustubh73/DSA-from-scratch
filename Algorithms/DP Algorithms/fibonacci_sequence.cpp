#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n, vector<int>& fibs) {
    if (n <= 1)
        return n;
    if (fibs[n] != -1)
        return fibs[n];
    fibs[n] = fibonacci(n-1, fibs) + fibonacci(n-2, fibs);
    return fibs[n];
}

int fibonacciBottomUp(int n) {
    if (n <= 1)
        return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n ; ++i)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main(int argc, char const *argv[])
{
    int n = 2;
    vector<int> fibs(n+1, -1);
    cout << fibonacci(n, fibs) << endl;

    return 0;
}

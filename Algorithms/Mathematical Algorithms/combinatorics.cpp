#include <bits/stdc++.h>

using namespace std;

int FactPower(int n, int k)
{
    int res =0;
    while (n) {
        n /= k;
        res += n;
    }
    return res;
}

int C(int n, int k)
{
    int res = 1;

    for (int i = n - k  +1 ; i <= n ; ++i)
    {
        res *= i;
    }
    for (int i = 2 ; i <= k ; ++i)
    {
        res /= i;
    }
    return res;
}

vector<int> catalan(int n){
    vector<int> cats(n+1);
    cats[0] = cats[1] = 1;
    for (int i = 2 ; i<= n; i++)
    {
        cats[i] = 0;
        for (int j = 0; j < i ; j++)
        {
            cats[i] += (cats[j] * cats[i-j-1]);
        }
    }
    return cats;
}

int noOfRelPrimes(int n, int r){
    vector<int> p;
    for (int i =2 ; i*i <= n; ++i)
    {
        if (n % i == 0)
        {
            p.push_back(i);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        p.push_back(n);
    
    int sum = 0;
    for (int msk = 1; msk < (1<<p.size()) ; ++msk)
    {
        int mult = 1, bits =0;
        for (int i = 0; i < (int)p.size(); ++i)
        {
            if (msk & (1<<i))
            {
                ++bits;
                mult *= p[i];
            }
            int cur = r / mult;
            if (bits % 2 == 1)
            {
                sum += cur;
            }
            else
                sum -= cur;
        }
    }

    return r - sum;
}

int calculateStirlingNumber2ndKind(int n, int k) {
    vector<vector<int>> stirling(n+1,vector<int>(k+1,0));

    for (int i = 0 ; i <= n ; i++)
    {
        for (int j = 0 ; j <= min(i,k) ; j++)
        {
            if (j == 0 || j == i)
                stirling[i][j] = 1;
            else
                stirling[i][j] = j * stirling[i-1][j] + stirling[i-1][j-1];
        }
    }
    return stirling[n][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n = 5;
    int k = 3;
    int result = calculateStirlingNumber2ndKind(n, k);
    std::cout << "Stirling number S(" << n << ", " << k << ") = " << result << std::endl;

	return 0;
}
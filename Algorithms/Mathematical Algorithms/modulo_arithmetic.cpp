#include <bits/stdc++.h>
using namespace std;

int factmod(int n, int p) {
    vector<int> f(p);
    f[0] = 1;
    for (int i = 1; i < p ; i++)
    {
        f[i] = f[i-1] * i % p;
    }
    int res = 1;
    while (n > 1) {
        if ((n/p) % 2)
            res = p - res;
        res = res * f[n%p] % p;
        n /= p;
    }
    return res;
}

int multiplicityFact(int n, int p)
{
    int count = 0;
    while (n)
    {
        n /= p;
        count += n;
    }
    return count;
}

long long binpow(long long a, long long n, int m)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % m;
        a = a * a % m;
        n >>= 1;
    }
    return res;
}

int discreteLog(int a, int b, int m) {
    a %= m, b%= m;
    int k = 1, add =0 , g;
    while ((g = gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }
    if (a == 0)
        return b == 0 ? 1 : -1;
    int n = sqrt(m) + 1;
    map<int, int> vals;
    for (int p = 1; p <= n ; ++p)
        vals[binpow(a, p*n, m)] = p;
    for (int q = 0 ; q <= n; ++q)
    {
        long long cur = (binpow(a, q, m) * b) % m;
        if (vals.count(cur))
        {
            int ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
int main()
{
    cout << factmod(14, 5) << endl;
    cout << multiplicityFact(14, 2) << endl;
    cout << discreteLog(3, 6, 7) << endl;
    return 0;
}
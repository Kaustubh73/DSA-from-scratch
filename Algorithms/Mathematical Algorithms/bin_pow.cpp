#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long n)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

long long binmul(long long a, long long b)
{
    long long res = 0;
    while (b > 0)
    {
        if (b & 1)
            res = res + a;
        a = a + a;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout << binpow(3, 13) << endl;
    cout << binmul(3, 13) << endl;
    return 0;
}
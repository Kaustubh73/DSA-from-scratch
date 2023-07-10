#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;
bool isPrime(int n)
{
        if (n <= 1) return false;
    for (int i = 2 ; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

long long binpow(long long a, long long n, long long m)
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

bool probablyPrimeFermat(int n, int iter=5)
{
    if (n < 4)
        return n == 2 || n == 3;
    
    for (int i =0 ; i < iter; i++)
    {
        int a = 2 + rand() % (n-3);
        if (binpow(a, n-1, n) != 1)
            return false;
    }
    return true;
}

bool checkComposite(u64 n, u64 a, u64 d, int s)
{
    u64 x = binpow(a, d, n);
    if (x == 1 || x == n - 1)
    {
        return false;
    }
    for (int r =1 ; r < s; r++)
    {
        x = (u128) x * x % n;
        if (x == n-1)
            return false;
    }
    return true;
}

bool MillerRabin(u64 n, int iter =5)
{
    if (n < 4)
        return n == 2 || n == 3;
    
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int i = 0; i < iter ; i++)
    {
        int a = 2 + rand() % (n-3);
        if (checkComposite(n, a, d, s))
            return false;
    }
    return true;
}

bool deterministicMillerRabin(u64 n, int iter =5)
{
    if (n < 4)
        return n == 2 || n == 3;
    
    int s = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37})
    {
        if (n == a)
            return true;
        if (checkComposite(n, a, d, s))
            return false;
    }
    return true;
}

vector<long long> trialDivision1(long long n)
{
    vector<long long> factors;
    for (long long d = 2; d * d <= n ; d++)
    {
        while (n % d == 0)
        {
        factors.push_back(d);
        n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

vector<long long> trialDivision2(long long n)
{
    vector<long long> factors;
    while (n % 2 == 0)
    {
        factors.push_back(2);
        n /= 2;
    }
    for (long long d = 3 ; d*d <= n ; d+=2)
    {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

vector<long long> trialDivision3(long long n)
{
    vector<long long> factors;
    for (int d : {2, 3, 5})
    {
        while (n % d == 0)
        {
            factors.push_back(d);
            n /= d;
        }
    }

    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7 ; d * d <= n ; d += increments[i++])
    {
        while (n % d == 0) {
            factors.push_back(d);
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

int fermat(int n)
{
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    int b = round(sqrt(b2));
    while (b * b != b2)
    {
        a = a + 1;
        b2 = a * a - n;
        b = round(sqrt(b2));
    }
    return a - b;

}

int main()
{
    int n = 124;
    vector<long long> factors = trialDivision3(n);
    for (auto i : factors)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << fermat(23) << endl;
    return 0;
}
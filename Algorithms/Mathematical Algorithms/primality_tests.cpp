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
int main()
{
    cout << MillerRabin(12) << endl;
    cout << MillerRabin(1) << endl;
    cout << MillerRabin(3) << endl;
    cout << MillerRabin(561) << endl;

    return 0;
}
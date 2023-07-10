#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    while (b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;

}

int bin_gcd(int a, int b)
{
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    while (b)
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    }
    return a << shift;
}
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

// gcd = a*x + b*y
int extended_euclid(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extended_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modular_inverse(int a, int m)
{
    int x, y;
    int g = extended_euclid(a, m, x, y);
    if (g != 1)
        return -1;
    else
    {
        x = (x % m + m) % m;
        return x;
    }
}

int lin_congruence_sol(int a,int b, int n)
{
    int x, k;
    int g = extended_euclid(a, n, x, k);
    if (g == 1)
        return (b * modular_inverse(a, n));
    else if (g % b == 0)
    {
        return lin_congruence_sol(a/g, b/g, n/g);
    } 
    return -1;
}
int main()
{
    cout << bin_gcd(12, 8) << endl;
    cout << lcm(12, 8) << endl;
    int x, y;
    cout << extended_euclid(12, 8, x, y) << endl;
    modular_inverse(9, 5);
    cout << lin_congruence_sol(3, 2, 5) << endl;
    return 0;
}
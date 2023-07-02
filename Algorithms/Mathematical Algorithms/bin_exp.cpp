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
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main()
{
    cout << bin_gcd(12, 8) << endl;
    cout << lcm(12, 8) << endl;
    return 0;
}
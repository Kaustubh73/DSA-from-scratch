#include <bits/stdc++.h>

using namespace std;

long long splitMultiply(long long x, long long y, long long n)
{
    if (n == 1)
        return x * y;
    else
    {
        long long m, a, b, c, d, e, f, g, h;
        m = n / 2;
        long long power = static_cast<long long>(pow(10, m));
        a = x / power;
        b = x % power;
        c = y / power;
        d = y % power;
        cout << a << " " << b << " " << c << " " << d << endl;
        e = splitMultiply(a, c, m);
        f = splitMultiply(b, d, m);
        g = splitMultiply(a, d, m);
        h = splitMultiply(b, c, m);
        return power * power * e + power * (g + h) + f;
    }
}   

long long fastMultiply(long long x, long long y, long long n)
{
    if (n == 1)
        return x * y;
    else
    {
        long long m, a, b, c, d, e, f, g;
        m = n / 2;
        long long power = static_cast<long long>(pow(10, m));
        a = x / power;
        b = x % power;
        c = y / power;
        d = y % power;
        cout << a << " " << b << " " << c << " " << d << endl;
        e = fastMultiply(a, c, m);
        f = fastMultiply(b, d, m);
        g = fastMultiply(a-b, c-d, m);
        return power * power * e + power * (e + f - g) + f;
    }
}   

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int x = 1000;
    int y = 3431;
    cout << fastMultiply(x, y, 4) << endl;
	return 0;
}
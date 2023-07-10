#include <bits/stdc++.h>
using namespace std;

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

bool find_any_solution(int a, int b, int c, int&x0, int&y0, int& g)
{
    g = extended_euclid(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


int main()
{
    int a, b, c, x0, y0, g;
    a = 10;
    b = 2;
    c = 22;
    if (find_any_solution(a, b, c, x0, y0, g))
        cout << x0 << " " << y0 << " " << g << endl;
    else 
        cout << "NO SOLUTION" << endl;
    return 0;
}
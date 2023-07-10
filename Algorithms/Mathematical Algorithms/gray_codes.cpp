#include <bits/stdc++.h>
using namespace std;

int g(int n)
{
    return n ^ (n >> 1);
}

int revG(int g)
{
    int n = 0;
    for (; g ; g >>= 1)
        n ^= g;
    return n;
}

int main()
{
    cout << g(5) << endl;
    cout << revG(7) << endl;
    return 0;
}
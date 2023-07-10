#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n ; i++)
    {
        int tmp = a + b;
        a = b;
        b = tmp;
    }
    return a;
}

class matrix {
    public:
        long long mat[2][2];
};

matrix mul(matrix &a, matrix &b)
{
    matrix c;
    for (int i = 0 ; i < 2; i++)
    {
        for (int j = 0 ; j < 2 ; j++)
        {
            c.mat[i][j] = 0;
            for (int k = 0 ; k < 2 ; k++)
            {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}
matrix matpow(matrix base, long long n) {
    matrix ans{ {
        {1, 0},
        {0, 1}
    }};
    while (n) {
        if (n & 1)
            ans = mul(ans, base);
        base = mul(base, base);
        n >>= 1;
    }
    return ans;
}

long long matfib(int n) {
    matrix base{ {
        {1, 1},
        {1, 0}
    }};
    return matpow(base, n).mat[0][1];
}
int main()
{
    cout << fib(4) << " " << matfib(4) << endl;
    return 0;
}
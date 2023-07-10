#include <bits/stdc++.h>
using namespace std;

int phi(int n)
{
    int result = n;
    for (int i = 2 ; i * i <= n ; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    if (n > 1)
        result -= result / n;
    return result;
}

vector<int> phiFrom1toN(int n)
{
    vector<int> phi(n+1);
    for (int i = 0 ; i <= n; i++)
        phi[i] = i;
    
    for (int i = 2; i <= n ; i++)
    {
        if (phi[i] == i) {
            for (int j = i ; j <= n ; j += i)
            {
                phi[j] -= phi[j] / i;
            }
        }
    }
    return phi;
}
vector<int> phiFrom1toNDivSum(int n) {
    vector<int> phi(n+1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n ; i++)
    {
        phi[i] = i-1;
    }
    for (int i= 2 ; i <= n ; i++)
    {
        for (int j = 2 * i; j <= n ; j+= i)
        {
            phi[j] -= phi[i];
        }
    }
    return phi;
}
int main()
{
    cout << phi(3) << endl;
    vector<int> phis = phiFrom1toN(12);
    for (int i = 1 ; i <= 12 ; i++)
    {
        cout << phis[i] << " ";
    }
    cout << endl;
    vector<int> phiss = phiFrom1toNDivSum(12);
    for (int i = 1 ; i <= 12 ; i++)
    {
        cout << phiss[i] << " ";
    }
    cout << endl;
    return 0;
}
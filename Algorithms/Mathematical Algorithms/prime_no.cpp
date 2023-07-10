#include <bits/stdc++.h>
using namespace std;

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

vector<int> simpleSieve(int n)
{
    vector<bool> is_prime(n+1, true);
    vector<int> ans; 
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n ; i++)
    {
        if (is_prime[i] && (long long)i * i <= n) {
            for (int j = i * i ; j <= n; j+= i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (is_prime[i])
            ans.push_back(i);
    }
    return ans;
}

vector<int> segmentedSieve(int n)
{
    int limit = floor(sqrt(n)) + 1;
    vector<int> primes;
    primes = simpleSieve(limit);
    vector<int> ans = primes;
    int low = limit;
    int high = 2 * limit;
    
    while (low < n)
    {
        if (high >= n)
            high = n;
        
        vector<bool> is_prime(limit + 1, true);

        for (int i = 0 ; i < primes.size() ; i++)
        {
            int start = floor(low / primes[i]) * primes[i];
            if (start < low)
                start += primes[i];
            
            for (int j = start; j < high ; j+= primes[i])
            {
                is_prime[j - low] = false;
            }

            for (int k = low;  k < high ; k++)
            {
                if (is_prime[k - low] == true && k <= n)
                    ans.push_back(k);
            }

            low += limit;
            high += limit;
        }
    }
    return ans;
}

vector<int> linearSieve(int n)
{
    vector<int> minFac(n+1);
    vector<int> primes;

    for (int i = 2; i <= n; ++i)
    {
        if (minFac[i] == 0)
        {
            minFac[i] = i;
            primes.push_back(i);
        }
        for (int j = 0 ; i * primes[j] <= n ; ++j)
        {
            minFac[i * primes[j]] = primes[j];
            if (primes[j] == minFac[i])
                break;
        }
    }
    return primes;
}

int main()
{
    cout << isPrime(12) << endl;
    cout << isPrime(1) << endl;
    cout << isPrime(3) << endl;
    cout << isPrime(81) << endl;
    vector<int> ans = linearSieve(15);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
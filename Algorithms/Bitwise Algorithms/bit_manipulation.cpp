#include <bits/stdc++.h>
using namespace std;

void setBit(int& num, int pos)
{
    num |= (1 << pos);
}

void unsetBit(int& num, int pos)
{
    num &= (~(1 << pos));
}

void toggleBit(int& num, int pos)
{
    num ^= (1 << pos);
}

bool isSet(int& num, int pos)
{
    bool bit = num & (1 << pos);
    return bit;
}

int XORfrom1to(int n) 
{
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;

    return 0;
}

int findXOROfSubsets(vector<int> arr, int n)
{
    if (n == 1)
        return arr[0];
    else
        return 0;
}

bool isPowerOfTwo(int n)
{
    return n && (!(n & (n-1)));
}

int countSetBits(int n)
{
    int count = 0;
    while (n) {
        count += n & 1;

        n >>= 1;
    }
    return count;
}

int countUnSetBits(int n)
{
    int count = 0;
    while (n)
    {
        if ((n & 1) == 0)
            count++;
        n >>= 1;
    }
    return count;
}

int posOfRightmostBit(int n) {
    if (n & 1) {
        return 1;
    }

    n = n ^ (n & (n-1));

    int pos = 0;
    while (n) {
        n = n >> 1;
        pos++;
    }
    return pos;
}

int findOdd(vector<int> arr, int n)
{
    int res = 0;
    for (int i = 0; i < n ; i++)
    {
        res ^= arr[i];
    }
    return res;
}

int countValues(int n)
{
    int unset_bits = countUnSetBits(n);
    return 1 << unset_bits;
}

int swap(int& a, int& b)
{
    a ^= b;
    b ^= a;
    a ^= b;
    return 0;
}

bool allBitsAreSet(unsigned int n)
{
    if (((n+1) & n) == 0)
        return true;
    return false;
}

bool bitsAreInAltOrder(unsigned int n)
{
    unsigned int num = n ^ (n >> 1);
    return allBitsAreSet(num);
}

void stripLowestSetBit(int& num)
{
    num = num & (num - 1);
    return;
}

int getLowestSetBit(int num)
{
    return num & (-num);
}

void clearBitsFromLSBTo(int& num, int i)
{
    int mask = ~((1 << i + 1) - 1);
    num &= mask;
    return;
}

void clearBitsFromMSBTo(int& num, int i)
{
    int mask = (1 << i) - 1;
    num &= mask;
}

int log2(int x)
{
    int res = 0;
    while (x >>= 1)
        res++;
    return res;
}

int clearRangeItoJ(int n, int i, int j)
{
    int a = 1 << (j + 2);
    int b = (1 << i) - 1;
    int mask = a | b;
    int ans = n & mask;
    return ans;
}

int replaceBits(int n, int m, int i, int j)
{
    int n1;
    n1 = clearRangeItoJ(n, i, j);
    int ans = n1 | (m << i);
    return ans;
}

int decToBin(int n)
{
    int ans = 0, p = 1;
    while (n > 0)
    {
        int last_bit = (n & 1);
        ans += p * last_bit;

        p = p * 10;
        n = n >> 1;
    }

    return ans;
}

int main() {
    int num = 215;
    cout << XORfrom1to(num) << endl;
    cout << isPowerOfTwo(num) << endl;
    cout << countSetBits(num) << endl;
    vector<int> arr = {12,32,32,12,43};
    cout << findOdd(arr, 5) << endl;
    cout << countValues(num) << endl;
    cout << findXOROfSubsets(arr, 5) << endl;
    int a = 5, b = 7;
    swap(a, b);
    cout << a << " " << b << endl;
    cout << getLowestSetBit(num) << endl;
    cout << log2(num) << endl;
    cout << replaceBits(256, 23, 2, 6) << endl;
    cout << decToBin(256) << endl;
    return 0;
}   

// a + b = a|b + a&b or a|b
//__builtin_ctz(x)
//__builtin_clz(x)
//__builtin_popcount(x)
// 101011100
// 10111
// 
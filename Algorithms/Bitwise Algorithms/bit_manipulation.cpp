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

int posOfRightmostBit(int num) {
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


int main() {
    int num = 4;
    cout << XORfrom1to(num) << endl;
    cout << isPowerOfTwo(num) << endl;
    cout << countSetBits(num) << endl;
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void towerOfHanoi(int n, char source, char destination, char intermediate)
{
    if (n > 0)
    {
        towerOfHanoi(n - 1, source, intermediate, destination);
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        towerOfHanoi(n - 1, intermediate, destination, source); 
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');

	return 0;
}
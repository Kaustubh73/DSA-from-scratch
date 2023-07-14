#include <bits/stdc++.h>
using namespace std;

void printMaxSubSquare(vector<vector<int>>& grid, int m, int n)
{
    vector<vector<int>> square (m, vector<int> (n, 0));

    for (int i = 0 ; i < m ; i++)
        square[i][0] = grid[i][0];
    for (int j = 0 ; j < n ; j++)
        square[0][j] = grid[0][j];

    for (int i = 1 ; i < m ; i++)
    {
        for (int j = 1; j < m ; j++)
        {
            if (grid[i][j] == 1)
                square[i][j] = min({square[i][j-1], square[i-1][j], square[i-1][j-1]}) + 1;
            else
                square[i][j] = 0;
        }
    }

    int max_square = square[0][0];
    int max_i = 0, max_j = 0;
    for (int i =0  ;i < m ; i++)
    {
        for (int j = 0 ; j < n ; j++)
        {
            if (max_square < square[i][j])
            {
                max_square = square[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    cout << max_square << endl;
    for (int i = max_i ; i > max_i - max_square ; i--)
    {
        for (int j = max_j ; j > max_j - max_square ; j--)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int m = 6, n = 5;
    vector<vector<int>> grid = { { 0, 1, 1, 0, 1 }, { 1, 1, 0, 1, 0 },
                     { 0, 1, 1, 1, 0 }, { 1, 1, 1, 1, 0 },
                     { 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 } };
    printMaxSubSquare(grid, m, n);
    return 0;
}

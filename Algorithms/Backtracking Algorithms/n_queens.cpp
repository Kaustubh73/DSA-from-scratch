#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    for (int i =0 ; i < row ; i++)
    {
        if (board[i][col] == 1)
            return false;
    }
    
    for (int i =row, j = col ; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row, j = col ; i >= 0 && j < n ; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void solveNQueensUtil(vector<vector<int>>& board, int row, int n, vector<vector<string>>& solutions)
{
    if (row == n) {
        vector<string> solution;
        for (int i = 0 ; i < n ; i++)
        {
            string rowString = "";
            for (int j = 0 ; j < n ; j++) 
            {
                if (board[i][j] == 1)
                    rowString += 'Q';
                else
                    rowString += '.';
            }
            solution.push_back(rowString);
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0 ; col < n ; col++)
    {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            solveNQueensUtil(board, row + 1, n, solutions);

            board[row][col] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));

    vector<vector<string>> solutions;

    solveNQueensUtil(board, 0, n, solutions);

    return solutions;
}

int main() {

    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;
    int i = 1;
    for (const auto& solution : solutions)
    {
        cout << "Solution " << i++ << endl;
        for (const auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
    return 0;
}
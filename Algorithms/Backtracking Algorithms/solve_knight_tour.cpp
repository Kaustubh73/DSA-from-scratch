#include <bits/stdc++.h>
using namespace std;

const int N = 8;

const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isValidMove(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

void printTour(vector<vector<int>>& board)
{
    for (int i =0 ; i < N ; i++)
    {
        for (int j = 0 ; j < N ; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl;
    }
}

bool solveKnightTour(int x, int y, int moveCount, vector<vector<int>>& board) {
    if (moveCount == N * N) {
        printTour(board);
        return true;
    }

    for (int i = 0 ; i < 8 ; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (isValidMove(nextX, nextY, board)) {
            board[nextX][nextY] = moveCount;

            if (solveKnightTour(nextX, nextY, moveCount + 1, board))
                return true;

            board[nextX][nextY] = -1;
        }
    }

    // Backtrack if all moves have been exhausted from the current position
    return false;
}

int main() {
    vector<vector<int>> board(N, vector<int>(N, -1));

    int startRow = 3;
    int startCol = 0;
    int moveCount = 0;

    board[startRow][startCol] = moveCount;

    if (!solveKnightTour(startRow, startCol, moveCount + 1, board)) {
        cout << "No solution found." << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;  

const int n = 8;

bool isSafe(const vector<vector<int>>& board, int row, int col) {

    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col) {
    if (col >= n) {
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQueens(board, col + 1)) {
                return true;
            }

            board[i][col] = 0;
        }
    }

    return false;
}

void print(const vector<vector<int>>& board) {
    for (const auto& row : board) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (!solveNQueens(board, 0)) {
        cout << "No solutions" << endl;
    } else {
        print(board);
    }

    return 0;
}

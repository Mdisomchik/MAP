#include <Windows.h>
#include <vector>

using namespace std;

const int n = 8;
const int squareSize = 60;

vector<int> queensPlacement(n, -1);

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
                queensPlacement[col] = i; 
                return true;
            }

            board[i][col] = 0; 
        }
    }
    return false;
}

void drawChessboard(HDC hdc) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            RECT square = { j * squareSize, i * squareSize, (j + 1) * squareSize, (i + 1) * squareSize };

            if ((i + j) % 2 == 0) {
                FillRect(hdc, &square, CreateSolidBrush(RGB(255, 206, 158)));
            }
            else {
                FillRect(hdc, &square, CreateSolidBrush(RGB(209, 139, 71))); 
            }
        }
    }
}

void drawQueens(HDC hdc, const vector<int>& queensPlacement) {
    for (int i = 0; i < n; i++) {
        if (queensPlacement[i] != -1) {
            RECT queen = { queensPlacement[i] * squareSize, i * squareSize, (queensPlacement[i] + 1) * squareSize,
                          (i + 1) * squareSize };
            FillRect(hdc, &queen, CreateSolidBrush(RGB(255, 0, 0))); 
        }
    }
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        drawChessboard(hdc);
        drawQueens(hdc, queensPlacement);

        EndPaint(hwnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

int main() {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solveNQueens(board, 0)) {
        MessageBox(NULL, L"No solutions", L"Error", MB_OK | MB_ICONERROR);
        return 1;
    }

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = L"NQueensWindowClass";
    RegisterClass(&wc);

    HWND hwnd = CreateWindow(L"NQueensWindowClass", L"N-Queens Visualization", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, n * squareSize, n * squareSize, NULL, NULL, GetModuleHandle(NULL), NULL);

    ShowWindow(hwnd, SW_SHOWNORMAL);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

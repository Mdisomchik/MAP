#include <iostream>
#include <vector>

using namespase std;

const int n = 8;

//first function
bool ifSafe(const vector<vector<int>>& board, int row, int col){

// same left row 
for (int i = 0; i < col; i ++){
if (board[row][i] == 1) {
return false;
   }
}

//upper left diagonal
for (int i = row, j = col;i >= 0 && j >= 0; i--, j--){
if (board[i][j] == 1){
return false;
  }
}
   for (int i = row, j = col; i < n && j >= 0; i++, j--)
      {
         if (board[i][j] == 1)
         {
            return false;
         }
      }
   return true;
            }

bool solveNQueens(vector <int>> & board, int col){
if (col >=n){
return true;
}

for (int i = 0; i < n;i++){
if (ifSafe(board,i,col)){
board[i][col] = 1;
if(solveQueens(board,col + 1)){
return true;
}
board[i][col] = 0;
}
}


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

#define Size 9
bool isEmpty(vector<vector<int>> &sudoku, int &row, int &col)
{
    for (row= 0; row < Size; row++)
    {
        for (col=0; col < Size; col++)
        {
            if (sudoku[row][col] == 0)
            {
                return true;
            }
        }
    }
    return false;
}
bool usedInRow(vector<vector<int>> &sudoku, const int row, int fill) {
    for (int j=0; j < Size; j++) {
        if (sudoku[row][j] == fill) {
            return true;
        }
    }
    return false;
}
bool usedInCol(vector<vector<int>> &sudoku, const int col, int fill) {
    for (int i=0; i < Size; i++) {
        if (sudoku[i][col] == fill) {
            return true;
        }
    }
    return false;
}
bool usedInBox(vector<vector<int>> &sudoku, int row, int col, int fill){
    row=row-row%3;
    col=col-col%3;
    for (int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            if(sudoku[i+ row][j + col] == fill) {
                return true;
            }
        }
    }
    return false;
}
bool isSafe(vector<vector<int>> &sudoku, const int row, const int col, int fill) {

    return (!usedInRow(sudoku, row, fill) && !usedInCol(sudoku, col, fill) && !usedInBox(sudoku,row,col, fill));
}
bool solveSudoku (vector<vector<int>> &sudoku) {
    int row, col;
    if (!isEmpty(sudoku, row, col)) {
        return true;
    }
    for(int i=1;i<=9;i++) {
        if(isSafe(sudoku,row,col,i)) {
            sudoku[row][col]=i;
            if(solveSudoku(sudoku)) {
                return true;
            }
            sudoku[row][col]=0;
        }
    }
    return false;
}

    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku(board);
    }
};
int main(){
    return 0;
}
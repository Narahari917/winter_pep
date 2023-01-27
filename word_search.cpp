#include<bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<char>>&board, vector<vector<bool>>&visited, string &word, int index, int x, int y, const int &r, const int &c)
{
    return(x >= 0 && x < r && y >= 0 && y < c && !visited[x][y] && board[x][y] == word[x][y]);
}

int xMoves[] = {0, 0, 1, -1};
int yMoves[] = {1, -1, 0, 0};

bool exist(vector<vector<char>>&board, vector<vector<bool>>&visited, string &word, int index, int x, int y, const int &r, const int &c)
{
    if(index >= word.size())
        return true;
    else
    {
        visited[x][y] = true;
        for(int i = 0; i< 4; i++)
        {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(issafe(board, visited, word, index, nextX, nextY, r, c))
            {
                if(exist(board, visited, word, index + 1, nextX, nextY, r, c))
                return true;
            }
        }
        visited[x][y] = false;
        return false;
    }
    
}

bool exist(vector<vector<char>>&board, string word)
{
    if(word == "")
    return true;

    int r = board.size();
    if(r == 0)
    return false;

    int c = board[0].size();

    vector<vector<bool>>visited(r, vector<bool>(c, false));
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(board[i][j] == word[0] && exist(board, visited, word, 1, i, j, r, c))
            return true;
        }
    }
}
int main(){
    return 0;
}
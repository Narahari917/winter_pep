#include<bits/stdc++.h>
using namespace std;
int xMoves[] = {0, 0, 1, -1};
int yMoves[] = {1, -1, 0, 0};

#define possible_moves 
bool issafe(vector<vector<int>>&mat, vector<vector<bool>>&visited, int x, int y, const int &r, const int &c)
{
    return ((x >= 0 && x < r && y >= 0 && y<c) && !visited[x][y] && mat[x][y] == 1);
}

bool ratInMaze(vector<vector<int>>&mat, vector<vector<bool>> &visited, int x, int y, const int &r, const int &c)
{
    if( x == r-1 && y==c-1 && mat[r - 1][c - 1] == 1)
    {
        visited[x][y] = true;
        return true;
    }   

    if(issafe(mat, visited, x, y, r, c))
    {
        visited[x][y] = true;
        for(int i=0; i < 4; i++)
        {
            int nextX = x + xMoves[i];
            int nextY = y + yMoves[i];
            if(ratInMaze(mat, visited, nextX, nextY, r, c))
            return true;
        }
        visited[x][y] = false;
    }
    return false;
}

bool ratInMaze(vector<vector<int>>&mat)
{
    int r = mat.size();
    if(r == 0)
    return true;

    int c = mat[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    return ratInMaze(mat, visited, 0, 0, r, c);
}
int main(){
    return 0;
}
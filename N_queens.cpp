#include<bits/stdc++.h>
using namespace std;
bool issafe(vector<vector<bool>>&chess, int x, int y, const int &n)
{
    for(int i = x; i >= 0; i--)
    {
        if(chess[i][y])
        return false;
    }

    for(int i = x, j = y; i >=0 && j >= 0; i--, j-- )
    {
        if(chess[i][y])
        return false;

    }
    return true;
}

bool NQueen(vector<vector<bool>>&chess, int y, const int &n)
{
    if(y == n)
    {
        return true;
    }

    for(int x = 0; x < n; x++)
    {
        if(issafe(chess, x, y, n))
        {
            chess[x][y] = true;
            if(NQueen(chess, y+1, n)) 
            return true;
            chess[x][y] = false;
        }
    }
    return false;
}

vector<vector<bool>> NQueen(int n)
{
    vector<vector<bool>>chess (n, vector<bool>(n,false));
    NQueen(chess, 0, n);
    return chess;
}

int main()
{
return 0;
}
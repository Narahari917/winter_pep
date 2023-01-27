#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<string> dialpad =  {"", "", "abc", "def", "ghi", "jkl", " mno", "pqrs", "tuv", "wxyz"};
void letterCombinations(string &input, string &strSoFar , vector<string>&result, int start, int end)
{
    if( start > end)
    {
        result.push_back(strSoFar);
        return;
    }
    else
    {
        char digitPressed = input[start];
        string possibleMoves = dialpad[digitPressed - '0'];
        for(int i=0; i < possibleMoves.size(); i++)
        {
            strSoFar.push_back(possibleMoves[i]);
            letterCombinations(input, strSoFar, result, start+1, end);
            // backtrcaking
            strSoFar.pop_back();
        }
    }

}

vector<string> letterCombinations(string &input)
{
    vector<string> result;
    int start = 0, end = input.size()-1;

    if(input=="")
    return result;
    
    string strSoFar = "" ;

    letterCombinations(input, strSoFar, result, start, end);

    return result;
}
};
int main(){
    return 0;
}
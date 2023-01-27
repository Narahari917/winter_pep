#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

void generateParenthesis(string &strSoFar , vector<string>&result, int open, int close)
{
    if(open < 0|| close < 0 || open > close)
    return;

    else if(open == 0 && close == 0)
    {
        result.push_back(strSoFar);
        return;
    }
    else if(open <= close)
    {
        strSoFar.push_back('(');
        generateParenthesis(strSoFar, result, open-1, close);
        // backtrcaking
        strSoFar.pop_back();

        strSoFar.push_back(')');
        generateParenthesis(strSoFar, result, open, close-1);
        // backtrcaking
        strSoFar.pop_back();
    }

}

    vector<string> generateParenthesis(int n) {
    vector<string> result;
    int open = n, close = n;
    string strSoFar = "";
    generateParenthesis(strSoFar, result, open, close);
    return result;
    }
};
int main(){
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        help(0, {}, ans, nums);
        return ans;
    }
    
    void help(int idx, vector<int> cur, vector<vector<int>>& ans, vector<int>& nums){
        if(idx == nums.size()){ 
            ans.push_back(cur); 
            return;
        }
        help(idx + 1, cur, ans, nums);
        cur.push_back(nums[idx]);
        help(idx + 1, cur, ans, nums);
    }
    
    
    
//video approach...

void generateSet(vector<vector<int>>&result, vector<int> &setsofar, const vector<int>&vec, int index)
{
    if(index >= vec.size())
    {
        result.push_back(setsofar);
        return;
    }
    else
    {
        setsofar.push_back(vec[index]);
        generateSet(result, setsofar, vec, index + 1);

        setsofar.pop_back();
        generateSet(result, setsofar, vec, index + 1);
    }
}

vector<vector<int>> generateSet(vector<int> &vec)
{
    if(vec.size() == 0)
    {
        return {};
    }
    vector<vector<int>>result;
    vector<int>setsofar;
    generateSet(result, setsofar, vec,0);

    return result;
}
int main(){
    return 0;
}
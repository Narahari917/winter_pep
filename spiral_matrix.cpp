#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &ans){
    for(int i = 0; i < ans.size();i++){
            cout << ans[i] <<" ";
    }
}
vector<int> spiral(vector<vector<int> > &nums){
    vector<int> res (nums.size()*nums[0].size());
    int sx = 0,sy=0;
    int ctr = 0;
    int ex = nums.size()-1,ey = nums[0].size()-1;
    while(sx <= ex && sy <= ey){
        for(int j = sy; j<=ey; j++){
            res[ctr++] = nums[sx][j];
        }
        sx++;
        for(int i = sx; i <= ex; i++){
            res[ctr++] = nums[i][ey];
        }
        ey--;
        if(sx<=ex){
        for(int j = ey; j>=sy;j--){
            res[ctr++] = nums[ex][j];
        }
        ex--;
        }
        if(sy<=ey){
        for(int i = ex;i>=sx;i--){
            res[ctr++] =nums[i][sy];
        }
        sy++;
        }
    }
    return res;
}

int main(){
    vector<int> ans;
    vector<vector<int> > nums = {{1,2,3},{4,5,6},{7,8,9}};
    ans = spiral(nums);
    print(ans);
    return 0;
}
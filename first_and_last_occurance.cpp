#include<bits/stdc++.h>
using namespace std;
int first_Occurance(vector<int> &nums, int start, int end, int target){
    int mid = start+(end-start)/2;
    if(nums[mid] < target){
       return first_Occurance(nums, mid+1, end, target);
    }else if(nums[mid] > target){
       return first_Occurance(nums,start,mid-1,target);
    }else{
        if(mid==0 || (mid-1>=0 && nums[mid-1]<nums[mid])){
            return mid;
        }
        return first_Occurance(nums,start,mid-1,target);
    }
}
int last_Occurance(vector<int> &nums, int start, int end, int target){
    int mid = start+(end-start)/2;
    if(nums[mid] < target){
       return last_Occurance(nums, mid+1, end, target);
    }else if(nums[mid] > target){
        return last_Occurance(nums,start,mid-1,target);
    }else{
        if(mid==nums.size()-1|| (mid+1<=nums.size()-1 && nums[mid+1]>nums[mid])){
            return mid;
        }
        return last_Occurance(nums,mid+1,end,target);
    }
    
}
vector<int> firstAndLast(vector<int> nums,int target){
    int first = first_Occurance(nums,0,nums.size()-1,target);
    int last = last_Occurance(nums,first,nums.size()-1,target);
    return {first,last};
}
int main(){
    vector<int> nums = {1,2,3,4,5,5,5,5,6,7,8,9};
    int target = 5;
    vector<int> ans = firstAndLast(nums,target);
    for(auto i : ans){
        cout << i << endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
 int search_target(vector<int>& nums,int start,int end ,int target) {
        if(start>end){
            return -1;
        }
        int mid = start+(end-start)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[start]<=nums[mid]){
            if(nums[start]<=target && target<=nums[mid]){
                return search_target(nums,start,mid-1,target);
            }else{
                return search_target(nums,mid+1,end,target);
            }
        }else{
             if(nums[mid]>=target && target<=nums[end]){
                return search_target(nums,mid+1,end,target);
            }else{
                return search_target(nums,start,mid-1,target);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        int ans =search_target(nums,start,end,target);
        return ans;
    }
    int main(){
        vector<int> nums ={4,5,6,7,0,1,2};
        int target =0;
        search(nums,target);
        return 0;
    }

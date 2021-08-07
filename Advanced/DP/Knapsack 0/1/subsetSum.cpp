#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Subset sum problem

// Top Down

bool subsetSumTD(vector<int> nums, int idx, int target, bool** dp) {
    if(target==0){      // empty subset is present in all arrays and its sum is zero
        return true;
    }
    if(idx==0 || target<0) {
        return false;
    }
    if(dp[idx][target]){
        return true;
    }
    if(nums[idx-1]<=target){
        dp[idx][target] = subsetSumTD(nums,idx-1,target-nums[idx-1],dp) || subsetSumTD(nums,idx-1,target,dp);
        return dp[idx][target];
    } else {
        dp[idx][target] = subsetSumTD(nums,idx-1,target,dp);
        return dp[idx][target];
    }
}

// Bottom Up

bool subsetSumBU(vector<int> nums, int target) {
    // DP array initialization
    bool ** dp;
    dp = new bool *[nums.size()+1];
    for(int i=0;i<nums.size()+1;i++){
        dp[i] = new bool [target+1];
    }
    // Filling DP array
    for(int i=0;i<nums.size()+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0&&j==0){
                dp[i][j] = true;
            } 
            else if(i==0){
                dp[i][j] = false;
            }
            else if(j==0){
                dp[i][j] = true;
            }
            else {
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[nums.size()][target];
}

int main() {
    vector<int> v {1,2,4,3,2,6,7};
    int targetSum = 12;
    bool** dp;
    dp = new bool *[v.size()+1];
    for(int i=0;i<v.size()+1;i++){
        dp[i] = new bool [targetSum+1];
    }
    for(int i=0;i<v.size()+1;i++){
        for(int j=0;j<targetSum+1;j++){
            dp[i][j] = 0;
        }
    }
    cout<<subsetSumTD(v,v.size(),targetSum,dp)<<endl;
    delete dp;
    cout<<subsetSumBU(v,targetSum)<<endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Find number of subsets with sum equal to given target

// Top Down

int subsetSumCountTD(vector<int> nums, int idx, int target, int** dp) {
    if(target==0 && idx==0){
        return 1;
    }
    if(idx==0){
        return 0;
    }
    if(target==0) return 1;
    if(dp[idx][target]!=-1) return dp[idx][target];
    if(nums[idx-1]<=target){
        dp[idx][target] = subsetSumCountTD(nums,idx-1,target,dp) + subsetSumCountTD(nums,idx-1,target-nums[idx-1],dp);
        return dp[idx][target];
    } else {
        dp[idx][target] = subsetSumCountTD(nums,idx-1,target,dp);
        return dp[idx][target];
    }
}

// Bottom Up

int subsetSumCountBU(vector<int> nums, int target) {
    // DP array initialization
    int ** dp;
    dp = new int *[nums.size()+1];
    for(int i=0;i<nums.size()+1;i++){
        dp[i] = new int [target+1];
    }
    // Filling DP array
    for(int i=0;i<nums.size()+1;i++){
        for(int j=0;j<target+1;j++){
            if(j==0) {
                dp[i][j] = 1;
                continue;
            }
            if(i==0) {
                dp[i][j] = 0;
                continue;
            }
            if(nums[i-1]<=j) {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
            
        }
    }
    return dp[nums.size()][target];
}

int main() {
    vector<int> v {};
    int targetSum = 0;
    int** dp;
    dp = new int *[v.size()+1];
    for(int i=0;i<v.size()+1;i++){
        dp[i] = new int [targetSum+1];
    }
    for(int i=0;i<v.size()+1;i++){
        for(int j=0;j<targetSum+1;j++){
            dp[i][j] = -1;
        }
    }
    cout<<subsetSumCountTD(v,v.size(),targetSum,dp)<<endl;
    delete dp;
    cout<<subsetSumCountBU(v,targetSum)<<endl;
    return 0;
}
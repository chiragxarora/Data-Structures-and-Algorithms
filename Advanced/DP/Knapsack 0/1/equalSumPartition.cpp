#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Print true if array can be divided into 2 parts with equal sum!

bool equalSumPartitionTD(vector<int> v, int idx, int target, bool** dp) {
    if(idx==0) return false;
    if(target==0) return true;
    if(dp[idx][target]) return true;

    if(v[idx-1]<=target) {
        dp[idx][target] = equalSumPartitionTD(v,idx-1,target-v[idx-1],dp) || equalSumPartitionTD(v,idx-1,target,dp);
        return dp[idx][target];
    } else {
        dp[idx][target] = equalSumPartitionTD(v,idx-1,target,dp);
        return dp[idx][target];
    }
}

bool equalSumPartitionBU(vector<int> nums, int target) {
    // DP array initialization
    int ** dp;
    dp = new int *[nums.size()+1];
    for(int i=0;i<nums.size()+1;i++){
        dp[i] = new int [target+1];
    }
    // Filling DP array
    for(int i=0;i<nums.size()+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0){
                dp[i][j] = false;
                continue;
            }
            if(j==0){
                dp[i][j] = true;
                continue;
            }
            if(nums[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[nums.size()][target];
}

int main() {
    vector<int> v {1,2,3,4};
    int targetSum = 0;
    for(auto i : v) {
        targetSum += i;
    }
    if(targetSum%2==1){
        cout<<0;
        return 0;
    }
    targetSum /= 2;
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
    cout<<equalSumPartitionTD(v,v.size(),targetSum,dp)<<endl;
    delete dp;
    cout<<equalSumPartitionBU(v,targetSum)<<endl;
    return 0;
}
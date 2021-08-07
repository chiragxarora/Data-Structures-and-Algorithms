#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// Print true if array can be divided into 2 parts with equal sum!

int subsetSumDifference(vector<int> nums, int idx, int currentSum, int totalSum) {
    if(idx==0&&totalSum==0) return 0;
    if(idx==0) {
        return abs((totalSum-currentSum) - currentSum);
    }
    // pick in A
    int include = subsetSumDifference(nums,idx-1,currentSum+nums[idx-1],totalSum);
    // pick in remaining part
    int exclude = subsetSumDifference(nums,idx-1,currentSum,totalSum);

    return min(include,exclude);
}


int subsetSumDifferenceTD(vector<int> nums, int idx, int currentSum, int totalSum, int** dp) {
    if(idx==0&&totalSum==0) return 0;
    if(idx==0) {
        return abs((totalSum-currentSum) - currentSum);
    }
    if(dp[idx][currentSum] != INT_MAX){
        return dp[idx][currentSum];
    }
    // pick in A
    int include = subsetSumDifferenceTD(nums,idx-1,currentSum+nums[idx-1],totalSum,dp);
    // pick in remaining part
    int exclude = subsetSumDifferenceTD(nums,idx-1,currentSum,totalSum,dp);
    dp[idx][currentSum] = min(include,exclude);
    return min(include,exclude);
}

int subsetSumDifferenceBU(vector<int> nums, int range) {
    // DP array initialization
    bool ** dp;
    dp = new bool *[nums.size()+1];
    for(int i=0;i<nums.size()+1;i++){
        dp[i] = new bool [range+1];
    }
    // Filling DP array
    for(int i=0;i<nums.size()+1;i++){
        for(int j=0;j<range+1;j++){
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
    int min = INT_MAX;
    for(int i=0;i<=range/2;i++){
        if(dp[nums.size()][i]){
            if(range-(2*i)<min){
                min = range-(2*i);
            }
        }
    }
    return min;
}

int main() {
    vector<int> v {1,2,7};
    int totalSum = 0;
    for(auto i : v) {
        totalSum += i;
    }
    cout<<subsetSumDifference(v,v.size(),0,totalSum)<<endl;
    
    int** dp;
    dp = new int *[v.size()+1];
    for(int i=0;i<v.size()+1;i++){
        dp[i] = new int [totalSum+1];
    }
    for(int i=0;i<v.size()+1;i++){
        for(int j=0;j<totalSum+1;j++){
            dp[i][j] = INT_MAX;
        }
    }
    cout<<subsetSumDifferenceTD(v,v.size(),0,totalSum,dp)<<endl;
    cout<<subsetSumDifferenceBU(v,totalSum)<<endl;
    return 0;
}
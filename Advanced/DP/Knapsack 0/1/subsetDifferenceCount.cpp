#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// Find number of partitions of an array in subsets, where differnce of sum of both subsets is equal to "diff"

int subsetDifferenceCountBU(vector<int> nums, int totalSum, int targetDiff) {
    // find subset with sum = (totalSum + diff)/2;
    int target = (totalSum + targetDiff)/2;
    // DP array initialization
    int** dp;
    dp = new int *[nums.size()+1];
    for(int i=0;i<nums.size()+1;i++){
        dp[i] = new int [target+1];
    }
    // Filling DP array
    for(int i=0;i<nums.size()+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0&&j==0){
                dp[i][j] = 1;
            } 
            else if(i==0){
                dp[i][j] = 0;
            }
            else if(j==0){
                dp[i][j] = 1;
            }
            else {
                if(nums[i-1]<=j){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
            
        }
    }
    return dp[nums.size()][target];
}

int main() {
    vector<int> v {1,1,2,3};
    int totalSum = 0;
    for(auto i : v) {
        totalSum += i;
    }
    int targetDiff = 1;
    if(((totalSum+targetDiff)/2) % 2 == 1) {
        cout<<0;
        return 0;
    }
    cout<<subsetDifferenceCountBU(v,totalSum,targetDiff)<<endl;
    return 0;
}
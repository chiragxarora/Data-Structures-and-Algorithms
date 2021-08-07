#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Target Sum : https://leetcode.com/problems/target-sum/

int targetSum(vector<int> nums, int idx, int currentSum, int target){
    if(idx==0){
        if(currentSum==target){
            return 1;
        } else {
            return 0;
        }
    }
    // plus sign
    int plus = targetSum(nums,idx-1,currentSum+nums[idx-1],target);
    // minus sign
    int minus = targetSum(nums,idx-1,currentSum-nums[idx-1],target);
    return plus + minus;
}

int targetSumTD(vector<int> nums, int idx, int currentSum, int totalSum, int target, int** dp){
    if(idx==0){
        if(currentSum==target){
            return 1;
        } else {
            return 0;
        } 
    }
    if(dp[idx][totalSum+currentSum]!=INT_MIN){
        return dp[idx][totalSum+currentSum];
    }
    // plus sign
    int plus = targetSumTD(nums,idx-1,currentSum+nums[idx-1],totalSum,target,dp);
    // minus sign
    int minus = targetSumTD(nums,idx-1,currentSum-nums[idx-1],totalSum,target,dp);
    dp[idx][totalSum+currentSum] = plus + minus;
    return dp[idx][totalSum+currentSum];
}

 /*
    This problem is same as subset difference count,
    if we separate positive and negative numbers after assigning sign,
    it will be equal to  +a +b -c +d -e == target  ==>>  (a+b+d) - (c+e) == target
*/

// int targetSumBU(vector<int> nums, int target) {
//     int totalSum = 0;
//     for(auto i : nums){
//         totalSum += i;
//     }
//     if(((totalSum+target)/2) % 2 == 1) {
//         cout<<0;
//         return 0;
//     }
//     // find subset with sum = (totalSum + diff)/2;
//     int tgt = (totalSum + target)/2;
//     // DP array initialization
//     int** dp;
//     dp = new int *[nums.size()+1];
//     for(int i=0;i<nums.size()+1;i++){
//         dp[i] = new int [tgt+1];
//     }
//     // Filling DP array
//     for(int i=0;i<nums.size()+1;i++){
//         for(int j=0;j<tgt+1;j++){
//             if(i==0&&j==0){
//                 dp[i][j] = 1;
//             } 
//             else if(i==0){
//                 dp[i][j] = 0;
//             }
//             else if(j==0){
//                 dp[i][j] = 1;
//             }
//             else {
//                 if(nums[i-1]<=j){
//                     dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
//                 } else {
//                     dp[i][j] = dp[i-1][j];
//                 }
//             }
            
//         }
//     }
//     return dp[nums.size()][tgt];    
// }

int main() {
    vector<int> nums {1,1,1,1,1};
    int target = 3;
    cout<<targetSum(nums,nums.size(),0,target)<<endl;
    int totalSum = 0;
    for(auto i : nums) {
        totalSum+=i;
    }
    int** dp;
    dp = new int *[nums.size()+1];
    for(int i=0;i<nums.size()+1;i++){
        dp[i] = new int [2*totalSum+1];
    }
    for(int i=0;i<nums.size()+1;i++){
        for(int j=0;j<2*totalSum+1;j++){
            dp[i][j] = INT_MIN;
        }
    }
    cout<<targetSumTD(nums,nums.size(),0,totalSum,target,dp)<<endl;
    // cout<<targetSumBU(nums,target)<<endl;
    return 0;
}
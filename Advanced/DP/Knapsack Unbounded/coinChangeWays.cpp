#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Find number of ways by which we can obtain a target sum using given coins(unlimited supply)

int coinChange(vector<int> coins, int idx, int target){
    if(idx==0&&target!=0) return 0;
    if(target==0) return 1;
    if(coins[idx-1]<=target){
        // pick
        int p1 = coinChange(coins,idx,target-coins[idx-1]);
        // dont pick
        int p2 = coinChange(coins,idx-1,target);
        return p1+p2;
    } else {
        return coinChange(coins,idx-1,target);
    }
}

int coinChangeTD(vector<int> coins, int idx, int target, int** dp){
    if(idx==0&&target!=0) return 0;
    if(target==0) return 1;
    if(dp[idx][target]!=-1) return dp[idx][target];
    if(coins[idx-1]<=target){
        // pick
        int p1 = coinChangeTD(coins,idx,target-coins[idx-1],dp);
        // dont pick
        int p2 = coinChangeTD(coins,idx-1,target,dp);
        return dp[idx][target] = p1+p2;
    } else {
        return dp[idx][target] = coinChangeTD(coins,idx-1,target,dp);
    }
}

int coinChangeBU(vector<int> coins, int target){
    int ** dp;
    dp = new int *[coins.size()+1];
    for(int i=0;i<coins.size()+1;i++){
        dp[i] = new int [target+1];
    }
    for(int i=0;i<coins.size()+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0&&j!=0) {
                dp[i][j] = 0;
            }
            else if(j==0){
                dp[i][j] = 1;
            }
            else {
                if(coins[i-1]<=j) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[coins.size()][target];
}

// ** Bottom Up Space Efficient!  {converting 2D DP to 1D}

int coinChangeBUSE(vector<int> coins, int target){
    int* dp = new int [target+1];
    dp[0] = 1;
    for(int i=1;i<target+1;i++){
        dp[i] = 0;
    }
    for(int i=1;i<coins.size()+1;i++){
        for(int j=1;j<target+1;j++){
            if(coins[i-1]<=j) {
                int up = dp[j];
                int prev = dp[j-coins[i-1]];
                dp[j] = up + prev;
            }
        }
    }
    return dp[target];
}



int main() {
    vector<int> coins {1,2,3};
    int target = 47;
    cout<<coinChange(coins,coins.size(),target)<<endl;
    int ** dp;
    dp = new int *[coins.size()+1];
    for(int i=0;i<coins.size()+1;i++){
        dp[i] = new int [target+1];
    }
    for(int i=0;i<coins.size()+1;i++){
        for(int j=0;j<target+1;j++){
            dp[i][j] = -1;
        }
    }
    cout<<coinChangeTD(coins,coins.size(),target,dp)<<endl;
    cout<<coinChangeBU(coins,target)<<endl;
    cout<<coinChangeBUSE(coins,target)<<endl;
    return 0;
}
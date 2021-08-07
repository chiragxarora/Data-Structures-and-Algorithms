#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// Find number of ways by which we can obtain a target sum using given coins(unlimited supply)

int maximumCuts(vector<int> partition, int idx, int target){
    if(idx==0&&target!=0) return -1;
    if(target==0) return 0;

    if(partition[idx-1]<=target) {
        // pick
        int p1 = maximumCuts(partition,idx,target-partition[idx-1]) + 1;
        // dont pick
        int p2 = maximumCuts(partition,idx-1,target);
        return max(p1,p2);
    } else {
        return maximumCuts(partition,idx-1,target);
    }
}

int maximumCutsTD(vector<int> partition, int idx, int target, int** dp){
    if(idx==0&&target!=0) return INT_MIN;
    if(target==0) return 0;
    if(dp[idx][target]!=INT_MIN) return dp[idx][target];

    if(partition[idx-1]<=target) {
        // pick
        int p1 = maximumCutsTD(partition,idx,target-partition[idx-1],dp) + 1;
        // dont pick
        int p2 = maximumCutsTD(partition,idx-1,target,dp);
        return dp[idx][target] =  max(p1,p2);
    } else {
        return dp[idx][target] = maximumCutsTD(partition,idx-1,target,dp);
    }
}

int maximumCutsBU(vector<int> partition, int target) {
    int** dp = new int *[partition.size()+1];
    for(int i=0;i<partition.size()+1;i++){
        dp[i] = new int [target+1];
    }
    for(int i=0;i<partition.size()+1;i++){
        for(int j=0;j<target+1;j++){
            if(i==0&&j!=0){
                dp[i][j] = INT_MIN;
            } else if(j==0) {
                dp[i][j] = 0;
            }
            else {
                if(partition[i-1]<=j){
                    dp[i][j] = max(dp[i][j-partition[i-1]]+1,dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[partition.size()][target];
}

int main() {
    vector<int> partition {2,3,5};
    int target = 5;
    cout<<maximumCuts(partition,partition.size(),target)<<endl;
    int ** dp;
    dp = new int *[partition.size()+1];
    for(int i=0;i<partition.size()+1;i++){
        dp[i] = new int [target+1];
    }
    for(int i=0;i<partition.size()+1;i++){
        for(int j=0;j<target+1;j++){
            dp[i][j] = INT_MIN;
        }
    }
    cout<<maximumCutsTD(partition,partition.size(),target,dp)<<endl;
    cout<<maximumCutsBU(partition,target)<<endl;
    // cout<<coinChangeBUSE(coins,target)<<endl;
    return 0;
}
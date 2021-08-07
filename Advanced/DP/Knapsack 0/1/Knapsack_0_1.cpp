#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

// -0/1 knapsack 

// recursive

int knapsack(vector<int> itemP, vector<int> itemW, int idx, int totalWeight) {
    // starting from end of the array (last element)
    // *** idx corresponds to item at index idx-1
    if(idx==0 || totalWeight<=0) return 0;

    if(itemW[idx-1]<=totalWeight){
        // pick 
        int p1 = knapsack(itemP, itemW, idx-1, totalWeight-itemW[idx-1]) + itemP[idx-1];
        // dont pick
        int p2 = knapsack(itemP, itemW, idx-1, totalWeight);
        return max(p1,p2);
    } else {
        return knapsack(itemP, itemW, idx-1, totalWeight);
    }
}

// top down (memoization)

int knapsackTD(vector<int> itemP, vector<int> itemW, int idx, int totalWeight, int **dp) {
    if(idx==0 || totalWeight<=0) return 0;

    // using previously stored value if present
    if(dp[idx][totalWeight] != -1){
        return dp[idx][totalWeight];
    }

    if(itemW[idx-1]<=totalWeight){
        // pick 
        int p1 = knapsackTD(itemP,itemW,idx-1,totalWeight-itemW[idx-1],dp) + itemP[idx-1];
        // dont pick
        int p2 = knapsackTD(itemP,itemW,idx-1,totalWeight,dp);
        dp[idx][totalWeight] = max(p1,p2);
        return dp[idx][totalWeight];
    } else {
        dp[idx][totalWeight] =  knapsackTD(itemP,itemW,idx-1,totalWeight,dp);
        return dp[idx][totalWeight];
    }
}

// Bottom Up

int knapsackBU(vector<int> itemP, vector<int> itemW, int totalWeight) {
    // DP array initialization
    int ** dp;
    dp = new int *[itemP.size()+1];
    for(int i=0;i<itemP.size()+1;i++){
        dp[i] = new int [totalWeight+1];
    }
    // filling DP array
    for(int i=0;i<itemP.size()+1;i++){
        for(int j=0;j<totalWeight+1;j++){
            if(i==0 || j==0) {
                dp[i][j] = 0;       // filling base cases
            } else {
                if(itemW[i-1]<=j){
                    dp[i][j] = max(itemP[i-1]+dp[i-1][j-itemW[i-1]],dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    delete dp;
    return dp[itemW.size()][totalWeight];
}


int main() {
    vector<int> ip {1,3,5,7};
    vector<int> iw {2,3,4,6};
    int totalWeight = 10;
    // recursive
    cout<<knapsack(ip,iw,ip.size(),totalWeight)<<endl;

    // Top Down driver code
    // making storage array and filling it with an invalid answer
    int ** dp;
    dp = new int *[ip.size()+1];
    for(int i=0;i<ip.size()+1;i++){
        dp[i] = new int [totalWeight+1];
    }
    for(int i=0;i<ip.size()+1;i++){
        for(int j=0;j<totalWeight+1;j++){
            dp[i][j] = -1;
        }
    }
    cout<<knapsackTD(ip,iw,ip.size(),totalWeight,dp)<<endl;
    delete dp;
    // Bottom Up
    cout<<knapsackBU(ip,iw,totalWeight)<<endl;
    return 0;
}
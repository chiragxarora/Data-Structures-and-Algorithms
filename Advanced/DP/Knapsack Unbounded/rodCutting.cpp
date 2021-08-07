#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

// Rod Cutting problem

// recursive

int rodCutting(vector<int> price, int currentLength, int totalength) {
    if(totalength==0 || currentLength==0) return 0;
    if(currentLength <= totalength){
        // pick 
        int p1 = rodCutting(price,currentLength,totalength-currentLength) + price[currentLength-1];
        // dont pick
        int p2 = rodCutting(price,currentLength-1,totalength);
        return max(p1,p2);
    } else {
        return rodCutting(price,currentLength-1,totalength);
    }
}

// top down (memoization)

int rodCuttingTD(vector<int> price, int currentLength, int totalLength, int** dp) {
    if(totalLength==0 || currentLength==0) return 0;
    if(dp[currentLength][totalLength] != -1) return dp[currentLength][totalLength];
    if(currentLength <= totalLength){
        // pick 
        int p1 = rodCuttingTD(price,currentLength,totalLength-currentLength,dp) + price[currentLength-1];
        // dont pick
        int p2 = rodCuttingTD(price,currentLength-1,totalLength,dp);
        dp[currentLength][totalLength] = max(p1,p2);
        return max(p1,p2);
    } else {
        dp[currentLength][totalLength] = rodCuttingTD(price,currentLength-1,totalLength,dp);
        return dp[currentLength][totalLength];
    }
}

// Bottom Up

int rodCuttingBU(vector<int> price, int totalLength) {
    // DP array initialization
    int ** dp;
    dp = new int *[price.size()+1];
    for(int i=0;i<price.size()+1;i++){
        dp[i] = new int [totalLength+1];
    }
    // filling DP array
    for(int i=0;i<price.size()+1;i++){
        for(int j=0;j<totalLength+1;j++){
            if(i==0 || j==0) {
                dp[i][j] = 0;
            } else {
                if(i<=j){
                    dp[i][j] = max(price[i-1]+dp[i][j-i],dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    return dp[price.size()][totalLength];
}


int main() {
    vector<int> price {1,5,8,9,10,17,17,20};
    int totalLength = price.size();
    // recursive
    cout<<rodCutting(price,price.size(),totalLength)<<endl;

    int ** dp;
    dp = new int *[price.size()+1];
    for(int i=0;i<price.size()+1;i++){
        dp[i] = new int [totalLength+1];
    }
    for(int i=0;i<price.size()+1;i++){
        for(int j=0;j<totalLength+1;j++){
            dp[i][j] = -1;
        }
    }
    cout<<rodCuttingTD(price,price.size(),totalLength,dp)<<endl;
    delete dp;
    // Bottom Up
    cout<<rodCuttingBU(price,totalLength)<<endl;
    return 0;
}
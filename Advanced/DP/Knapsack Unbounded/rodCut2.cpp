#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Rod Cutting problem : different approach!

int rodCutting(vector<int> price, int length) {
    if(length==1){
        return price[0];
    }
    int ans = -1;
    for(int i=1;i<=length/2;i++){
        int left = rodCutting(price,i);
        int right = rodCutting(price,length-i);
        int asItIs = price[length-1];
        int cMax = max(asItIs,left+right);
        if(cMax > ans){
            ans = cMax;
        }
    }
    return ans;
}

int rodCuttingTD(vector<int> price, int length, int* dp) {
    if(length==1){
        return price[0];
    }
    if(dp[length]!=-1) return dp[length];

    int ans = -1;
    for(int i=1;i<=length/2;i++){
        int left = rodCuttingTD(price,i,dp);
        int right = rodCuttingTD(price,length-i,dp);
        int asItIs = price[length-1];
        int cMax = max(asItIs,left+right);
        if(cMax > ans){
            ans = cMax;
        }
    }
    dp[length] = ans;
    return ans;
}

int rodCuttingBU(vector<int> price, int length) {
    int* dp = new int [length+1];
    dp[0] = 0;
    dp[1] = price[0];
    for(int i=2;i<length+1;i++){
        int left = 1;
        int right = i-1;
        int ans = price[i-1];
        while(left<=right){
            if(dp[left]+dp[right]>ans){
                ans = dp[left] + dp[right];
            }
            left++;
            right--;
        }
        dp[i] = ans;
    }
    return dp[length];
}

int main() {
    
    vector<int> price {1,5,8,9,10,17,17,20};
    int totalLength = price.size();
    // recursive
    cout<<rodCutting(price,totalLength)<<endl;
    int* dp = new int [totalLength+1];
    for(int i=0;i<totalLength+1;i++){
        dp[i] = -1;
    }
    cout<<rodCuttingTD(price,totalLength,dp)<<endl;
    cout<<rodCuttingBU(price,totalLength)<<endl;
    return 0;
}
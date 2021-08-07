#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Longest Bitonic Subsequence

int* LIS(vector<int> nums) {
    int* dp = new int [nums.size()];
    dp[0] = 1;
    for(int i=1;i<nums.size();i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[j]+1,dp[i]);
            }
        }
    }
    return dp;
}

int main() {
    vector<int> v {3,4,2,8,10,5,1};
    int* lis = LIS(v);    // lis[i] = LIS ending on v[i];
    reverse(v.begin(),v.end());
    int* lds = LIS(v);    // lds[i] = LDS starting from v[len-i-1];
    int ans = 0;
    for(int i=0;i<v.size();i++){
        int len = lis[i] + lds[v.size()-i-1] - 1;
        ans = max(ans,len);
    }
    cout<<ans;
    return 0;
}
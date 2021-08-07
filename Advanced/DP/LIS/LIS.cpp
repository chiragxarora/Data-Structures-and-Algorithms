#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// DP { O(n^2) }

int LIS(vector<int> nums) {
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
    int ans = dp[0];
    for(int i=0;i<nums.size();i++){
        ans = max(ans,dp[i]);
    }
    return ans;
}

// Binary Search { O(n logn) }

int binary_search_ub(int dp[], int n, int key) {
    int start = 0, end = n, ans = -1;
    while(start<=end) {
        int mid = (start + end)/2;
        if(dp[mid]>=key) {
            ans = mid;
            end = mid-1;
        } else {
            start = mid+1;
        }
    }
    return ans;
}

int LIS_BS(vector<int> v) {
    int* dp = new int [v.size()+1];
    dp[0] = INT_MIN;
    for(int i=1;i<v.size()+1;i++){
        dp[i] = INT_MAX;
    }
    int lis = 1;
    for(int i=0;i<v.size();i++){
        if(dp[lis]>=v[i]){
            int idx = binary_search_ub(dp,v.size(),v[i]);
            dp[idx] = v[i];
        } else {
            lis++;
            dp[lis] = v[i];
        }
    }
    lis = 0;
    for(int i=0;i<v.size()+1;i++) {
        if(dp[i]!=INT_MAX){
            lis = i;
        }
        if(dp[i]==INT_MAX){
            break;
        }
    }
    return lis;
}

int main() {
    vector<int> v {4,3,2,1,1,2,3};
    cout<<LIS(v)<<endl;
    cout<<LIS_BS(v)<<endl;
    return 0;
}
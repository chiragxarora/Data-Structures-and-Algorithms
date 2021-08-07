#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Maximum sum increasing subsequence

int MIS(vector<int> nums) {
    int* dp = new int [nums.size()];
    dp[0] = nums[0];
    for(int i=1;i<nums.size();i++){
        dp[i] = nums[i];
        for(int j=0;j<i;j++){
            if(nums[i] > nums[j]){
                dp[i] = max(dp[i],dp[j]+nums[i]);
            }
        }
    }
    int ans = dp[0];
    for(int i=0;i<nums.size();i++){
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main() {
    vector<int> v {4,3,2,1,1,2,3};
    cout<<MIS(v)<<endl;
    return 0;
}
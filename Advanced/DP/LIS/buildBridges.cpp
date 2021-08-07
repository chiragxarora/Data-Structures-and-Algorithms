#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Building Bridges : https://www.geeksforgeeks.org/dynamic-programming-building-bridges/
// Similar to Russian Doll Envelopes : https://leetcode.com/problems/russian-doll-envelopes/

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

int LIS(vector<vector<int>> v) {
    int* dp = new int [v.size()+1];
    dp[0] = INT_MIN;
    for(int i=1;i<v.size()+1;i++){
        dp[i] = INT_MAX;
    }
    int lis = 1;
    for(int i=0;i<v.size();i++){
        if(dp[lis]>=v[i][1]){
            int idx = binary_search_ub(dp,v.size(),v[i][1]);
            dp[idx] = v[i][1];
        } else {
            lis++;
            dp[lis] = v[i][1];
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

bool cmp (vector<int> v1, vector<int> v2) {
    if(v1[0]!=v2[0]){
        return v1[0]<v2[0];
    } else {
        return v1[1]<v2[1];
    }
}

int main() {
    vector<vector<int>> v {{5,4},{6,4},{6,7},{2,3}};
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    }
    cout<<LIS(v);
    return 0;
}
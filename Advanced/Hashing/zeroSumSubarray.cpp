#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// Find maximum length of subarray in a given array that has sum = 0

int solve(vector<int> nums) {
    for(int i=1;i<nums.size();i++){
        nums[i] += nums[i-1];
    }
    int ans = 0;
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            ans = max(ans,i+1);
        }
        if(map.find(nums[i])!=map.end()){
            ans = max(ans,i-map[nums[i]]);
        } else {
            map.insert(make_pair(nums[i],i));
        }
    }
    return ans;
}

int main() {
    vector<int> v {6,-1,2,-1,2,-1,-1};
    cout<<solve(v);
    return 0;
}
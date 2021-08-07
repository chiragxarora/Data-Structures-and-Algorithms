#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// Find maximum length of subarray in a given array that has sum = k

int solve(vector<int> nums, int k) {
    for(int i=1;i<nums.size();i++){
        nums[i] += nums[i-1];
    }
    int ans = 0;
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(nums[i]==k){
            ans = max(ans,i+1);
        }
        if(map.find(nums[i])!=map.end()){
            //ans = max(ans,i-map[nums[i]]);
        } else {
            map.insert(make_pair(nums[i],i));
            if(map.find(nums[i]-k)!=map.end()){
                ans = max(ans,i-map[nums[i]-k]);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> v {0,4,1,2,3,-2,-3};
    cout<<solve(v,3);
    return 0;
}
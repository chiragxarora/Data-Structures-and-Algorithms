#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// Find maximum length of consecutive subsequence in a given array

// 1 4 5 8 2 6 9 7 10  :  ans = 4 5 6 7 => len = 4

int solve(vector<int> nums) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        if(map.find(nums[i])!=map.end()) continue;
        if(map.find(nums[i]+1)!=map.end() && map.find(nums[i]-1)!=map.end()){
            int l1 = map[nums[i]+1], l2 = map[nums[i]-1];
            cout<<nums[i]<<" "<<l1<<" "<<l2<<endl;
            map[nums[i]] = 1;
            map[nums[i]-map[nums[i]-1]] = l1+l2+1;
            map[nums[i]+map[nums[i]+1]] = l1+l2+1;
        }
        else if(map.find(nums[i]+1)!=map.end()){
            map[nums[i]] = map[nums[i]+1]+1;
            map[nums[i]+map[nums[i]+1]] = map[nums[i]+1]+1; 
        }
        else if(map.find(nums[i]-1)!=map.end()){
            map[nums[i]] = map[nums[i]-1]+1;
            map[nums[i]-map[nums[i]-1]] = map[nums[i]-1]+1;
        }
        else {
            map[nums[i]] = 1;
        }
    }
    int ans = 0;
    for(auto m : map){
        ans = max(ans,m.second);
    }
    return ans;
}

int solve2(vector<int> nums) {
    unordered_set<int> set;
    for(auto i : nums){
        set.insert(i);
    }
    int ans = 1;
    for(int i=0;i<nums.size();i++){
        if(set.find(nums[i]-1)==set.end()){
            int nextNum = nums[i]+1;
            int currentLen = 1;
            while(set.find(nextNum)!=set.end()){
                currentLen++;
                nextNum++;
            }
            ans = max(ans,currentLen);
        }
    }
    return ans;
}

int main() {
    vector<int> v {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4, 2, 1, 3, 4, 5, 9, 6};
    cout<<solve(v);
    cout<<solve2(v);
    return 0;
}
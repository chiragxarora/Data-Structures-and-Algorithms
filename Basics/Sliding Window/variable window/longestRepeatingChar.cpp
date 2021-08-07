#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/longest-repeating-character-replacement/

int solve(string str, int k) {
    int i=0, j=0, ans=0, mx=0;
    unordered_map<char,int> map;
    while(j<str.size()){
        map[str[j]]++;
        mx = max(mx, map[str[j]]);
        while(j-i+1-mx>k){
            map[str[i]]--;
            i++;
            for(auto m : map) mx = max(mx,m.second);
        }
        ans = max(ans,j-i+1);
        j++;
    }
    return ans;
}

int main() {
    string str = "aabacbebebe";
    int k = 3;
    cout<<solve(str,k);
    return 0;
}
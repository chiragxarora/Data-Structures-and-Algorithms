#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

// https://leetcode.com/problems/minimum-window-substring/

string solve(string str, string pattern) {
    int i=0, j=0, ans=INT_MAX, cnt=0;
    string val;
    unordered_map<char,int> sf, pf;
    for(auto p : pattern) pf[p]++;

    while(j<str.size()){
        char ch = str[j];
        sf[ch]++;
        if(pf.find(ch)!=pf.end() && pf[ch]>=sf[ch]) cnt++;
        if(cnt==pattern.size()){
            while(pf[str[i]]<sf[str[i]]){
                sf[str[i]]--;
                i++;
            }
            if(j-i+1<ans){
                val = str.substr(i,j-i+1);
                ans = j-i+1;
            }
        }
        j++;
    }
    return val;
}

int main() {
    string str = "aabacbebebe", pattern = "bbec";
    cout<<solve(str,pattern);
    return 0;
}
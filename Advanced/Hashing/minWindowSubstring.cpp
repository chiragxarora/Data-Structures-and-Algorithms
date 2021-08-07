#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <climits>
#include <string>

using namespace std;

// Find minimum length substring containing all characters of a given pattern

int solve(string str, string pattern) {
    unordered_map<char,int> pf, sf;
    for(auto p : pattern) {
        pf[p] +=1;
    }
    int start = 0, end = 0, ans = INT_MAX;
    string val;
    int cnt = 0;
    while(end<str.size()){
        char ch = str[end];
        sf[ch]++;
        if(pf.find(ch)!=pf.end()&&sf[ch]<=pf[ch]){
            cnt++;
        }
        if(cnt==pattern.length()){
            cout<<str.substr(start,end-start+1)<<endl;
            while(sf[str[start]]>pf[str[start]]){
                sf[str[start]]--;
                start++;
            }
            if(end-start<ans){
                ans = end-start+1;
                val = str.substr(start,ans);
            }
        }
        end++;
    }
    cout<<val<<endl;
    return ans;
}

int main() {
    string str = "bcbabcaadcsabacadaaabd", pattern = "abcd";
    cout<<solve(str,pattern);
    return 0;
}
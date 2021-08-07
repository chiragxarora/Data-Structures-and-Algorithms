#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

//  https://leetcode.com/problems/word-break-ii/

vector<string> wordBreak(string str, unordered_set<string> words) {
    if(str.length()==0){
        vector<string> v {""};
        return v;
    }
    vector<string> ans;
    for(int i=1;i<=str.length();i++){
        string rem = str.substr(0,i);
        if(words.find(rem)==words.end()){
            continue;
        }
        vector<string> remAns = wordBreak(str.substr(i),words);
        for(auto rs : remAns){
            ans.push_back(rem+" "+rs);
        }
    }
    return ans;
}

int main() {
    string str = "a";
    vector<string> dict {"a"};
    unordered_set<string> s;
    for(auto d : dict){
        s.insert(d);
    }
    vector<string> ans = wordBreak(str,s);
    for(auto a : ans) {
        cout<<a<<endl;
    }
    return 0;
}
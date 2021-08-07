#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Question : https://leetcode.com/problems/palindrome-partitioning/

bool isPalindrome(string s) {
    for(int i=0,j=s.length()-1;i<=j;i++,j--){
        if(s[i]!=s[j]) {
            return false;
        }
    }
    return true;
}

void pp(string str, vector<string> ans, vector<vector<string>>& fn) {
    if(str.length()==0) {
        fn.push_back(ans);
        return;
    }

    for(int i=0;i<str.length();i++){
        if(isPalindrome(str.substr(0,i+1))) {
            ans.push_back(str.substr(0,i+1));
            pp(str.substr(i+1),ans,fn);
            ans.erase(ans.end()-1);
        }
    }
}

int main() {
    vector<string> ans;
    vector<vector<string>> fn;
    pp("aaba",ans,fn);
    for( auto x : fn) {
        for(auto s : x) {
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// given a string s, find all its permutations

void printPermutations(string str, string ans) {
    if(str.length()==0) {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.length();i++){
        char ch = str[i];
        string ros = str.substr(0,i) + str.substr(i+1);
        printPermutations(ros,ans+ch);
    }
}

vector<string> getPermutations(string str) {
    if(str.length()==0) {
        vector<string> v;
        v.push_back("");
        return v;
    }
    vector<string> restAns = getPermutations(str.substr(1));
    vector<string> ans;
    for(int i=0;i<restAns.size();i++){
        for(int j=0;j<=restAns[i].length();j++){
            string val = restAns[i].substr(0,j) + str[0] + restAns[i].substr(j+1);
            ans.push_back(val);
        }
    }
    return ans;
}

int main() {
    printPermutations("abc","");
    vector<string> ans = getPermutations("abc");
    for(auto x : ans) {
        cout<<x<<" ";
    }
    return 0;
}
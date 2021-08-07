#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// given a pattern, find all its anagrams present in another string

int solve(string str, string pattern) {
    int i=0, j=0;
    unordered_map<char,int> pt;
    for(auto p : pattern){
        pt[p]++;
    }
    int count = pt.size();
    while(j<str.size()){
        if(pt.find(str[j])!=pt.end()){
            pt[str[j]]--;
            if(pt[str[j]]==0){
                count--;
            }
        }
        if(j-i+1==pattern.size()){
            string val = str.substr(i,pattern.size());
            if(count==0){
                cout<<val<<" ";
            }
            if(pt.find(str[i])!=pt.end()){
                pt[str[i]]++;
                if(pt[str[i]]==1){
                    count++;
                }
            }
            i++;
        }
        j++;
    }
    return 0;
}

int main() {
    string str = "abcadjbcadababsqcaabca", pattern = "abc";
    cout<<solve(str,pattern);
    return 0;
}
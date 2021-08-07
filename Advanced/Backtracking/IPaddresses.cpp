#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Restore IP addresses : https://leetcode.com/problems/restore-ip-addresses/

bool isValid(string str) {
    if(str[0]=='0' && str.length()!=1){
        return false;
    }
    if(stoi(str)>255){
        return false;
    }
    return true;
}
void ipAddress(string s, int dots, string ans, vector<string>& a) {
    if(dots==4) {
        if(s.length()==0){
            
            a.push_back(ans.substr(0,ans.length()-1));
        }
            return;
    }
    int len = 3;
    if(s.length()<len){
        len = s.length();
    }
    for(int i=0;i<len;i++){
        string temp = s.substr(0,i+1);
        if(isValid(temp)){
            ipAddress(s.substr(i+1),dots+1,ans+temp+".",a);
        }
    }
}

int main() {
    vector<string> ans;
    ipAddress("255134567",0,"",ans);
    for(auto s : ans){
        cout<<s<<" ";
    }
    return 0;
}
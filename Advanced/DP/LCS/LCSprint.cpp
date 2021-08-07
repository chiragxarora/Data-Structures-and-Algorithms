#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Given 2 strings, print the longest common subsequence
string answer;

int LCS(string s1, string s2, string ans) {
    if(s1.length()==0 || s2.length()==0){
        if(ans.length()>answer.length()){
            answer = ans;
        }
        return 0;
    }
    if(s1[s1.length()-1]==s2[s2.length()-1]){
        // if character matches => lcs of 1 length found
        return LCS(s1.substr(0,s1.length()-1),s2.substr(0,s2.length()-1),ans+s1[s1.length()-1])+1;
    } else {
        // otherwise check by removing next character of each string one by one
        int option1 = LCS(s1.substr(0,s1.length()-1),s2,ans);
        int option2 = LCS(s1,s2.substr(0,s2.length()-1),ans);
        return max(option1,option2);
    }
}

// printing LCS from traversing the Bottom Up DP array

void LCS_BU(string s1, string s2) {
    int** dp = new int *[s1.length()+1];
    for(int i=0;i<s1.length()+1;i++){
        dp[i] = new int [s2.length()+1];
    }
    for(int i=0;i<s1.length()+1;i++){
        for(int j=0;j<s2.length()+1;j++){
            if(i==0||j==0){
                dp[i][j] = 0;
            }
            else {
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
    }
    string ans = "";
    int i = s1.length(), j = s2.length();
    while(i!=0 && j!=0){
        if(s1[i-1]==s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        } else {
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            } else {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}


int main() {
    string s1 = "abcabn";
    string s2 = "abdabkdn";
    cout<<LCS(s1,s2,"")<<endl;
    reverse(answer.begin(),answer.end());
    cout<<answer<<endl;
    LCS_BU(s1,s2);
    return 0;
}
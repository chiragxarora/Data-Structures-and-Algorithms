#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// LONGEST PALINDROMIC SUBSEQUENCE

int LCS(string s1, string s2) {
    int* dp = new int [s2.length()+1];
    for(int i=0;i<s2.length()+1;i++){
        dp[i] = 0;
    }
    int prevDiag = dp[0];
    for(int i=1;i<s1.length()+1;i++){
        for(int j=1;j<s2.length()+1;j++){
            int prevUp = dp[j];
            int prevLeft = dp[j-1];
            if(s1[i-1]==s2[j-1]){
                dp[j] = prevDiag+1;
            } else {
                dp[j] = max(prevUp,prevLeft);
            }
            if(j!=s2.length()){
                prevDiag = prevUp;
            } else {
                prevDiag = dp[0];
            }
        }
    }
    return dp[s2.length()];
}

int main() {
    string s1 = "mbadbm";
    string s2 = s1;
    reverse(s2.begin(),s2.end());
    cout<<LCS(s1,s2);
    return 0;
}
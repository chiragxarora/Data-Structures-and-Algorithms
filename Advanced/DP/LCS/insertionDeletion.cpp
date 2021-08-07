#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Given a string s1 and s2, find minimum number of operations needed to convert s1 into s2;
// operations allowed are insertion and deletion of a single character at a time

int LCS_BU(string s1, string s2) {
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
    return dp[s1.length()][s2.length()];
}


int main() {
    string s1 = "heap";
    string s2 = "epa";
    int lenLCS = LCS_BU(s1,s2);
    int insertions = s2.length() - lenLCS;
    int deletions = s1.length() - lenLCS;
    cout<<insertions+deletions<<endl;
    return 0;
}
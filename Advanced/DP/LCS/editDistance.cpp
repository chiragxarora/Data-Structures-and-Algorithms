#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// Edit Distance

int editDistance(string s1, string s2){
    if(s1.length()==0 || s2.length()==0){
        return max(s1.length(), s2.length());
    }
    char ch1 = s1[s1.length()-1];
    char ch2 = s2[s2.length()-1];
    string s11 = s1.substr(0,s1.length()-1);
    string s22 = s2.substr(0,s2.length()-1);
    if(ch1==ch2){
        return editDistance(s11,s22);
    } else {
        int Replace = editDistance(s11,s22) + 1;
        int Delete = editDistance(s11,s2) + 1;
        int Insert = editDistance(s1,s22) + 1;
        return min(min(Insert,Delete),Replace);
    }
}

int editDistanceTD(string s1, string s2, int** dp){
    if(s1.length()==0 || s2.length()==0){
        return max(s1.length(), s2.length());
    }
    if(dp[s1.length()][s2.length()]!=-1){
        return dp[s1.length()][s2.length()];
    }
    char ch1 = s1[s1.length()-1];
    char ch2 = s2[s2.length()-1];
    string s11 = s1.substr(0,s1.length()-1);
    string s22 = s2.substr(0,s2.length()-1);
    if(ch1==ch2){
        return dp[s1.length()][s2.length()] = editDistanceTD(s11,s22,dp);
    } else {
        int Replace = editDistanceTD(s11,s22,dp) + 1;
        int Delete = editDistanceTD(s11,s2,dp) + 1;
        int Insert = editDistanceTD(s1,s22,dp) + 1;
        return dp[s1.length()][s2.length()] = min(min(Insert,Delete),Replace);
    }
}

int editDistanceBU(string s1, string s2) {
    int** dp = new int *[s1.length()+1];
    for(int i=0;i<s1.length()+1;i++){
        dp[i] = new int [s2.length()+1];
    }
    for(int i=0;i<s1.length()+1;i++){
        dp[i][0] = i;
    }
    for(int i=0;i<s2.length()+1;i++){
        dp[0][i] = i;
    }
    dp[0][0] = 0;
    for(int i=1;i<s1.length()+1;i++){
        for(int j=1;j<s2.length()+1;j++){
            if(s1[i-1]!=s2[j-1]){    
                int Replace = dp[i-1][j-1] + 1;
                int Delete = dp[i-1][j] + 1;
                int Insert = dp[i][j-1] + 1;
                dp[i][j] = min(min(Insert,Delete),Replace);
            } else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    }
    return dp[s1.length()][s2.length()];
}

int main() {
    string s1 = "sea";
    string s2 = "eat";
    cout<<editDistance(s1,s2)<<endl;
    int** dp = new int *[s1.length()+1];
    for(int i=0;i<s1.length()+1;i++){
        dp[i] = new int [s2.length()+1];
    }
    for(int i=0;i<s1.length()+1;i++){
        for(int j=0;j<s2.length()+1;j++){
            dp[i][j] = -1;
        }
    }
    cout<<editDistanceTD(s1,s2,dp)<<endl;
    cout<<editDistanceBU(s1,s2)<<endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cstring>

using namespace std;

// Palindrome Partitioning

bool isPalindrome(string str) {
    int start = 0, end = str.length()-1;
    while(start<end){
        if(str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int palindromePartitioning(string str, int* dp) {
    if(str.length()<=1 || isPalindrome(str)){
        return 0;
    }
    if(dp[str.length()]!=-1){
        return dp[str.length()];
    }
    int ans = INT_MAX;
    for(int k=0;k<str.length()-1;k++){
        string fp = str.substr(0,k+1);
        if(isPalindrome(fp)){
            string sp = str.substr(k+1);
            ans = min(ans, palindromePartitioning(sp,dp)+1);
        }
    }
    return dp[str.length()] = ans;
}

int main() {
    string str = "nitinnnp";
    int* dp = new int[str.length()+1];
    for(int i=0;i<str.length()+1;i++){
        dp[i] = -1;
    }
    cout<<palindromePartitioning(str,dp);
    return 0;
}
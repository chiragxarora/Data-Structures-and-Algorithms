// #include <iostream>
// #include <algorithm>

// using namespace std;
// int val = 0;
// // Given 2 strings, find the length of longest common substring

// int LCSubstring(string s1, string s2) {
//     if(s1.length()==0 || s2.length()==0){
//         return 0;
//     }
//     int ans = 0;
//     if(s1[s1.length()-1]==s2[s2.length()-1]){
//         int option = LCSubstring(s1.substr(0,s1.length()-1),s2.substr(0,s2.length()-1))+1;
//         val = max(val,option);
//     }
//     int option1 = LCSubstring(s1.substr(0,s1.length()-1),s2);
//     int option2 = LCSubstring(s1,s2.substr(0,s2.length()-1));
//     ans = max(ans,max(option1,option2));
//     return ans;
// }

// int LCS_TD(string s1, string s2, int** dp) {
//     if(s1.length()==0 || s2.length()==0){
//         return 0;
//     }
//     if(dp[s1.length()][s2.length()]!=-1){
//         return dp[s1.length()][s2.length()];
//     }
//     if(s1[s1.length()-1]==s2[s2.length()-1]){
//         return dp[s1.length()][s2.length()] = LCS_TD(s1.substr(0,s1.length()-1),s2.substr(0,s2.length()-1),dp)+1;
//     } else {
//         int option1 = LCS_TD(s1.substr(0,s1.length()-1),s2,dp);
//         int option2 = LCS_TD(s1,s2.substr(0,s2.length()-1),dp);
//         return dp[s1.length()][s2.length()] = max(option1,option2);
//     }
// }

// int LCS_BU(string s1, string s2) {
//     int** dp = new int *[s1.length()+1];
//     for(int i=0;i<s1.length()+1;i++){
//         dp[i] = new int [s2.length()+1];
//     }
//     for(int i=0;i<s1.length()+1;i++){
//         for(int j=0;j<s2.length()+1;j++){
//             if(i==0||j==0){
//                 dp[i][j] = 0;
//             }
//             else {
//                 if(s1[i-1]==s2[j-1]){
//                     dp[i][j] = dp[i-1][j-1]+1;
//                 } else {
//                     dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
//                 }
//             }
//         }
//     }
//     return dp[s1.length()][s2.length()];
// }

// int main() {
//     string s1 = "zabcabf";
//     string s2 = "pabdabcabe";
//     cout<<LCSubstring(s1,s2,0)<<endl;
//     int** dp = new int *[s1.length()+1];
//     for(int i=0;i<s1.length()+1;i++){
//         dp[i] = new int [s2.length()+1];
//     }
//     for(int i=0;i<s1.length()+1;i++){
//         for(int j=0;j<s2.length()+1;j++){
//             dp[i][j] = -1;
//         }
//     }
//     // cout<<LCS_TD(s1,s2,dp)<<endl;
//     // cout<<LCS_BU(s1,s2)<<endl;
//     return 0;
// }
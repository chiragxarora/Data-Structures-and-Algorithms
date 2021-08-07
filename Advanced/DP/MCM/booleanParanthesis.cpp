#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cstring>
#include <unordered_map>

using namespace std;

// Boolean Paranthesis: given an expression, find number of ways of paranthesisation such that expression evaluates to TRUE

// T | F | F & T ^ F

int booleanParanthesis(string str, int i, int j, bool isTrue) {
    if(i==j){
        if(isTrue) return str[i]=='T' ? 1 : 0;
        if(!isTrue) return str[i]=='F' ? 1 : 0;
    }
    int ans = 0;
    for(int k=i+1;k<j;k+=2){
        int lT = booleanParanthesis(str,i,k-1,true);
        int lF = booleanParanthesis(str,i,k-1,false);
        int rT = booleanParanthesis(str,k+1,j,true);
        int rF = booleanParanthesis(str,k+1,j,false);
        if(str[k]=='|' && isTrue){
            ans += rT*lT + rT*lF + lT*rF;
        }
        if(str[k]=='|' && !isTrue){
            ans += rF*lF;
        }
        if(str[k]=='&' && isTrue){
            ans += lT*rT;
        }
        if(str[k]=='&' && !isTrue){
            ans += rF*lF + rT*lF + lT*rF;
        }
        if(str[k]=='^' && isTrue){
            ans += lT*rF + lF*rT;
        }
        if(str[k]=='^' && !isTrue){
            ans += lT*rT + lF*rF;
        }
    }
    return ans;
}

int dp[201][201][2];

int booleanParanthesisTD(string str, int i, int j, bool isTrue, int dp [201][201][2]) {
    if(i==j){
        if(isTrue) return str[i]=='T' ? 1 : 0;
        if(!isTrue) return str[i]=='F' ? 1 : 0;
    }
    if(dp[i][j][isTrue]!=-1){
        return dp[i][j][isTrue];
    }
    int ans = 0;
    for(int k=i+1;k<j;k+=2){
        int lT = booleanParanthesisTD(str,i,k-1,true,dp);
        int lF = booleanParanthesisTD(str,i,k-1,false,dp);
        int rT = booleanParanthesisTD(str,k+1,j,true,dp);
        int rF = booleanParanthesisTD(str,k+1,j,false,dp);
        if(str[k]=='|' && isTrue){
            ans += rT*lT + rT*lF + lT*rF;
        }
        if(str[k]=='|' && !isTrue){
            ans += rF*lF;
        }
        if(str[k]=='&' && isTrue){
            ans += lT*rT;
        }
        if(str[k]=='&' && !isTrue){
            ans += rF*lF + rT*lF + lT*rF;
        }
        if(str[k]=='^' && isTrue){
            ans += lT*rF + lF*rT;
        }
        if(str[k]=='^' && !isTrue){
            ans += lT*rT + lF*rF;
        }
    }
    return dp[i][j][isTrue] = ans;
}

int main() {
    string str = "T^F|F&T|F^T^F";
    cout<<booleanParanthesis(str,0,str.length()-1,true)<<endl;
    memset(dp,-1,sizeof(dp));
    cout<<booleanParanthesisTD(str,0,str.length()-1,true,dp);
    return 0;
}
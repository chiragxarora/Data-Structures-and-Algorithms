#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

// Matrix Chain Multiplication

int MCM(vector<int> v, int i, int j) {
    if(i>=j) {
        return 0;
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int firstPart = MCM(v,i,k);   // dimension = (i-1)*k
        int secondPart = MCM(v,k+1,j);   // dimension = k*j
        int selfWork = v[i-1]*v[k]*v[j];
        ans = min(ans,firstPart+secondPart+selfWork);
    }
    return ans;
}

int MCM_TD(vector<int> v, int i, int j, int** dp) {
    if(i>=j) {
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    for(int k=i;k<j;k++){
        int firstPart = MCM_TD(v,i,k,dp);   // dimension = (i-1)*k
        int secondPart = MCM_TD(v,k+1,j,dp);   // dimension = k*j
        int selfWork = v[i-1]*v[k]*v[j];
        ans = min(ans,firstPart+secondPart+selfWork);
    }
    return dp[i][j] = ans;
}

int main() {
    vector<int> v {10,5,20,15};
    cout<<MCM(v,1,v.size()-1)<<endl;
    int** dp = new int *[v.size()+1];
    for(int i=0;i<v.size()+1;i++){
        dp[i] = new int [v.size()+1];
    }
    for(int i=0;i<v.size()+1;i++){
        for(int j=0;j<v.size()+1;j++){
            dp[i][j] = -1;
        }
    }
    cout<<MCM_TD(v,1,v.size()-1,dp)<<endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

float knapsack(vector<int> mo, vector<int> mt, int idx, int k, int obt, int tot, float** dp) {
    if(k==0){
        float avg = (float)((obt+0.0)/tot);
        avg *= 100;
        return avg;
    }
    if(idx==0) return 0.0;
    if(dp[idx][k]!=-1.0){
        return dp[idx][k];
    }
    // pick
    float a1 = knapsack(mo,mt,idx-1,k-1,obt+mo[idx-1],tot+mt[idx-1],dp);
    // not pick
    float a2 = knapsack(mo,mt,idx-1,k,obt,tot,dp);
    return dp[idx][k] =  max(a1,a2);
}

int main() {
    vector<int> mo {10,5,4,4,6,11,30,10,5,4,4,6,11,30,10,5,4,4,6,11,30,10,5,4,4,6,11,30,10,5,4,4,6,11,30,10,5,4,4,6,11,30,10,5,4,4,6,11,30,10,5,4,4,6,11,30};
    vector<int> mt {10,10,5,5,10,25,50,10,10,5,5,10,25,50,10,10,5,5,10,25,50,10,10,5,5,10,25,50,10,10,5,5,10,25,50,10,10,5,5,10,25,50,10,10,5,5,10,25,50,10,10,5,5,10,25,50};
    float ** dp;
    int k = 35;
    dp = new float *[mo.size()+1];
    for(int i=0;i<mo.size()+1;i++){
        dp[i] = new float [k+1];
    }
    for(int i=0;i<mo.size()+1;i++){
        for(int j=0;j<k+1;j++){
            dp[i][j] = -1.0;
        }
    }
    cout<<knapsack(mo,mt,mo.size(),k,0,0,dp);
    return 0;
}
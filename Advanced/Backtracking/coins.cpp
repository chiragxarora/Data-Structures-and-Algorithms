#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Coins combination problems

void coinRespect1(vector<int> denom, int idx, int amount, string ans) {
    if(amount==0) {
        cout<<ans<<endl;
        return;
    }
    if(amount<0 || idx==denom.size()) {
        return;
    }
    // a coin will have  options, either contribute to the amount or not
    // include
    coinRespect1(denom,idx,amount-denom[idx],ans+to_string(denom[idx]));
    // exclude
    coinRespect1(denom,idx+1,amount,ans);
}

void userRespect1(vector<int> denom, int idx, int amount, string ans) {
    if(amount==0) {
        cout<<ans<<endl;
        return;
    }
    if(amount<0 || idx==denom.size()) {
        return;
    }
    // user will have n choices to contribute to the amount (n = no. of denom)

    for(int i=idx;i<denom.size();i++){
        userRespect1(denom,i,amount-denom[i],ans+to_string(denom[i]));
    }
    
}

void userRespect1Permute(vector<int> denom, int idx, int amount, string ans) {
    if(amount==0) {
        cout<<ans<<endl;
        return;
    }
    if(amount<0 || idx==denom.size()) {
        return;
    }
    for(int i=0;i<denom.size();i++){
        userRespect1Permute(denom,i,amount-denom[i],ans+to_string(denom[i]));
    }
    
}


int main() {
    vector<int> denom {1,2,5};
    coinRespect1(denom,0,10,"");  // solving with coin perspective && one denom can be repeated
    userRespect1(denom,0,5,"");  // solving same problem with user perspective ie user gets to pick coin of his choice
    userRespect1Permute(denom,0,3,"");  // same as userRespect1 but with permutations => 122 is different than 212
    return 0;
}
#include <iostream>
#include <string>

using namespace std;

// for given n, generate valid brackets using n pairs of round brackets
// n = 2 =>  ()() && (())

void validBrackets(int n, int len, int open, int close, string ans) {
    if(len==0){
        cout<<ans<<endl;
        return;
    }
    if(open<n){
        validBrackets(n,len-1,open+1,close,ans+"(");
    }
    if(close<open){
        validBrackets(n,len-1,open,close+1,ans+")");
    }
}

int main() {
    validBrackets(3,6,0,0,"");
    return 0;
}
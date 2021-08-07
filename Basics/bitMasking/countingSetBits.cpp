#include <iostream>
#include <algorithm>

using namespace std;

// count set bits present in a number

int setBits(int n){
    int ans = 0;
    while(n!=0){
        ans += n & 1;
        n = n >> 1;
    }
    return ans;
}

int setBitsFast(int n){
    int ans = 0;
    while(n!=0) {
        n = n&(n-1);
        ans++;
    }
    return ans;
}

int main() {
    int n = 87;
    cout<<setBits(n)<<endl;
    cout<<setBitsFast(n)<<endl;
    return 0;
}
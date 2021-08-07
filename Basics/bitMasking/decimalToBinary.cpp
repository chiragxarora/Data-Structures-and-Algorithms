#include <iostream>
#include <algorithm>

using namespace std;

// convert decimal to binary using bitwise operators

int decimalToBinary(int n){
    int ans = 0, p = 1;
    while(n!=0){
        int lastBit = n&1;
        ans += lastBit*p;
        n = n>>1;
        p *= 10;
    }
    return ans;
}

int main() {
    int n = 34;
    cout<<decimalToBinary(n)<<endl;
    return 0;
}
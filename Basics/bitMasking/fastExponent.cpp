#include <iostream>
#include <algorithm>

using namespace std;

// calculate a ^ b in an efficient way

int main() {
    /*
    a ^ b => first we will convert b into binary
    suppose its 2^5 then 5 is 101 => 2 ^ 101 = 2^(1*2^2) * 2^(0*2^1) * 2^(1*2^0) = 2^4 * 2^1 = 2^5
    */
    int a = 3, b = 5, ans = 1;
    while(b!=0){
        int lastBit = b&1;
        if(lastBit == 0) {
            
        } else {
            ans *= a;
        }
        a *= a;
        b= b >> 1;
    }
    cout<<ans;
    return 0;
}
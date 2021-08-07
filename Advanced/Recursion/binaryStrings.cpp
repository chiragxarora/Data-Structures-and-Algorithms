#include <iostream>
#include <algorithm>

using namespace std;

// given n, find binary strings of length n, with no consecutive 1s

int binaryStrings(int n, int last) {
    if(n==0) {
        return 1;
    }
    int one = 0;
    if(last!=1) {
        one = binaryStrings(n-1,1);
    }
    int zero = binaryStrings(n-1,0);
    return one + zero;
}

int main() {
    cout<<binaryStrings(2,-1);
    return 0;
}
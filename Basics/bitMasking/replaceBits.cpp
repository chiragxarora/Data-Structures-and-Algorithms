#include <iostream>
#include <algorithm>

using namespace std;

// Given, N = 0110101010110, i,j and M = 1010
// replace bits from i to j in N with M

int clearRangeOfBits(int n, int i, int j){
    int ones = ~0;
    int a = ones << (j+1); // left part of the mask
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int replaceBits(int n, int i, int j, int m) {
    n = clearRangeOfBits(n,i,j);
    int mask = m << i;
    return n | mask;
}

int main() {
    int n = 21, i = 3, j = 6, m = 7;
    cout<<replaceBits(n,i,j,m);
    return 0;
}
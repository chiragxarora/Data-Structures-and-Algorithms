#include <iostream>
#include <algorithm>

using namespace std;

// common bit tasks

int isOdd(int n)
{
    return n & 1; // returns last bit
}

int getBit(int n, int i)
{
    n = n >> i;
    return n & 1;
}

int setBit(int n, int i) {
    int mask = 1<<i;
    return mask|n;
}

void clearBit(int *n, int i) {
    int mask = 1 << i;
    mask = ~ mask;
    *n = *n & mask;
}

void updateBit(int *n, int i, int v){
    int mask = ~(1 << i);
    int cleared_n = *n & mask;
    *n = cleared_n | (v << i);
}

int clearLastBits(int n, int i){
    int mask = -1 << i;
    return n & mask;
}

int clearRangeOfBits(int n, int i, int j){
    int ones = ~0;
    int a = ones << (j+1); // left part of the mask
    int b = (1 << i) - 1;
    int mask = a | b;
    return n & mask;
}

int main()
{
    // int n = 5;   // 00000101
    // if (isOdd(n))
    // {
    //     // cout << "odd\n";
    // }
    // else
    // {
    //     // cout << "even\n";
    // }
    // cout<<getBit(n,1)<<endl;
    // int num = 5;
    // num =setBit(num,1);
    // // cout<<num<<endl;
    // int x = 5;
    // // cout<<x<<endl;
    // clearBit(&x, 0);
    // // cout<<x<<endl;
    // int y = 5;
    // cout<<y<<endl;
    // updateBit(&y, 0, 0);
    // cout<<y<<endl;
    int n = 15;
    // cout<<clearLastBits(n,2);
    cout<<clearRangeOfBits(n,0,2);
    return 0;
}
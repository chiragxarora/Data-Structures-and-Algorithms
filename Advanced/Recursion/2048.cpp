#include <iostream>
#include <unordered_map>
#include<string>

using namespace std;

// given a number, convert it into words
// 2048 => two zero four eight

void speakNumber(int n, unordered_map<int,string> map) {
    // base case
    // find digit
    // rec()
    //print
    if(n==0){
        return;
    }
    int digit = n%10;
    speakNumber(n/10,map);
    cout<<map[digit]<<" ";
}


int main() {
    unordered_map<int,string> map;
    map[0] = "zero";
    map[1] = "one";
    map[2] = "two";
    map[3] = "three";
    map[4] = "four";
    map[5] = "five";
    map[6] = "six";
    map[7] = "seven";
    map[8] = "eight";
    map[9] = "nine";
    speakNumber(2048,map);
    return 0;
}
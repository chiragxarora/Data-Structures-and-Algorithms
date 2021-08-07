#include <iostream>
#include <string>

using namespace std;

// find no. of ways in which n friends can go to a party, one can either go solo or as a pair

int friendsPair(int n) {
    if(n<0) {
        return 0;
    }
    if(n==0) {
        return 1;
    }
    int solo = 1 * friendsPair(n-1);  // himself in 1 way, remaining in f(n-1) ways => total in 1*f(n-1) ways
    int pair = (n-1) * friendsPair(n-2); // can form n-1 pairs so himself in (n-1) ways, remaining people are n-2 so
    return solo + pair;
}

int main() {
    cout<<friendsPair(5);
    return 0;
}
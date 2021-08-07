#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

// given a string, find its all possible subsets/subsequences
// "abc" => "", "a", "b", "c", "ab", "bc", "ac", "abc"

void filterChars(int i, string s){
    string ans = "";
    int idx = 0;
    while(i!=0){
        int lastBit = i & 1;
        if(lastBit == 1) {
            ans += s[idx];
        }
        idx++;
        i = i >> 1;
    }
    cout<<ans<<endl;
}

int main() {
    string str = "abc";
    for(int i=0;i<(1<<str.length());i++){
        filterChars(i,str);
    }
    return 0;
}
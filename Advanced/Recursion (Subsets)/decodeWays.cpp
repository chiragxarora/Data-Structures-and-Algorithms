#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Decode ways : https://hack.codingblocks.com/app/contests/988/145/problem
// ** similar problem on leetcode but with DP : https://leetcode.com/problems/decode-ways/

char makeChar(string s) {
    int a = stoi(s);
    return (char)(a+96);
}

int getValue(string s) {
    return stoi(s);
}

void decodeWaysPrint(string str, string ans) {
    if(str.length()==0) {
        cout<<ans<<endl;
        return;
    }
    string s1 = str.substr(0,1);
    if(getValue(s1) >=1 && getValue(s1) <=9) {
        char ch = makeChar(s1);
        decodeWaysPrint(str.substr(1),ans+ch);
    }
    if(str.length()>=2) { 
        string s2 = str.substr(0,2);
        if(getValue(s2)<=26 && getValue(s2)>= 10) {
            char cc = makeChar(s2);
            decodeWaysPrint(str.substr(2),ans+cc);
        }
    }
}

int main() {
    decodeWaysPrint("122212","");
    return 0;
}
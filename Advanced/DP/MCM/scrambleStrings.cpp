#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#include <cstring>
#include <unordered_map>

using namespace std;

// Scramble strings

// string ans = s.substr(0,i) + s.substr(k+1,j-k) + s.substr(i,k-i+1) + s.substr(j+1);

bool scrambleStrings(string a, int i, int j, string b) {
    if(i==j){
        return false;
    }
    if(a==b){
        return true;
    }
    bool ans = false;
    for(int k=i;k<j;k++){
        bool left = scrambleStrings(a,i,k,b);
        bool right = scrambleStrings(a,k+1,j,b);
        
    }
    return ans;
}

int main() {
    string a = "great", b = "ategr";
    cout<<scrambleStrings(a,0,a.length()-1,b);
    return 0;
}
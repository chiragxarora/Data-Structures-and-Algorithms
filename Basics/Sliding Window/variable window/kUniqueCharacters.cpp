#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;

// Find longest substring with k unique characters
// aabacebebeb
void solve(string str, int k) {
    int i=0, j=0, sum=0, ans=0;
    unordered_map<char, int> map;
    while(j<str.size()){
        map[str[j]]++;
        while(map.size()>k){
            char ch = str[i];
            map[ch]--;
            i++;
            if(map[ch]==0){
                map.erase(ch);
            }
        }
        if(map.size()==k){
            cout<<str.substr(i,j-i+1)<<endl;
            ans = max(ans,j-i+1);
        }
        j++;
    }
}

int main() {
    string str = "aabacbebebe";
    int k = 3;
    solve(str,k);
    return 0;
}
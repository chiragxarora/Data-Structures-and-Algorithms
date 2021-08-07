#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int perfectString(string s, int k, char ch){
    int i=0,j=0,swaps=0,ans=0;
    for(int i=0;i<k;i++){
        if(s[i] != ch){
            swaps++;
        }
        j++;
    }
    while(i != s.length()-k){
        int len = k,cswaps=swaps;
        while(j<s.length() && s[j] == ch){
            j++;
            len++;
        } // abbaabab
        for(int z=j;z<s.length()&&cswaps<=k;z++){
            if(s[z]==ch ){
                if(cswaps <= k){
                    len++;
                }
            } else {
                if(cswaps == k){
                    break;
                }
                len++;
                cswaps++;
            }
        }
        if(len>ans){
            ans=len;
        }
        if(s[i] != ch){
            swaps--;
        }
        if(s[i+k] != ch){
            swaps++;
        }
        i++;
        j = i+k;
    }
    return ans;
}

int main() {
    string s = "aaaaaabab";
    int k = 3;
    char ch = 'b';
    cout<<perfectString(s,k,ch);
    return 0;
}
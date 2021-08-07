#include <iostream>
#include <string>
#include <vector>

using namespace std;

// for a given array/string, generate all its subsets/subsequences

int subsequencesPrint(string str, string ans) {
    if(str.length()==0){
        cout<<ans<<endl;
        return 1;
    }
    char ch = str[0];
    string rem = str.substr(1);
    int a = subsequencesPrint(rem,ans+ch);
    int b = subsequencesPrint(rem,ans);
    return a + b;
}

vector<string> subsequencesGet(string str) {
    if(str.length()==0) {
        vector<string> v;
        v.push_back("");
        return v;
    }
    // rec
    vector<string> remainingAns = subsequencesGet(str.substr(1));

    //self work
    vector<string> ans;
    for(int i=0;i<remainingAns.size();i++){
        ans.push_back(str[0] + remainingAns[i]);
        ans.push_back(remainingAns[i]);
    }
    return ans;
}

int main() {
    // for a string of length "n", there are 2^n subsequences
    cout<<subsequencesPrint("abc","");
    vector<string> ss = subsequencesGet("abc");
    for(auto x : ss) {
        cout<<x<<", ";
    }
    return 0;
}
#include <iostream>
#include <algorithm>
# include <string>

using namespace std;

bool compare(string a, string b){
    if(a.length() == b.length()){
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    string s[100];
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    sort(s,s+n,compare);  // by default does the lexicographic sorting
    for(int i=0;i<n;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}
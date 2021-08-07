#include <iostream>
#include <string>

using namespace std;

// given a string, replace each occurence of "pi" with its value(3.14)

void replacePi(string str, string ans, char prev) {
    if(str.length()==0) {
        cout<<ans;
        return;
    }
    char ch = str[0];
    if(ch != 'i') {
        replacePi(str.substr(1),ans+ch,ch);
    } else {
        if(prev=='p') {
            ans[ans.length()-1] = '3';
            ans += ".14";
            replacePi(str.substr(1),ans,ch);
        } else {
            replacePi(str.substr(1),ans+ch,ch);
        }
    }
}

int main() {
    replacePi("xyzpipiqweprtpiypi","",'_');
    return 0;
}
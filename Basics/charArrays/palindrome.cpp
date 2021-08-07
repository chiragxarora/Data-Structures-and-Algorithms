#include <iostream>
#include <cstring>
using namespace std;

bool isPalindrome(char a[]){
    int i=0,j=strlen(a)-1;
    while(i<j){
        if(a[i]!=a[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    char a[1000];
    cin.getline(a,1000);
    //cout<<a;
    if(isPalindrome(a)){
        cout<<"Yes";
    } else{
        cout<<"No";
    }
    return 0;
}
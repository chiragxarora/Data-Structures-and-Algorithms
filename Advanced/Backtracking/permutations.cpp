#include <iostream>
#include <string>

using namespace std;

// given an array, print all its permutations

void permute(char str[], int idx, int n) {
    if(str[idx]=='\0') {
        cout<<str<<endl;
        return;
    }
    for(int i=idx;i<n;i++){
        swap(str[idx],str[i]);
        permute(str,idx+1,n);
        swap(str[idx],str[i]);
    }
}

int main() {
    char str[] = {'a','b','c','\0'};
    int n = sizeof(str)/sizeof(char);
    permute(str,0,n);
    return 0;
}
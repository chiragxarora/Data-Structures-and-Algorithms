#include <iostream>
#include <cstring>
using namespace std;

// Remove consecutive duplicates
// cccoodingg => coding

void removeDuplicates(char a[]){
    int i=0,j=1;
    while(j!=strlen(a)-1){
        if(a[i]==a[j]){
            j++;
        } else {
            i++;
            a[i] = a[j];
            j++;
        }
    }
    a[i+1] = '\0';
}

int main() {
    char a[1000];
    cin.getline(a,100,'\n');
    removeDuplicates(a);
    cout<<a;
    return 0;
}
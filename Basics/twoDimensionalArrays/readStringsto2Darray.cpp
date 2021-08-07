#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Read a list of strings and store them as a 2d character array

int main() {
    char a[1000][1000];
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        cin.getline(a[i],1000);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
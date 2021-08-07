#include<iostream>
using namespace std;
int main() {
    int n,key,i;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<"Enter a number to be searched";
    cin>>key;
    for(i=0;i<n;i++) {
        if(a[i]==key) {
            break;
        }
    }
    if(i==n) {
        cout<<"Element not found!";
    } else {
        cout<<"Element found at index "<<i;
    }
    return 0;
}
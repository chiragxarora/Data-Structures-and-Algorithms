#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int maxm = INT_MIN, minm = INT_MAX;
    for(int i=0;i<n;i++) {
        // if(a[i]>max) {
        //     max = a[i];
        // }
        // if(a[i]<min) {
        //     min = a[i];
        // }
        maxm = max(maxm, a[i]);
        minm = min(minm, a[i]);
    }
    cout<<minm<<" "<<maxm;
    
    return 0;
}
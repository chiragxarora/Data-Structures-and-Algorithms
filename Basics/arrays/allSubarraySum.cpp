#include<iostream>
using namespace std;
int main() {
    int a[3] = {1,2,3};
    // number of subarrays when a[i] is the first element : n-i
    // number of subarrays when a[i] is not the first element : (n-i)*i
    int n = sizeof(a)/sizeof(int);
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<a[k]<<" ";
                // sum += a[k]; this will generate sum of all the subarrays
            }
            cout<<endl;
        }
    }
    return 0;
}
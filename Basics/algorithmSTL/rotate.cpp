#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(int);
    // next_permutation generates the next possible permutation which is just bigger than the current one
    next_permutation(arr,arr+n-1);
    // rotate(s,m,e) : rotate the array from start to end about the index "m"
    //rotate(arr,arr+3,arr+n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
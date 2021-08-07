#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    // Search => find()
    int key;
    cin>>key;
    auto it = find(arr, arr+n, key);  // returns the address of the key if found 
    int index = it - arr;   // to get index of key, we subtract the base address of arr
    if(index==n){
        cout<<"key not found";
    } else {
        cout<<"key found at index "<<index<<endl;
    }
    return 0;
}
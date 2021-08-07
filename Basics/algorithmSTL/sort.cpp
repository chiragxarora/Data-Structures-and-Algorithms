#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int a, int b){
    return a > b;
}

int main() {
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // sort an array usng sort function
    // sort(s, e, compare) : will sort the subarray from index s to index e (last index is not included)
    // compare will contain the logic of sorting (ascending, descending)
    sort(arr,arr+n, compare);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<", ";
    }
    return 0;
}
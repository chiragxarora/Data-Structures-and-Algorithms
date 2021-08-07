#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0, end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = (start+end)/2;
        if(key==arr[mid]){
            ans = mid;
            end = mid-1;
        } else if(key<arr[mid]){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int key;
    cin>>key;
    int idx = binarySearch(arr,n,key);
    cout<<idx;
    return 0;
}
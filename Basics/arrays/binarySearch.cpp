#include<iostream>
using namespace std;

int binarySearch (int a[], int n, int key) {
    int start = 0, end = n-1, ans = n, mid;
    while(start<=end) {
        mid = (start + end)/2;
        if(key==a[mid]) {
            ans = mid;
            break;
        } else if(key>a[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

int main() {
    int n,key,i;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    cout<<"Enter a number to be searched";
    cin>>key;
    int ans = binarySearch(a,n,key);
    if(ans==n) {
        cout<<"Element not found!";
    } else {
        cout<<"Element found at index "<<ans;
    }
    return 0;
}
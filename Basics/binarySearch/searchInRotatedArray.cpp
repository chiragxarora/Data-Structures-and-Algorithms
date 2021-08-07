#include <iostream>
#include <algorithm>

using namespace std;

int specialKey(int arr[], int n) {
     int start = 0, end = n-1;
     while(start <= end){
         int mid = (start+end)/2;
         if(arr[mid] < arr[mid-1]){
             return mid;
         } else if(arr[mid]<=arr[end]){
             end = mid - 1;
         } else {
             start = mid + 1;
         }

     }
     return -1;
}

int binarySearch(int arr[], int start, int end, int key){
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
    int arr[] = {60,70,80,3,4,50};  // sk = 3
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    int sk = specialKey(arr,n);
    if(sk==-1){
        int ans = binarySearch(arr,0,n-1,key);
        cout<<ans;
        return 0;
    }
    if(key>=arr[0]&&key<=arr[sk-1]){
        cout<<binarySearch(arr,0,sk-1,key);
    } else if(key>=arr[sk]&&key<=arr[n-1]){
        cout<<binarySearch(arr,sk,n-1,key);
    } else {
        cout<<-1;
    }

    return 0;
}
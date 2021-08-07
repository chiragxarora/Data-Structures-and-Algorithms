#include <iostream>
#include <algorithm>

using namespace std;

// Given an array find a number's first occurence, last occurence, all occurences

int firstOccurence(int arr[], int idx, int n, int key){
    if(idx == n){
        return -1;
    }
    if(arr[idx] == key){
        return idx;
    }
    int ans = firstOccurence(arr,idx+1,n,key);
    return ans;
}

int lastOccurence(int arr[], int idx, int n, int key){
    if(idx == n) {
        return -1;
    }
    int ans = lastOccurence(arr,idx+1,n,key);
    if(arr[idx] == key && idx > ans){
        ans = idx;
    }
    return ans;
}

void allOccurences(int arr[], int idx, int n, int key) {
    if(idx == n) {
        return;
    }
    if(arr[idx] == key) {
        cout<<idx<<" ";
    }
    allOccurences(arr,idx+1,n,key);
}

int main() {
    int arr[] = {1,3,6,9,2,7,3,4,2,2,8};
    int n = sizeof(arr)/sizeof(int);
    //cout<<firstOccurence(arr,0,n,2);
    //cout<<lastOccurence(arr,0,n,2)<<endl;
    allOccurences(arr,0,n,2);
    return 0;
}
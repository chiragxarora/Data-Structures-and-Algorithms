#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr[], int start, int end) {
    int mid = (start+end)/2;
    int temp[1000];
    int i=start,j=mid+1,k=start;
    while(i<=mid && j <= end) {
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=end) {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for(int i=start;i<=end;i++){
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int start, int end) {
    if(start >= end) {
        return;
    }
    int mid = (start + end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);
}

int main() {
    int arr[] = {1,2,3,2,1,4,7,8,0,4,5,10,9};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }   
    return 0;
}
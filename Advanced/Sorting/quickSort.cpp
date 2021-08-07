#include <iostream>
#include <algorithm>

using namespace std;

int part(int arr[], int start, int end) {
    int pivot = arr[end];
    int i=start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}

void quickSort(int arr[], int start, int end){
    if(start >= end) {
        return;
    }
    int pivot = part(arr,start,end);

    quickSort(arr,start,pivot-1);
    quickSort(arr,pivot+1,end);
}

int main() {
    int arr[] = {1,5,2,8,3,6,9,7,0,4};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    part(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
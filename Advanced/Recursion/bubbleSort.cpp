#include <iostream>
#include <algorithm>

using namespace std;

void bubbleSort(int arr[], int n, int idx, int out) {
    if(out==n-1){
        return;
    }
    if(idx == n-1) {
        bubbleSort(arr,n,0,out+1);
        return;
    }
    if(arr[idx] > arr[idx+1]){
        int temp = arr[idx];
        arr[idx] = arr[idx+1];
        arr[idx+1] = temp;
    }
    bubbleSort(arr,n,idx+1,out);
    
}

int main() {
    int arr[] = {5,3,2,10,4,6,1};  // 3 2 1 4 5 1 6
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr,n,0,0);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
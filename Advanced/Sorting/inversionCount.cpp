#include <iostream>

using namespace std;

int merge(int arr[], int start, int end) {
    int mid = (start+end)/2;
    int cnt=0;
    int temp[1000];
    int i=start,j=mid+1,k=start;
    while(i<=mid && j <= end) {
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        } else {
            cnt += mid-i+1;
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
    return cnt;
}

int mergeSort(int arr[], int start, int end) {
    if(start >= end) {
        return 0;
    }
    int mid = (start + end)/2;
    int a = mergeSort(arr,start,mid);
    int b = mergeSort(arr,mid+1,end);
    int c = merge(arr,start,end);
    return a+b+c;
}

int main() {
    int arr[] = {1,2,3,6,4,5,0};
    int n = sizeof(arr)/sizeof(int);
    cout<<mergeSort(arr,0,n-1);
       
    return 0;
}
#include<iostream>
using namespace std;

void kSumPairs(int arr[], int n, int target) {
    int start = 0, end = n-1, currentSum = 0;
    while(start<end) {
        currentSum = arr[start] + arr[end];
        if(currentSum == target) {
            cout<<arr[start]<<" "<<arr[end]<<endl;
            start++;
            end--;
        }
        if(currentSum < target) {
            start++;
        }
        if(currentSum > target) {
            end--;
        }
    }
}

int main() {
    int a[9] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(int);
    int target = 10;
    kSumPairs(a,n, target);
    return 0;
}
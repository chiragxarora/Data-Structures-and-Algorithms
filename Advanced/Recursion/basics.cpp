#include <iostream>
#include <algorithm>

using namespace std;

// Basic recursion problems

int factorial(int n){
    if(n == 0 || n == 1) {
        return 1;
    }
    int fn = factorial(n-1);
    int factorial = n * fn;
    return factorial;
}

int nthFibonacci(int n) {
    if(n==0||n==1){
        return n;
    }
    int nMinus1Fib = nthFibonacci(n-1);
    int nMinus2Fib = nthFibonacci(n-2);
    int nthFib = nMinus1Fib + nMinus2Fib;
    return nthFib;
}

void printNincreasing(int n) {
    if(n==0){
        return;
    }
    printNincreasing(n-1);
    cout<<n<<" ";
}

void printNdecreasing(int n) {
    if(n==0){
        return;
    }
    cout<<n<<" ";  // our work : print "n"
    printNdecreasing(n-1);  // recursion work : let recursion print remaining numbers in dec order
}

bool isSorted(int arr[], int n, int idx) {
    if(n<=1 || idx == n-1){
        return true;
    }
    bool current = false;
    if(arr[idx] < arr[idx+1]){
        current = true;
    } else {
        return false;
    }
    bool remaining = isSorted(arr,n,idx+1);
    return remaining && current;
}

int binarySearch(int arr[], int start, int end, int n, int key) {
    if(start > end) {
        return -1;
    }
    int mid = (start + end)/2;
    int ans = -1;
    if(arr[mid] == key) {
        return mid;
    } else if (arr[mid] > key) {
        ans = binarySearch(arr,start,mid-1,n,key);
    } else {
        ans = binarySearch(arr,mid+1,end,n,key);
    }
    return ans;
}

int power(int a, int n){
    if(n==0){
        return 1;
    }
    int ans = a * power(a,n-1);
    return ans;
}

int product(int a, int b){
    if(b==1) {
        return a;
    }
    int prod = a + product(a,b-1);
    return prod;

}

int main() {
    //cout<<factorial(5)<<endl;
    //cout<<nthFibonacci(4)<<endl;
    //printNincreasing(5);
    //cout<<endl;
    //printNdecreasing(5);
    //cout<<endl;
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    //cout<<isSorted(arr,n,0);
    //cout<<binarySearch(arr,0,n-1,n,56)<<endl;
    //cout<<power(5,4)<<endl;
    cout<<product(12,15)<<endl;
    return 0;
}
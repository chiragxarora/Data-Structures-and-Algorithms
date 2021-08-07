#include <iostream>
#include <algorithm>

using namespace std;

// A list has n numbers and except two numbers, all are occuring twice. Find the two unique numbers

int getFirstSetBit(int n){
    int lastBit = -1, i=0;
    while(true){
        lastBit = n&1;
        if(lastBit == 1){
            return i;
        }
        i++;
        n = n >> 1;
    }
    return -1;
}

int getIthBit(int n, int i){
    int lastBit = -1;
    while(true){
        lastBit = n&1;
        if(i == 0){
            return lastBit;
        }
        i--;
        n = n >> 1;
    }
    return -1;
}

int main() {
    int arr[] = {1,1,8,5,3,6,8,6,4,7,4,5,11,7};
    int n = sizeof(arr)/sizeof(int);
    int res = 0;
    for(int i=0;i<n;i++){
        res = res ^ arr[i];
    }
    int idx = getFirstSetBit(res);
    int res2 = 0;
    for(int i=0;i<n;i++){
        if(getIthBit(arr[i], idx)){
            res2 = res2 ^ arr[i];
        }
    }
    cout<<res2<<" "<<(res^res2);
    return 0;
}
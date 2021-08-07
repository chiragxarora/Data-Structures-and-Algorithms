#include <iostream>
#include <algorithm>

using namespace std;

// A list has n numbers and except one, all are occuring twice. Find the unique number

int main() {
    int arr[] = {1,1,8,5,6,8,6,4,7,4,5,3,7};
    int n = sizeof(arr)/sizeof(int);
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = ans ^ arr[i];
    }
    cout<<ans;
    return 0;
}
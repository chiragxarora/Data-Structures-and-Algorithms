#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

// in a given matrix, find the maximum possible sum of a submatrix
// given matrix is row and col wise sorted
// solution
// prepare a suffux sum matrix and find the maximum element of that matrix

int maxSumSubmatrix( int arr [100][100], int n){
    // col wise addition
    for(int i = n-1;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            arr[i][j] += arr[i][j+1];
        }
    }
    // row wise addition
    for(int i=n-1;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            arr[j][i] += arr[j+1][i];
        }
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(arr[i][j]>=ans){
                ans = arr[i][j];
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    int arr[100][100];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout<<maxSumSubmatrix(arr,n)<<endl;
    return 0;
}
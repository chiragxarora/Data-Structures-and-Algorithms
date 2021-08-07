#include <iostream>
#include <algorithm>

using namespace std;

// rotate image by 90 degrees anticlock wise

void rotate(int arr[][100], int n){
    // reverse each row
    for(int i=0;i<n;i++){
        int start = 0, end = n-1;
        while(start < end){
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
    // transpose of matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

void rotate_stl(int arr[][100], int n){
    // reverse each row using reverse()
    for(int i=0;i<n;i++){
        reverse(arr[i],arr[i]+n);
    }
    // transpose of matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }
}

int main() {
    int arr[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    rotate_stl(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
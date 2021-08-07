#include <iostream>
#include <algorithm>

using namespace std;

// search in a row and col wise sorted array
// either start searching from a[0][n-1] or a[n-1][0]

int main() {
    int arr[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    int r=0,c=n-1;
    while(r<n-1 && c >=0) {
        if(key == arr[r][c]){
            cout<<"Found at ("<<r<<","<<c<<") th position"<<endl;
            return 0;
        }
        else if(key > arr[r][c]){
            r++;
        }
        else {
            c--;
        }
    }
    cout<<"Not Found"<<endl;
    
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // there is no way of directly creating dynamic 2d arrays
    // we can only create multiple 1d arrays and combine them
    // in heap each array is stored at random location so for 2d array, we need to store location of
    // starting address of each row
    // for that we must create an array of pointers of size = no. of rows of 2d array  // new int *[r]
    // we need another pointer variable to store the address of this array of pointers  // int ** arr;

    int ** arr;
    int r,c;
    cin>>r>>c;

    // create an array of row heads
    
    arr = new int *[r];

    // create a 2d array

    for(int i=0;i<r;i++){
        arr[i] = new int [c];
    }

    // now we can take input and print output as usual

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int val;
            cin>>val;
            arr[i][j] = val;
        }
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
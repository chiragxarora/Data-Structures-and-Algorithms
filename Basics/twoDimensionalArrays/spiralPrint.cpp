#include <iostream>
using namespace std;

// spiral print (traversal)

int main() {
    int a[100][100];
    int row,col;
    cin>>row>>col;
    // iterate over array
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cin>>a[r][c];
        }
    }
    int sr=0, er=row-1, sc=0, ec=col-1,count=0;
    while(count<row*col){
        // start row
        if(count>=row*col){
            break;
        }
        for(int i=sc;i<=ec;i++){
            cout<<a[sr][i]<<" ";
            count++;
        }
        sr++;
        // end col
        if(count>=row*col){
            break;
        }
        for(int i=sr;i<=er;i++){
            cout<<a[i][ec]<<" ";
            count++;
        }
        ec--;
        // end row
        if(count>=row*col){
            break;
        }
        for(int i=ec;i>=sc;i--){
            cout<<a[er][i]<<" ";
            count++;
        }
        er--;
        // start col
        if(count>=row*col){
            break;
        }
        for(int i=er;i>=sr;i--){
            cout<<a[i][sc]<<" ";
            count++;
        }
        sc++;
    }
    return 0;
}
#include <iostream>
using namespace std;

// wave print (traversal)

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
    int i=1;
    for(int c=0;c<col;c++){
        if(i%2==1){  // bottom to top
            for(int r=row-1;r>=0;r--){
                cout<<a[r][c]<<" ";
            }
        } else {  // top to bottom
            for(int r=0;r<row;r++){
                cout<<a[r][c]<<" ";
            }
        }
        i++;
    }
    return 0;
}
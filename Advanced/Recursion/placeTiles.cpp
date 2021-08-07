#include <iostream>
#include <algorithm>

using namespace std;

// given a wall of size (4,n), find no. of ways to build the wall with tiles of size (1,4) and (4,1)

int placeTiles(int len) {
    if(len <= 0) {
        return 0;
    }
    if(len==4){
        return 2;
    }
    if(len <4 && len > 0) {
        return 1;
    }
    int horizontal = placeTiles(len-4);
    int vertical = placeTiles(len-1);
    return horizontal + vertical;
}

int main() {
    cout<<placeTiles(6);
    return 0;
}
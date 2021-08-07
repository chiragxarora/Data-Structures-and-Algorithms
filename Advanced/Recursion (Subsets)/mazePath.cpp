#include <iostream>
#include <string>

using namespace std;

// given a 2d maze, print ways to reach end row end col, from start row start col { (0,0) => (n,n) }

void mazePath(int cr, int cc, int er, int ec, string ans) {
    if(cr==er && cc==ec) {
        cout<<ans<<endl;
        return;
    }

    if(cr>er || cc>ec) {
        return;
    }

    mazePath(cr,cc+1,er,ec,ans+"H");   // horizontal
    mazePath(cr+1,cc,er,ec,ans+"V");   // vertical
    mazePath(cr+1,cc+1,er,ec,ans+"D");   // diagonal
}

int main() {
    mazePath(0,0,2,2,"");
    return 0;
}
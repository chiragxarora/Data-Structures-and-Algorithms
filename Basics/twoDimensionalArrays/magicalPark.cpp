#include <iostream>
using namespace std;

// problem link : https://hack.codingblocks.com/app/practice/6/1051/problem

int main() {
    char a[100][100];
    int row,col,k,s;
    cin>>row>>col>>k>>s;
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            cin>>a[r][c];
        }
    }
    for(int r=0;r<row;r++){
        for(int c=0;c<col;c++){
            if(c!=col-1 && a[r][c]!='#'){
				s-=1;
			}
            if(s < k){
                cout<<"No";
                return 0;
            }
            if(a[r][c]=='.'){
                s -= 2;
            }
            else if(a[r][c]=='*'){
                s += 5;
            }
            else{
                c = col;
            }
            
        }
    }
    cout<<"Yes\n"<<s;
    return 0;
}
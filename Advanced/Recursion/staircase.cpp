#include <iostream>
#include <string>

using namespace std;

// stairs of len = n, can take jump of 1,2,3 : find ways to reach top from bottom

int staircase(int n, string ans) {
    if(n<0) {
        return 0;
    }
    if(n==0) {
        cout<<ans<<endl;
        return 1;
    }

    int j1 = staircase(n-1, ans+'1');
    int j2 = staircase(n-2, ans+'2');
    int j3 = staircase(n-3, ans+'3');
    return j1+j2+j3;
}

int main() {
    cout<<staircase(4,"");
    return 0;
}
#include <iostream>

using namespace std;

int power(int a, int n){
    if(n==0) {
        return 1;
    }
    int half = power(a,n/2);
    int ans;
    if(n%2==0){
        ans = half * half;
    } else {
        ans = half * half * a;
    }
    return ans;
}

int main() {
    cout<<power(3,4);
    return 0;
}
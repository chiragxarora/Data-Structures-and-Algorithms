#include <iostream>
#include <algorithm>

using namespace std;

// Tower of Hanoi problem

int toh(int n, char initial, char final, char aux) {
    if(n==0){
        //cout<<"moving "<<n<<" from "<<initial<<" to "<<final<<endl;
        return 0;
    }
    int a = toh(n-1,initial,aux,final);
    cout<<"moving "<<n<<" from "<<initial<<" to "<<final<<endl;
    int b = toh(n-1,aux,final,initial);
    return a + b + 1;
}

int main() {
    cout<<toh(3,'a','c','b');
    return 0;
}
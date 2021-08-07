#include <iostream>
using namespace std;

void readLine(char a[], int maxLen, char delim = '\n') {
    int i=0;
    char ch = cin.get();
    while(ch != delim) {
        a[i] = ch;
        i++;
        if(i == maxLen-1) {
            break;
        }
        ch = cin.get();
    }
    a[i] = '\0';
}

int main() {
    // Reading a line/parra from terminal
    char a[1000];
    // cin>>a;         // reads only continous characters, breaks on receiving a new line or space
    // cout<<a;

    // cin.get() reads a single character at a time
    // using this, we can put a loop and read until we get a new line '/n'
    // readLine(a,100);
    // this readLine method is already defined in c++ libs as cin.getline()
    cin.getline(a,100,'\n');
    cout<<a;
    return 0;
}
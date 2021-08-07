#include <iostream>
using namespace std;

int main() {
    int b[] = {1,2,3};
    cout<<b<<endl;    // address of first element
    char a[] = {'a','b','c','d','e', '\0'};
    cout<<a<<endl;    // contents of the array {due to operator overloading}
    // character array end with a null character which is '\0'
    // INPUT
    char str[10];
    cin>>str;   // no loop required for input of an character array (unlike integer arrays)
    cout<<str;
    // Every string in c++ must be terminated by a null character
    // otherwise it will print upto a point where it finds a null character
    return 0;
}
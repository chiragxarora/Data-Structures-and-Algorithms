#include <iostream>
#include <algorithm>

using namespace std;

// 2d character arrays

int main() {
    // one way
    // char arr[][10] = {{'a','b','c','\0'},{'d','e','f','\0'}};
    // another way : no need to put null character this way
    char arr[][10] = {"abc", "defg", "h"};
    cout<<arr[0]<<endl<<arr[1]<<endl<<arr[2];
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // static allocation
    // here deallocation is done by compiler
    int a[50];
    cout<<sizeof(a)<<endl;
    // here a cannot be overwritten because its a constant inside RAM
    // dynamic allocation
    int n;
    cin>>n;
    int *b = new int [n];
    cout<<sizeof(b);  // will print the size of pointer only(which is in static memory)
    // we can do all the similar stuff on the dynamically created array
    // like taking input, updating array
    // now deallocating the memory
    // overwritting b array is possible using : b = new char [50];
    delete [] b;
    return 0;
}
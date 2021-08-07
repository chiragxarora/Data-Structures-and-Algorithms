#include <iostream>
#include <algorithm>

using namespace std;

// Generic programming: same code can work with different data types
// it is done by using templates

// template < typename T> or template<class T>

template<typename T>

int search(T arr[], int n, T key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8};
    int na = sizeof(a)/sizeof(int);
    int keyA = 5;
    cout<<search(a,na,keyA)<<endl;  // can be used with integer arrays
    char b[] = {'a','b','c','d'};
    int nb = sizeof(a)/sizeof(int);
    char keyB = 'b';
    cout<<search(b,nb,keyB);  // can be used with character arrays too (and all the possible datatypes)
    return 0;
}
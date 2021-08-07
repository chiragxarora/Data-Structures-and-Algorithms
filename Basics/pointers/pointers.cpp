#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    // address of operator : &
    int a = 10;
    //cout<<&a;
    float b = 10.0;
    //cout<<endl<<&b;
    // '&' does not work for character variables
    char ch = 'a';
    //cout<<endl<<&ch;  // will return value of ch instead; happens because of operator overloading of '<<'
    //cout<<endl<<(void *)&ch;  // typecasting like this can let us see the address of character variable

    // pointer : *
    // it is a variable that stores address of another variable
    // declaration
    int m = 100;
    int *ptr1 = &m;
    //cout<<*ptr1<<endl;  // prints the value of variable whose address is stored in ptr1
    int c = 5;
    int *ptr2;
    ptr2 = &c;
    //cout<<ptr2<<endl;  // prints the address stored in ptr2
    // pointer variable will have a garbage value if not initialized
    // we should NOT store address of a different data type variable in a different data type pointer

    // size of a pointer variable

    // all pointer variables store address, be it of an int or char or float but its an address
    // all addresses are of same sizes
    // a pointer will be of size 4 bytes or 8 bytes depending upon the system

    // Re-assign another address to the pointer variable

    ptr2 = &m;
    //cout<<*ptr2<<endl; 

    // Dereference operator : *

    // by this we can dereference the address and access the variable whose address was stored
    // & bucket => address
    // * address => bucket

    int x1 = 40;
    int *x1ptr;
    x1ptr = &x1;
    cout<<x1ptr<<endl;  // address of x1
    cout<<*x1ptr<<endl;  // value of x1 : *x1ptr == x1
    cout<<*(x1ptr+1)<<endl; // value at next address (unknown value)
    cout<<*x1ptr + 1<<endl;  // x1 + 1 = 41
    cout<<&(*x1ptr)<<endl;  // equivalent to &(x1)
    cout<<*(&x1ptr)<<endl;  // again address of x1

    // double pointers
    // for creating pointer to a pointer variable, ** will be there
    int ** xx1ptr = &(x1ptr);
    cout<<xx1ptr<<endl;
    cout<<*xx1ptr<<endl;
    return 0;
}
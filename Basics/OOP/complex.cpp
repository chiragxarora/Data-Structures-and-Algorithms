#include <iostream>

using namespace std;

class Complex {
private: 
    int real;
    int img;

public:
    void print() {
        cout<<real<<" + "<<img<<"i\n";
    }
    Complex() : real(1), img(1) {  // contructor with initializor list!!
        
    }
    Complex(int r, int i) : real(r), img(i) {
        real = r;
        img = i;
    }
};

int main() {
    Complex a;
    a.print();
    Complex *b = new Complex(4,5);
    b->print();
    return 0;
}
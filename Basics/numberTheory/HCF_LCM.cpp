#include <iostream>
#include <algorithm>

using namespace std;

// HCF : highest common factor!
// GCD : greatest common divisor!
// LCM : lowest common multiple!
// hcf and gcd are one and the same,  gcd(a,b) : it is the greatest number which divides both a and ab

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

int main() {

    // Euclid's Algorithm:
    // gcd(a,b) = gcd(b,a%b);
    // gcd(a,0) = 0;
    // ** gcd(a,b) * lcm(a,b) = a*b;
    int a = 12, b = 144;
    cout<<"GCD is : "<<gcd(a,b)<<endl<<"LCM is : "<<(a*b)/gcd(a,b);
    return 0;
}
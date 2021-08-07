#include <iostream>
#include <algorithm>

using namespace std;

// generating prime numbers using sieve of eratosthenes
// by sieve we generate a array of prime numbers
// in prime_sieve array, if value is 1 => that index number is prime

void prime_sieve(int *p) {
    // first mark all the odd numbers as prime:
    for(long long int i=3;i<1000000; i+=2){
        p[i] = 1;
    }
    for(long long int i=3;i<1000000; i+=2){
        if(p[i] == 1) {
            for(long long int j = i*i; j<1000000; j+=i){
                p[j] = 0;
            }
        }
    }
}

int main() {
    int p[1000000] = {0};
    prime_sieve(p);
    for(long long int i =10000; i<1000000; i++){
        if(p[i] == 1) {
            cout<<i<<" ";
        }
    }
    return 0;
}
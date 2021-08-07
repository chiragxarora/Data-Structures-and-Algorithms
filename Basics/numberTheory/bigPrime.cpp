#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

// generating prime numbers using sieve of eratosthenes
// by sieve we generate a array of prime numbers
// in prime_sieve array, if value is 1 => that index number is prime

void prime_sieve() {
    b.set();
    b[0] = 0;
    b[1] = 1;
    
    for(long long int i=2;i<10000005; i++){
        if(b[i] == 1) {
            primes.push_back(i);
            for(long long int j = i*i; j<10000005; j+=i){
                b[j] = 0;
            }
        }
    }
}

bool isPrime(long long int no){
    if(no < n){
        return b[no]==1?true:false;
    }
    for(long long int i = 0; primes[i]*(long long int)primes[i] < no; i++){
        if(no%primes[i]==0){
            return false;
        }
    }
    return true;
}

int main() {
    prime_sieve();
    cout<<isPrime(2147483647);
    return 0;
}
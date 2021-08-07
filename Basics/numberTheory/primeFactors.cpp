#include <iostream>
#include <vector>

using namespace std;

// Prime factors of a number using sieve

const int N = 100000;
int p[N] = {0};
vector<int> primes;

void prime_sieve() {
    for(int i=2;i<N; i++){
        if(p[i] == 0) {
            primes.push_back(i);
            for(int j = i; j<N; j+=i){
                p[j] = 1;
            }
        }
    }
}

void factorize(int num) {
    int n = num;
    vector<int> factors;
    factors.clear();
    int i=0;
    while(primes[i]*primes[i] < num){
        if(n%primes[i]==0){
            factors.push_back(primes[i]);
            while(n%primes[i]==0){
                n = n/primes[i];
            }
        }
        i++;
    }
    if(n!=1){
        factors.push_back(n);
    }
    for(int i=0;i<factors.size();i++){
        cout<<factors[i]<<" ";
    }
    cout<<endl;
}

int main() {
    prime_sieve();
    int n = 1374;
    factorize(n);
    return 0;
}
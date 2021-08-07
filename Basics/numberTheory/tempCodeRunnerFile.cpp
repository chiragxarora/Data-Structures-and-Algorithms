#include <iostream>
#include <vector>
#include <bitset>


using namespace std;

#define range 100000

bitset<100000> b;
vector<int> primes;


// Segmented Sieve : "PRIME GENERATOR" : SPOJ problem

void prime_sieve() {
    b.set();
    b[0] = 0;
    b[1] = 1;
    
    for(long long int i=2;i<100000; i++){
        if(b[i] == 1) {
            primes.push_back(i);
            for(long long int j = i*i; j<100000; j+=i){
                b[j] = 0;
            }
        }
    }
}

bool isPrime(int no){
    if(no < range){
        return b[no]==1?true:false;
    }
    for(long long int i = 0; primes[i]*(long long int)primes[i] < no; i++){
        if(no%primes[i]==0){
            return false;
        }
    }
    return true;
}

void generate_primes(int a, int b){
   for(int i=a;i<=b;i++){
       if(isPrime(i)){
           cout<<i<<endl;
       }
   }
   cout<<endl;
}

int main() {
    prime_sieve();
    int t;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        generate_primes(m,n);
    }
    return 0;
}
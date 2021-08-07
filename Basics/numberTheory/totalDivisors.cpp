#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Find total number of divisors of a given number

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

int numberOfDivisors(int n) {
    
    int i=0, ans = 1;
    while(primes[i]*primes[i] < n){
        if(n%primes[i]==0){
            int cnt = 0;
            while(n%primes[i]==0){
                n = n/primes[i];
                cnt++;
            }
            ans = ans*(cnt+1);
        }
        i++;
    }
    if(n!=1){
        ans *= 2;
    }
    return ans;
}

int main() {
    prime_sieve();
    int n = 60;
    cout<<numberOfDivisors(n);
    string s = "abc";
    char ch = 'a';
    s += ch;
    cout<<s<<endl;
    return 0;
}
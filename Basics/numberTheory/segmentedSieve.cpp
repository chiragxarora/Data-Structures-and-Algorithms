#include <iostream>
#include <vector>

using namespace std;

const int N = 100000;
int p[N] = {0};
vector<int> primes;


// Segmented Sieve : "PRIME GENERATOR" : SPOJ problem

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

int main() {
    prime_sieve();
    int t;
    cin>>t;
    while(t--) {
        int m,n;
        cin>>m>>n;
        bool segment[N];
        for(int i=0;i<n-m+1;i++){
            segment[i] = 0;
        }
        for(auto p : primes) {
            if(p*p > n){
                break;
            }
            int start = (m/p) * p;
            if(p >= m && p <= n){
                start = 2*p;
            }
            for(int i=start; i<=n; i+=p){
                segment[i-m] = 1;
            }
        }
        for(int i = m;i<=n;i++){
            if(segment[i-m]==0 && i!=1){
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <climits>

using namespace std;

// On hackerblocks : https://hack.codingblocks.com/app/practice/1/137/problem

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

vector<pair<int, int>> factorize(int num, vector<pair<int, int>> factors) {
    int n = num;
    factors.clear();
    int i=0;
    while(primes[i]*primes[i] < num){
        if(n%primes[i]==0){
            int cnt = 0;
            while(n%primes[i]==0){
                n = n/primes[i];
                cnt++;
            }
            factors.push_back(make_pair(primes[i],cnt));
        }
        i++;
    }
    if(n!=1){
        factors.push_back(make_pair(n,1));
    }
    return factors;
}

int exponentInFactorial(int num, int primeFactor){
    int val = num/primeFactor;
    int ans = val;
    while(val!=0){
        val = val/primeFactor;
        ans += val;
    }
    return ans;
}

int main() {
    prime_sieve();
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int, int>> factorsOfK;
        factorsOfK = factorize(k,factorsOfK);
        int min = INT_MAX;
        for(int i=0;i<factorsOfK.size();i++){
            int powerOfFactorInNFact = exponentInFactorial(n,factorsOfK[i].first);
            int val = powerOfFactorInNFact/factorsOfK[i].second;
            if(val < min){
                min = val;
            }
        }
        cout<<min<<endl;
    }
    return 0;
}